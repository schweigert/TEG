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
	if(a != b)
		grafo->matriz_adj[a][b] += 1;
	grafo->matriz_adj[b][a] += 1;
}

void addArestaDirecionado(Grafo* grafo, int a, int b){
	grafo->isDir = 1;
	grafo->arestas ++;
	grafo->matriz_adj[a][b] += 1;
}

Grafo* addVerticeDirecional(Grafo* grafo, int quant){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices + quant - 1);

	new->isDir = grafo->isDir;
	if(grafo->arestas > 0){
		for(i = 0; i < grafo->vertices; i++){
			for(j = 0; j < grafo->vertices; j++){
				if(grafo->matriz_adj[i][j] > 0){
					if(i == j){
						for(c = 0; c < grafo->matriz_adj[i][j] / 2; c++){
							printf("aresta %i %i\n", i, j);
							addArestaDirecionado(new, i, j);
						}
					}else{
						for(c = 0; c < grafo->matriz_adj[i][j]; c++){
							printf("aresta %i %i\n", i, j);
							addArestaDirecionado(new, i, j);
						}
					}
				}
			}
		}
	}
	return new;
}

Grafo* addVertice(Grafo* grafo, int quant){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices + quant - 1);

	new->isDir = grafo->isDir;

	if(grafo->vertices > 0){
		for(i = 0; i < grafo->vertices; i++){
			for(j = i; j < grafo->vertices; j++){
				if(grafo->matriz_adj[i][j] > 0){
					if(i == j){
						for(c = 0; c < grafo->matriz_adj[i][j] / 2; c++){
							printf("aresta %i %i\n", i, j);
							addAresta(new, i, j);
						}
					}else{
						for(c = 0; c < grafo->matriz_adj[i][j]; c++){
							printf("aresta %i %i\n", i, j);
							addAresta(new, i, j);
						}
					}
				}
			}
		}
	}
	return new;
}


