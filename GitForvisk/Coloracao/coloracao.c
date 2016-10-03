#include <stdio.h>
#include <stdlib.h>

int* colorir(int **Grafo, int v){

	int *ret = malloc(sizeof(int)*v);
	int i,j,k;

	for(i = 0; i < v; i++){
		ret[i] = -1;
	}

	// Percorrer todos os vértices
	for (i = 0; i < v; i++){
		ret[i] = 0;
		while(1){
			// Verificar se pode combinar com tal coloração
			int flag = 1;
			for(j = 0; j < v; j++){
				if(ret[j] == -1) continue;
				if(Grafo[i][j] == 0) continue;
				if(ret[j] == ret[i]){
					flag = 0;
					break;
				}
			}
			if(flag){
				break;
			} else {
				ret[i]++;
				continue;
			}

		}
	}

	return ret;

}

int main (void){

	int **Grafo;

	int arestas, vertices;

	printf("Vértices:");
	scanf("%d", &vertices);
	printf("Arestas:");
	scanf("%d", &arestas);
	
	int i, j;

	Grafo = malloc(sizeof(int*)*vertices);
	for (i = 0; i < vertices; i++){
		Grafo[i] = malloc(sizeof(int)*vertices);
		for (j = 0; j < vertices; j++){
			Grafo[i][j] = 0;
			printf("%d ",Grafo[i][j]); 
		}
		printf("\n");
	}

	int a, b;

	for(i = 0; i < arestas; i++){
		printf("Aresta %d:", i);
		scanf("%d", &a);
		scanf("%d", &b);
		Grafo[a][b] = 1;
		Grafo[b][a] = 1;
	}

	int* coloracao = colorir(Grafo, vertices);
	
	for(i = 0; i < vertices; i++){
		printf("%d ", coloracao[i]);
	}

	return 0;
}
