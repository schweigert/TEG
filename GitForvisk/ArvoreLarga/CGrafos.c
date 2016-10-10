// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include <stdlib.h>
#include <stdio.h>
#include "CGrafos.h"


/*	Função usadad para criar um grafo
*	ao criar um grafo, cria uma matriz (n_vertices) x (n_vertices) e preenche a matriz com zeros
*	retorna a struct do grafo criado
*/
Grafo* criarGrafo (int n_vertices){
	Grafo* ret = (Grafo*)malloc(sizeof(Grafo));

	ret->vertices = n_vertices;
	ret->isDir = 0;
	int i,j;
	ret->matriz_adj = (int**)malloc(sizeof(int*)*n_vertices);
	for (i = 0; i< ret->vertices; i++){
		ret->matriz_adj[i] = (int*)malloc(sizeof(int)*n_vertices);
		for (j = 0; j < n_vertices; j++)
			ret->matriz_adj[i][j] = 0;
	}
	ret->arestas = 0;
	return ret;
}

/*	Função para adicionar arestas não direcionadas
*	adiciona uma aresta ligando (a) e (b) em um  grafo simples
*	caso (a = b), tudo ocorre nrmal graças ao "if"
*/
void addAresta(Grafo* grafo, int a, int b){
	grafo->arestas ++;
	if(a != b)
		grafo->matriz_adj[a][b] += 1;
	grafo->matriz_adj[b][a] += 1;
}

/*	Função para criar arestas direcionadas
*	adiciona um aresta ligando de (a) para (b) e 
*	transforma o grafo em grafo direcionado
*/
void addArestaDirecionado(Grafo* grafo, int a, int b){
	grafo->isDir = 1;
	grafo->arestas ++;
	grafo->matriz_adj[a][b] += 1;
}

/*	Função para criar um vertice em um grafo não direcionado
*	essa função cria um novo grafo que terá todas as arestas e vertices do
*	grafo existente e mais um vertice que não terar nenhuma aresta ligando a ele
*	essa função retorna o novo grafo
*/
Grafo* addVertice(Grafo* grafo, int quant){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices + quant - 1);
	new->isDir = grafo->isDir;
	if(grafo->vertices > 0)
		for(i = 0; i < grafo->vertices; i++)
			for(j = i; j < grafo->vertices; j++)
				if(grafo->matriz_adj[i][j] > 0){
					if(i == j)
						for(c = 0; c < grafo->matriz_adj[i][j] / 2; c++){
							printf("aresta %i %i\n", i, j);
							addAresta(new, i, j);
						}
					else
						for(c = 0; c < grafo->matriz_adj[i][j]; c++){
							printf("aresta %i %i\n", i, j);
							addAresta(new, i, j);
						}
				}
	return new;
}

/*	Função para criar um vertice em um grafo direcionado
*	essa função cria um novo grafo que terá todas as arestas e vertices do
*	grafo existente e mais um vertice que não terar nenhuma aresta ligando a ele
*	essa função retorna o novo grafo
*/
Grafo* addVerticeDirecional(Grafo* grafo, int quant){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices + quant - 1);
	new->isDir = grafo->isDir;
	if(grafo->arestas > 0){
		for(i = 0; i < grafo->vertices; i++)
			for(j = 0; j < grafo->vertices; j++)
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
	return new;
}

/*	Função de remover vertice em um grafo não direcional
*	essa função cria um novo grafo com as mesmas prorpiedades do grafo existente, com
*	exeção do vertice que é removido
*	a função retorna o novo grafo
*/
Grafo* RemoveVertice(Grafo* grafo, int a){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices - 1);
	a--;
	new->isDir = grafo->isDir;
	for(i = 0; i < grafo->vertices; i++)
		for(j = i; j < grafo->vertices; j++)
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
	return new;
}

/*	Função de remover vertice em um grafo direcional
*	essa função cria um novo grafo com as mesmas prorpiedades do grafo existente, com
*	exeção do vertice que é removido
*	a função retorna o novo grafo
*/
Grafo* RemoveVerticeDirecional(Grafo* grafo, int a){
	int i, j, c;
	Grafo* new = criarGrafo(grafo->vertices - 1);
	a--;
	new->isDir = grafo->isDir;
	for(i = 0; i < grafo->vertices; i++)
		for(j = 0; j < grafo->vertices; j++)
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
	return new;
}

