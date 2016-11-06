#include <stdio.h>
#include <stdlib.h>

int encontraMenorMarcado(int** r, int v){
	int i;
	int resp = -1, custo = -1;
	for(i = 0; i < v; i++){
		if(r[i][2] != 1) continue;
		printf("%d está acessível\n", i);
		if(r[i][1] < custo || custo == -1){
			printf("%d tem o atual menor valor\n",i);
			resp = i;
			custo = r[i][1];
		}
	}
	printf("Menor custo com %d: %d\n", resp, custo);
	return resp;
}

int** dijkstra(int** grafo, int v, int s){
	printf("Iniciando dijkstra...\n");
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
	printf("Inicializando startup\n");
	r[s][0] = s; // Dele mesmo
	r[s][1] = 0; // Custo zero
	r[s][2] = 2; // Relaxado

	// Marcar todos apartir da saída
	for(i = 0; i < v; i++){
		if (grafo[s][i] == 0) continue;
		if (r[i][2] == 2) continue;
		printf("Marcando %d\n", i);
		r[i][0] = s;
		r[i][1] = grafo[s][i];
		r[i][2] = 1;
	}

	while(1){
		printf("\n\nTabela Dijkstra Parcial:\n");
		for(i = 0; i < v; i++){
			printf("%d:\t", i);
			for(j = 0; j < 3; j++){
				printf("%d\t", r[i][j]);
			}
			printf("\n");
		}
		int vertice =	encontraMenorMarcado(r, v);

		if(vertice == -1){
			printf("Nenhum outro vértice é alcancavel\n");
			return r;
		}

		printf("\nMenor vértice é %d\n", vertice);

		r[vertice][2] = 2;
		for(i = 0; i < v; i++){
			if(grafo[vertice][i] == 0 || r[i][2] == 2){
				continue;
			}

			printf("\n Vértice %d é encontrado por %d\n", i, vertice);

			if(r[i][1] >= r[vertice][1]+grafo[vertice][i] || r[i][2] == 0){
				r[i][0] = vertice;
				r[i][1] = r[vertice][1]+grafo[vertice][i];
				r[i][2] = 1;
			}



			r[vertice][2] = 2;

		}
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

	printf("\tDijkstra:\n\n");

	int** respDijkstra = dijkstra(grafo, v, v1);

	printf ("Fim Dijkstra:\n");
	for(i = 0; i < v; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", respDijkstra[i][j]);
		}
		printf("\n");
	}

	return 0;
}