Grafo* RemoveVerticeDirecional(Grafo* grafo, int a){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices - 1);

	a--;
	new->isDir = grafo->isDir;

	for(i = 0; i < grafo->vertices; i++){
		for(j = 0; j < grafo->vertices; j++){
			if(grafo->matriz_adj[i][j] > 0){
				if((i < a) && (j < a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addArestaDirecionado(new, i, j);
				}else if((i < a) && (j > a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addArestaDirecionado(new, i, j-1);
				}else if((i > a) && (j < a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addArestaDirecionado(new, i-1, j);
				}else if((i > a) &&(j > a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addArestaDirecionado(new, i-1, j-1);
				}
			}
		}

	}
	return new;
}

Grafo* RemoveVertice(Grafo* grafo, int a){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices - 1);

	a--;
	new->isDir = grafo->isDir;

	for(i = 0; i < grafo->vertices; i++){
		for(j = i; j < grafo->vertices; j++){
			if(grafo->matriz_adj[i][j] > 0){
				if((i < a) && (j < a)){
					if(i == j){
						for(c = 0; c < grafo->matriz_adj[i][j] / 2; c++)
							addAresta(new, i, j);	
					}else{
						for(c = 0; c < grafo->matriz_adj[i][j]; c++)
							addAresta(new, i, j);
					}
				}else if((i < a) && (j > a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addAresta(new, i, j-1);
				}else if((i > a) && (j < a)){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++)
						addAresta(new, i-1, j);
				}else if((i > a) &&(j > a)){
					if(i == j){
						for(c = 0; c < grafo->matriz_adj[i][j] / 2; c++)
							addAresta(new, i-1, j-1);
					}else{
						for(c = 0; c < grafo->matriz_adj[i][j]; c++)
							addAresta(new, i-1, j-1);
					}
				}
			}
		}
	}
	return new;
}

void putsGrafo (Grafo* grafo){
	printf("\nGrafo %p:\n\tVertices: %d\n\tArestas: %d\n", (void*)grafo,grafo->vertices,grafo->arestas);
	//printf("\tDirecionado: %d\n", grafo->isDir);

	if(grafo->isDir)
		printf("\tGrafo direcionado\n");
	else
		printf("\tGrafo não direcionado\n");
	
	int i,j;
	
	for(i = 0; i < grafo->vertices; i++){
		for(j = 0; j < grafo->vertices; j++){
			printf ("%d ", grafo->matriz_adj[i][j]);
		}
		printf("\n");
	}
}

void putsGrafoIncidencia(Grafo* grafo){
	int matriz_inc[grafo->arestas][grafo->vertices];
	int i, j, a, c;
	printf("\nGrafo %p:\n\tVertices: %d\n\tArestas: %d\n", (void*)grafo,grafo->vertices,grafo->arestas);
	for(a = 0; a < grafo->arestas; a++)
		for(j = 0; j < grafo->vertices; j++)
			matriz_inc[a][j] = 0;
	a = 0;
	if(grafo->isDir){
		printf("\tGrafo direcionado\n");
		for(i = 0; i < grafo->vertices; i++){
			for(j = 0; j < grafo->vertices; j++){
				if(grafo->matriz_adj[i][j] > 0){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++){
						if(a < grafo->arestas){
							matriz_inc[a][i] = 1;
							matriz_inc[a][j] = -1;
							a++;
						}else{
							printf("Erro\n");
							exit(-1);
						}
					}
				}
			}
		}
	}else{
		printf("\tGrafo não direcionado\n");
		for(i = 0; i < grafo->vertices; i++){
			for(j = i; j < grafo->vertices; j++){
				if(grafo->matriz_adj[i][j] > 0){
					for(c = 0; c < grafo->matriz_adj[i][j]; c++){
						if(a < grafo->arestas){
							matriz_inc[a][i] = 1;
							matriz_inc[a][j] = 1;
							a++;
						}else{
							printf("Erro\n");
							exit(-1);
						}
					}
				}
			}
		}
	}
	for(a = 0; a < grafo->arestas; a++){
		for(j = 0; j < grafo->vertices; j++){
			printf(" %i", matriz_inc[a][j]);
		}
		printf("\n");
	}
}


/*Função usada para ler arquivo, ela pedira o nome do arquivo e ira ler as caracteristicas do grafo e criara um grafo com tais caracteristicas
	então ira continua lendo o arquivo e adcionara os vertices chamando as funções.*/
Grafo* leituraArquivo(){
	Grafo* grafo;
	char arquivo[50], nonAresta, direcao;
	FILE *fp;
	int i, a = 0, b = 0;
	int nVert = 0, nArest = 0;
	/*printf("Nome do arquivo contendo o grafo: ");
	scanf("%s", arquivo);
	fp = fopen( arquivo, "r");*/
	fp = fopen( NDIRCON, "r");
	//fp = fopen( NDIRDESCON, "r");
	//fp = fopen( DIRCON, "r");
	//fp = fopen( DIRDESCON, "r");
	if(fp == NULL){
		printf("\nArquivo não existe\n");
		return NULL;
	}
	//leitura do arquivo para vertica, direcionado e arestas
	fscanf( fp, "%c\n", &direcao);
	fscanf( fp, "%i\n", &nVert);
	printf("Vertices: %i", nVert);
	fscanf( fp, "%i\n", &nArest);
	printf("Arestas: %i\n", nArest);
	grafo = criarGrafo(nVert);
	if(direcao == 'd'){
		grafo->isDir = 1;
	}else if(direcao == 'n'){
		grafo->isDir = 0;
	}else{
		printf("Arquivo não esta no padrão;\n");
		return NULL;
	}
	for(i = 0; (i < nArest) && (feof(fp) == 0); i++) {
		fscanf( fp, "%c: %i, %i;\n", &nonAresta, &a, &b);
		printf("%c: %i, %i\n", nonAresta, a, b);
		if(grafo->isDir == 0)
			addAresta(grafo, --a, --b);
		else
			addArestaDirecionado(grafo, --a, --b);
	}
	putsGrafo(grafo);
	fclose(fp);
	return grafo;
}


Grafo* complemento(Grafo* grafo){
	Grafo* ret = criarGrafo(grafo->vertices);
	int i, j;
	if(grafo->isDir){
		for(i = 0; i < grafo->vertices; i++){
			for(j = 0; j<grafo->vertices; j++){
				if(grafo->matriz_adj[i][j] == 0)
					addArestaDirecionado(ret,i,j);
			}
		}
	} else {
		for(i = 0; i < grafo->vertices; i++){
			for(j = i; j < grafo->vertices; j++){
				if(grafo->matriz_adj[i][j] == 0)
					addAresta(ret,i,j);
			}
		}
	}

	return ret;
}

