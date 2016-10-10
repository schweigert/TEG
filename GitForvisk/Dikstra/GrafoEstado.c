// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr


#include "Grafo.h"

int seConectado(Grafo* grafo){
	int i, j;
	int n_vertices = grafo->n_vertices;
	int vert_visitado[ n_vertices][2];
	int linha = 0, leave = 1;
	for( i = 0; i < n_vertices; i++){
		vert_visitado[ i][ 0] = 0;
		vert_visitado[ i][ 1] = 0;
	}

	vert_visitado[ linha][0] = 1;
	vert_visitado[ linha][1] = 1;
	j = 0;
	i = linha;
	do{
		leave = 1;
		for( i = 0; i < n_vertices; i++){
			for( j = i + 1; j < n_vertices; j++){
				if(( grafo->vertices[ i][ j] > 0) || ( grafo->vertices[ j][ i] > 0)){
					if((vert_visitado[ i][ 0] == 1) && (vert_visitado[ j][ 0] == 0)){
						vert_visitado[ j][ 0] = 1;
						leave = 0;
					}else if((vert_visitado[ i][ 0] == 0) && (vert_visitado[ j][ 0] == 1)){
						vert_visitado[ i][ 0] = 1;
						leave = 0;
					}
				}
			}
		}
	}while( !leave);

	for( i = 0; i < n_vertices; i++){
		if(vert_visitado[ i][ 0] != 1){
			printf("Grafo não conectado!\n");
			return 0;
		}
	}

	printf("Grafo conexo!\n");
	return 1;
}


int seDirecionado(Grafo* grafo){
	int i, j;
	int loop = 0;
	for( i = 0; i < grafo->n_vertices; i++){
		for( j = i; j < grafo->n_vertices; j++){
			if((grafo->vertices[ i][ j] != grafo->vertices[ j][ i]) || 
				(grafo->custo[ i][ j] != grafo->custo[ j][ i])){
				printf( "Grafo direcionado!\n");
				return 1;
			}
		}
		if(grafo->vertices[ i][ i] != 0)
			loop = 1;
	}
	if(!loop)
		printf( "Grafo simples!\n");
	else
		printf( "Grafo não direcionado!\n");
	return 0;
}