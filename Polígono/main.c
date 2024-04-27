#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float X;
    float Y;
} Ponto;

float AreaTriangulo(Ponto A, Ponto B, Ponto C){
    float det = ((A.X * B.Y) + (A.Y * C.X) + (B.X * C.Y)) - ((A.Y * B.X) + (A.X * C.Y) + (B.Y * C.X));
    return fabs(det)/2.0;
}


int main(){
    FILE *entrada;
    int Nvertices;//armazena o número de vértices do polígono.
    float resultado = 0.0;
    Ponto *vertices;

    entrada = fopen("../poligono.txt", "r");

    if(entrada == NULL){
        printf("Arquivo Inexistente");
        exit(1);
    }
    
    fscanf(entrada, "%d", &Nvertices);

    vertices = (Ponto*)malloc(Nvertices * sizeof(Ponto));

    for (int i = 0; i < Nvertices; i++){
        fscanf(entrada, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(entrada);
    
    if(Nvertices == 3){
        resultado = AreaTriangulo(vertices[0], vertices[1], vertices[2]);
    } else {
        for(int i = 2; i < Nvertices; i++){
           resultado += AreaTriangulo(vertices[0], vertices[i-1], vertices[i]);
        }
    }

    printf("A area do poligono é: %.2f", resultado);
    fflush(stdout);

    free(vertices);

    return 0;



}

