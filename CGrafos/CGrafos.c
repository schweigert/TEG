#include <stdlib.h>
#include <stdio.h>
#include "CGrafos.h"

Grafo* criarGrafo (int n_vertices){
	Grafo* ret = (Grafo*)malloc(sizeof(Grafo));
	
	ret->vertices = n_vertices;
	ret->isDir = 0;
	int i,j;
	ret->matriz_adj = (int**)malloc(sizeof(int*)*n_vertices);
	for (i = 0; i< ret->vertices; i++){
		ret->matriz_adj[i] = (int*)malloc(sizeof(int)*n_vertices);
		for (j = 0; j < n_vertices; j++){
			ret->matriz_adj[i][j] = 0;
		}
	}
	
	ret->arestas = 0;
	
	return ret;
}

void addAresta(Grafo* grafo, int a, int b){
	grafo->arestas ++;
	grafo->matriz_adj[a][b] += 1;
	grafo->matriz_adj[b][a] += 1;
}

void addArestaDirecionado(Grafo* grafo, int a, int b){
	grafo->isDir = 1;
	grafo->arestas ++;
	grafo->matriz_adj[a][b] += 1;
}

void addVertice(Grafo* grafo, int quant){
	grafo->vertices += quant;
	int i = 0;
	
	grafo->matriz_adj = realloc(grafo->matriz_adj, sizeof(int*)*grafo->vertices);
	for (i = 0; i < grafo->vertices; i++){
		grafo->matriz_adj[i] = realloc(grafo->matriz_adj[i], sizeof(int)*grafo->vertices);
	}
	
}

void RemoveVertice(Grafo* grafo, int a){
	grafo->vertices;
	int i,j;
	
	free(grafo->matriz_adj[i]);
	
	for (i = a; i < grafo->vertices -1; i++){
		grafo->matriz_adj[i] = grafo->matriz_adj[i+1];
	}
	
	for (i = 0; i < grafo->vertices -1; i++){
		for (j = a; j < grafo->vertices -1; i++){
			grafo->matriz_adj[i][j] = grafo->matriz_adj[i][j+1];
		}
		grafo->matriz_adj[i] = realloc(grafo->matriz_adj[i], sizeof(int)*(grafo->vertices -1));
	}
	
	grafo->vertices --;
	
}


void putsGrafo (Grafo* grafo){
	printf("Grafo %p:\n\tVertices: %d\n\tArestas: %d\n", (void*)grafo,grafo->vertices,grafo->arestas);
	printf("\tDirecionado: %d\n", grafo->isDir);
	
	int i,j;
	
	for(i = 0; i < grafo->vertices; i++){
		for(j = 0; j < grafo->vertices; j++){
			printf ("%d ", grafo->matriz_adj[i][j]);
		}
		printf("\n");
	}
}