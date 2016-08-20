#include <stdio.h>
#include <stdlib.h>



int main(void){

    int** matrizAdj = NULL;
    int** matrizInc = NULL;
    int** matrizFlag = NULL;
    char d; // n: Não Dir; s: Dir;

    int a, v; // Arestas, Vertices;

    scanf ("%c", &d);

    int i = 0; // contador

    // Alocar Matrizes

    // MatrizAdj[v,v]
    matrizAdj = (int**)malloc(sizeof(int*)*v);
    matrizFlag = (int**)malloc(sizeof(int*)*v);
    for (i = 0; i < v; i++){
        matrizAdj[i] = (int*)malloc(sizeof(int)*v);
        matrizFlag = (int*)malloc(sizeof(int)*v);
    }

    // MatrizInc[i,v]
    matrizInc = (int**)malloc(sizeof(int*)*a);
    for (i = 0; i < a; i++){
        matrizInc[i] = (int*)malloc(sizeof(int*)*v);
    }

    // Contador
    i = a;

    char k;
    int dest,origin;
    // K : O,D;

    while(i--){
        // atualizar caminho
        scanf("%c: %d , %d;" &k, &origin,&dest);
        matrizAdj[origin][dest]++;
        if (d == 'n'){
            matrizAdj[dest][origin]++;
        }

        matrizInc[i][origin] = 1;
        if (d == 's'){
            matrizInc[i][dest] = -1;
        } else {
            matrizInc[i][dest] = 1;
        }

    }

    // Matrizes alocadas, tanto para Direcionado
    // quanto para não direcionado

    // Terminar demais verificações <3



    return 0;
}