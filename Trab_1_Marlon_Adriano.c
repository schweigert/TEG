#include <stdio.h>
#include <stdlib.h>

// Created with <3 by:
//     - Marlon Henry Schweigert

int main(void){

	// Matrizes de Adj. e Inc.
	int **MAdj = NULL;
	int **MInc = NULL;

	// Número de Arestas e Vértices
	int arestas, vertices;


	// Auxiliares
	int i = 0, j = 0;
	int V1, V2;

	scanf ("%d %d", &arestas, &vertices);

	// Criando a matriz Adj
	MAdj = (int**) malloc(sizeof(int*)*vertices);
	for (i = 0; i < vertices; i++){
		MAdj[i] = malloc(sizeof(int)*vertices);
	}

    // Zerar
    for (i = 0; i < vertices; i++){
        for (j = 0; j < vertices; j++){
            MAdj[i][j] = 0;
        }
    }



	// Criando a matriz Inc
	MInc = (int**) malloc(sizeof(int*)*arestas);
	for (i = 0; i < vertices; i++){
		MInc[i] = malloc(sizeof(int)*vertices);
	}

    for (i = 0; i < arestas; i++){
        for (j = 0; j < vertices; j++){
            MInc[i][j] = 0;
        }
    }

	i = arestas;

	while (i--){
		scanf ("%d %d", &V1, &V2);
		MAdj[V1-1][V2-1]++;
		MAdj[V2-1][V1-1]++;

		MInc[i][V1]++;
		MInc[i][V2]++;
	}


	// Imprimir Matriz ADJ
	puts ("\n \tMatriz Adj:");
    printf ("\t");
    for (j = 0; j < vertices; j++){
        printf ("v%d\t", j);
    }
    printf ("\n");
	for (i = 0; i < vertices; i++){
        printf ("v%d|\t", i);
		for (j = 0; j < vertices; j++){
			printf ("%d\t", MAdj[i][j]);
		}
		printf ("\n");
	}

    puts ("\n \tMatriz Inc:");
    printf ("\t");
    for (j = 0; j < vertices; j++){
        printf ("v%d\t", j);
    }
    printf ("\n");
	for (i = 0; i < arestas; i++){
        printf ("u%d|\t", i);
		for (j = 0; j < vertices; j++){
			printf ("%d\t", MInc[i][j]);
		}
		printf ("\n");
	}

	return 0;
}