/*	Função imprime grafo adjacente
*	essa função lê o grafo e imprime na tela na forma de grafo de adjacencia
*/
void putsGrafo (Grafo* grafo){
	printf("\nGrafo %p:\n\tVertices: %d\n\tArestas: %d\n", (void*)grafo,grafo->vertices,grafo->arestas);
	if(grafo->isDir)
		printf("\tGrafo direcionado\n");
	else
		printf("\tGrafo não direcionado\n");
	for(int i = 0; i < grafo->vertices; i++){
		for(int j = 0; j < grafo->vertices; j++)
			printf ("%d ", grafo->matriz_adj[i][j]);
		printf("\n");
	}
}


/*	Função usada para ler arquivo
*	essa função pedira o nome do arquivo e ira ler as caracteristicas do grafo e criara um grafo com tais caracteristicas
*	então ira continua lendo o arquivo e adcionara os vertices chamando as funções.
*	essa função retorna o frago lido
*/
Grafo* leituraArquivo(){
	Grafo* grafo;
	char arquivo[50], nonAresta, direcao;
	FILE *fp;
	int i, a = 0, b = 0;
	int nVert = 0, nArest = 0;
	printf("Nome do arquivo contendo o grafo: ");
	scanf("%s", arquivo);
	fp = fopen( arquivo, "r");
	//fp = fopen( NDIRCON, "r");
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
	if(direcao == 'd')
		grafo->isDir = 1;
	else if(direcao == 'n')
		grafo->isDir = 0;
	else{
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

Grafo* leituraTeclado(){
	int n_vertices, n_arestas;
	int v1, v2;//, custo;
	int direcionado = -1;
	int i;
	Grafo* grafo;

	printf( "Inicindo inserção de dados!\n");
	while( direcionado == -1){
		char esc = 'a';
		printf( "O grafo é direcionado [Y/n]:");
		scanf( "%c", &esc);
		if( esc == 'Y'){
			direcionado = 1;
			printf(" Criando grafo direcionado!");
		}else if( esc == 'n'){
			direcionado = 0;
			printf( " Criando grafo não direcionado");
		}else
			printf( " Escolha invalida! %c", esc);
	}
	printf( "\nNumero de vertices: ");
	scanf( "%i", &n_vertices);
	printf( "\nNumero de arestas: ");
	scanf( "%i", &n_arestas);
	grafo = criarGrafo( n_vertices);
	putsGrafo(grafo);
	printf("Modelo de entrada de vertice:\nV1 V2\n");
	if(direcionado){
		grafo->isDir = 1;
		for( i = 0; i < n_arestas; i++){
			int ok = 0;
			while( !ok){
				scanf( "%i%i", &v1, &v2);
				if( ( v1 <= n_vertices) && ( v2 <= n_vertices) && ( v1 > 0) && ( v2 > 0)){
					addArestaDirecionado( grafo, --v1, --v2);
					printf("Aresta inserida: %i %i\n", v1+1, v2+1);
					ok = 1;
				}else{
					printf("Aresta invalido!\n");
					ok = 0;
				}
			}
		}
	}
	else if(!direcionado){
		grafo->isDir = 0;
		for ( i = 0; i < n_arestas; ++i){
			int ok = 0;
			while( !ok){
				scanf( "%i%i", &v1, &v2);
				if( ( v1 <= n_vertices) && ( v2 <= n_vertices) && ( v1 > 0) && ( v2 > 0)){
					addAresta( grafo, --v1, --v2);
					printf("Aresta inserida: %i %i\n", v1+1, v2+1);
					ok = 1;
				}else{
					printf("Aresta invalido!\n");
					ok = 0;
				}
			}
		}
	}
	else{
		printf("Erro\n");
		return NULL;
	}
	return grafo;
}

/*
*
*/
Grafo* complemento(Grafo* grafo){
	Grafo* ret = criarGrafo(grafo->vertices);
	int i, j;
	if(grafo->isDir){
		for(i = 0; i < grafo->vertices; i++)
			for(j = 0; j<grafo->vertices; j++)
				if(grafo->matriz_adj[i][j] == 0)
					addArestaDirecionado(ret,i,j);
	}else{ 
		for(i = 0; i < grafo->vertices; i++)
			for(j = i; j < grafo->vertices; j++)
				if(grafo->matriz_adj[i][j] == 0)
					addAresta(ret,i,j);
	}
	return ret;
}

