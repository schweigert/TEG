#include <stdio.h>
#include <stdlib.h>

int** dijkstra(int** grafo, int v, int s){
	int i,j;
	int** r = malloc(sizeof(int*)*v);
	for(i = 0; i < v; i++){
		r[i] = malloc(sizeof(int)*3);
		r[i][0] = 0; // De onde
		r[i][1] = 0; // Com tal custo
		r[i][2] = 0; // Estado de relaxação
		
		// Estado de relaxação:
		// 0 = Não alcançado
		// 1 = Alcançado
		// 2 = Relaxado
	}
	
	r[s][0] = s; // Dele mesmo
	r[s][1] = 0; // Custo zero
	r[s][2] = 2; // Relaxado
	
	// Marcar todos apartir da saída
	for(i = 0; i < v; i++){
		if (grafo[s][i] == 0) continue;
		if (r[i][2] == 2) continue;
		r[i][0] = s;
		r[i][1] = grafo[s][i];
		r[i][2] = 1;
	}
	
}

void printGrafo(int** g, int v){
	int i, j;
	for(i = 0; i < v; i++){
		for(j = 0; j < v; j++){
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	
	// Parâmetros do algoritmo
	
	int v, a;		// Vértices, Arestas
	int** grafo;	// Grafo
	
	// Auxiliares
	
	int i,j,v1,v2,p;
	
	// Entrada
	printf("V A\n");
	scanf("%d %d", &v, &a);
	
	// Criando a tabela do grafo
	grafo = (int**)malloc(sizeof(int*)*v);
	for(i = 0; i < v; i++){
		grafo[i] = (int*)malloc(sizeof(int)*v);
		for(j = 0; j < v; j++){
			grafo[i][j] = 0;
		}
	}
	
	printf("\n\tGrafo:\n\n");
	
	printGrafo(grafo, v);
	
	printf("\n\t A P A\n");
	for(i = 0; i < a; i++){
		printf("%d\t",i);
		scanf("%d %d %d", &v1, &p, &v2);
		grafo[v1][v2] = p;
	}
	
	printf("\n\tGrafo:\n\n");
	
	printGrafo(grafo, v);
	
	printf("\nI F\n");
	scanf("%d %d", &v1, &v2);
	
	return 0;
}
