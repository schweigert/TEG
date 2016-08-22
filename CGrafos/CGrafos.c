#include <stdlib.h>
#include "CGrafos.h"

// cc - Marlon Henry Schweigert & Adriano Zanella - 2016

// Cria a estrutura inicial do Grafo (matriz Adjacência) com N Vértices
Grafo* criarGrafo (int n_vertices){
	// Alocar Grafo
	Grafo* ret = (Grafo*)malloc(sizeof(Grafo));
	
	// Criar matriz adj
	int i = 0;
	ret->matriz_adj = (int**)malloc(sizeof(int*)*n_vertices);
	for (i = 0; i < n_vertices; i++){
		ret->matriz_adj[i] = (int*)malloc(sizeof(int)*n_vertices);
	}
	
	
	ret->vertices = n_vertices;
	ret->arestas = 0;
		
	
	return ret;
}

// Adiciona uma Aresta do vértice A ao B, confirmando se derá direcionado ou não
void addAresta (Grafo* grafo, int a, int b, int dir){
	
	grafo->arestas++;
	
	grafo->matriz_adj[a][b] += 1;
	if (!dir){
		grafo->matriz_adj[b][a] += 1;
	}
	
	grafo->matriz_inc =(int **)realloc( grafo->matriz_inc, sizeof(int*)*(grafo->arestas));
	
	if (dir){
		grafo->matriz_inc[grafo->arestas -1] = malloc(sizeof(int)*2);
		grafo->matriz_inc[grafo->arestas -1][0] = a;
		grafo->matriz_inc[grafo->arestas -1][1] = -b;
	} else {
		grafo->matriz_inc[grafo->arestas -1] = malloc(sizeof(int)*2);
		grafo->matriz_inc[grafo->arestas -1][0] = a;
		grafo->matriz_inc[grafo->arestas -1][1] = b;
	}
	
}

// Adiciona uma Aresta do vértice A ao B, confirmando se derá direcionado ou não
void addVertice (Grafo* grafo, int quant){
	
	if (quant <= 0) return;
	grafo->vertices += quant;
	grafo->matriz_adj = (int**)realloc(grafo->matriz_adj, sizeof(int**)*(grafo->vertices));
	
	int i = 0;
	
	for (i = 0; i < grafo->vertices; i++){
		grafo->matriz_adj[i] = (int*)realloc(grafo->matriz_adj, sizeof(int*)*(grafo->vertices));
	}
	
}

void putsGrafo (Grafo* grafo){
	
	
	
}

