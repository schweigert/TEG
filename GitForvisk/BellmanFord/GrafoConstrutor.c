// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr


#include "Grafo.h"

Grafo* criaGrafo( int n_vertices){
	Grafo* novo;
	novo = ( Grafo*)malloc( sizeof( Grafo));
	novo->n_vertices = n_vertices;
	novo->n_arestas = 0;

	novo->vertices = ( int**)malloc( sizeof( int*) * n_vertices);
	novo->custo =  ( int**)malloc( sizeof( int*) * n_vertices);
	int i, j;
	for( i = 0; i < n_vertices; i++){
		novo->vertices[ i] = ( int*)malloc( sizeof( int) * n_vertices);
		novo->custo[ i] = ( int*)malloc( sizeof( int) * n_vertices);
		for( j = 0; j < n_vertices; j++){
			novo->vertices[ i][ j] = 0;
			novo->custo[ i][ j] = 0;
		}
	}

	return novo;
}

void addVertice( Grafo* grafo){
	int i, j;
	int n_vertices = grafo->n_vertices + 1;
	int **vertices;
	int **custo;

	vertices = ( int**)malloc( sizeof( int*) * n_vertices);
	custo =  ( int**)malloc( sizeof( int*) * n_vertices);
	for( i = 0; i < n_vertices; i++){
		vertices[ i] = ( int*)malloc( sizeof( int) * n_vertices);
		custo[ i] = ( int*)malloc( sizeof( int) * n_vertices);
		for( j = 0; j < n_vertices; j++){
			if( ( i != n_vertices - 1) && ( j != n_vertices)){
				vertices[ i][ j] = grafo->vertices[ i][ j];
				custo[ i][ j] = grafo->custo[ i][ j];
			}else{
				vertices[ i][ j] = 0;
				custo[ i][ j] = 0;
			}
		}
	}
	grafo->n_vertices = n_vertices;
	grafo->vertices = vertices;
	grafo->custo = custo;
}

void addAresta( int origem, int destino, int custo, Grafo* grafo){
	grafo->vertices[ origem][ destino]++;
	grafo->custo[ origem][ destino] = custo;
	grafo->n_arestas++;
}

int removeVertice(int vertice, Grafo* grafo){
	vertice--;
	if( vertice >= 0){
		if( vertice < grafo->n_vertices){
			int i, j;
			int tam_novo = grafo->n_vertices - 1;

			int **novo_vertices, **novo_custo;
			novo_vertices = ( int**)malloc( sizeof( int*) * tam_novo);
			novo_custo = ( int**)malloc( sizeof( int*) * tam_novo);

			for( i = 0; i < grafo->n_vertices; i++){

				novo_vertices[ i] = ( int*)malloc( sizeof( int) * tam_novo);
				novo_custo[ i] = ( int*)malloc( sizeof( int) * tam_novo);

				for( j = 0; j < grafo->n_vertices; j++){

					if( ( i != vertice) && ( j != vertice)){

						if( ( i < vertice) && ( j < vertice)){
							novo_vertices[ i][ j] = grafo->vertices[ i][ j];
							novo_custo[ i][ j] = grafo->custo[ i][ j];
						}else if( ( i < vertice) && ( j > vertice)){
							novo_vertices[ i][ j] = grafo->vertices[ i][ j-1];
							novo_custo[ i][ j] = grafo->custo[ i][ j-1];
						}else if( ( i > vertice) && ( j < vertice)){
							novo_vertices[ i][ j] = grafo->vertices[ i-1][ j];
							novo_custo[ i][ j] = grafo->custo[ i-1][ j];
						}else if( ( i > vertice) && ( j > vertice)){
							novo_vertices[ i][ j] = grafo->vertices[ i-1][ j-1];
							novo_custo[ i][ j] = grafo->custo[ i-1][ j-1];
						}
					}
				}
			}
			grafo->vertices = novo_vertices;
			grafo->custo = novo_custo;
			grafo->n_vertices--;
			return 1;
		}
	}
	printf( "Vertice não existente!\n");
	return 0;
}

int removeAresta(int origem, int destino, Grafo* grafo){
	origem--, destino--;
	if( ( origem >= 0) && ( destino >= 0)){
		if( grafo->vertices[ origem][ destino]){
			grafo->vertices[ origem][ destino]--;
			grafo->custo[ origem][ destino] = 0;
			grafo->n_arestas--;
			return 1;
		}
	}
	printf( "Aresta não existente!\n");
	return 0;
}


