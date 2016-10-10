// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr


#include "Grafo.h"

Grafo* leituraTecladoGrafo(){
	int n_vertices, n_arestas;
	int v1, v2, custo;
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
	grafo = criaGrafo( n_vertices);
	putsGrafo(grafo);
	printf("Modelo de entrada de vertice:\nV1 V2 Custo\n");
	if(direcionado){
		for( i = 0; i < n_arestas; i++){
			int ok = 0;
			while( !ok){
				scanf( "%i%i%i", &v1, &v2, &custo);
				if( ( v1 <= n_vertices) && ( v2 <= n_vertices) && ( v1 > 0) && ( v2 > 0)){
					addAresta( --v1, --v2, custo, grafo);
					grafo->n_arestas++;
					printf("Aresta inserida: %i %i %i\n", v1+1, v2+1, custo);
					ok = 1;
				}else{
					printf("Aresta invalido!\n");
					ok = 0;
				}
			}
		}
	}
	else if(!direcionado){
		for ( i = 0; i < n_arestas; ++i){
			int ok = 0;
			while( !ok){
				scanf( "%i%i%i", &v1, &v2, &custo);
				if( ( v1 <= n_vertices) && ( v2 <= n_vertices) && ( v1 > 0) && ( v2 > 0)){
					addAresta( --v1, --v2, custo, grafo);
					addAresta( v2, v1, custo, grafo);
					grafo->n_arestas++;
					printf("Aresta inserida: %i %i %i\n", v1+1, v2+1, custo);
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

Grafo* leituraGrafoDirecionado(){
	char arquivo[ 50];
	char nameAresta;
	int n_vertices, n_arestas;
	int origem, destino, custo;

	int i;

	Grafo* grafo;

	FILE *fp;
	printf( "Nome do arquivo:\n");
	scanf( "%s", arquivo);
	fp = fopen( arquivo, "r");
	if( fp == NULL){
		printf( "Arquivo não existente!\n");
		return NULL;
	}

	fscanf( fp, "%i%i", &n_vertices, &n_arestas);
	grafo = criaGrafo( n_vertices);
	for( i = 0; i < n_arestas; i++){
		fscanf( fp, "%c: %i, %i = %i", &nameAresta, &origem, &destino, &custo);
		addAresta( origem, destino, custo, grafo);
		addAresta( destino, origem, custo, grafo);
		grafo->n_arestas--;
	}
	return grafo;
}

Grafo* leituraGrafo(){
	char arquivo[ 50];
	char nameAresta;
	int n_vertices, n_arestas;
	int origem, destino, custo;

	int i;

	Grafo* grafo;

	FILE *fp;
	printf( "Nome do arquivo:\n");
	scanf( "%s", arquivo);
	fp = fopen( arquivo, "r");
	if( fp == NULL){
		printf( "Arquivo não existente!\n");
		return NULL;
	}
	printf( "Arquivo encontrado\n");
	fscanf( fp, "%i %i\n", &n_vertices, &n_arestas);
	printf( "Vertices: %i;\nArestas: %i.\n", n_vertices, n_arestas);
	grafo = criaGrafo( n_vertices);
	for( i = 0; i < n_arestas; i++){
		fscanf( fp, "%c: %i, %i = %i;\n", &nameAresta, &origem, &destino, &custo);
		printf( "%c %i, %i = %i;\n", nameAresta, origem, destino, custo);
		addAresta( origem-1, destino-1, custo, grafo);
	}
	return grafo;
}

void putsGrafo( Grafo* grafo){
	int i, j;
	printf( "Grafo: %p;\n\nVertices: %i;\n", ( void*)grafo, grafo->n_vertices);
	printf( "    ");
	for( j = 0; j < grafo->n_vertices; j++)
		printf( " %3i ", j+1);
	printf( "\n\n");
	for( i = 0; i < grafo->n_vertices; i++){
		printf( "%2i  ", i+1);
		for ( j = 0; j < grafo->n_vertices; j++){
			printf( " %3i ", grafo->vertices[i][j]);
		}
		printf("\n    ");
		for( j = 0; j < grafo->n_vertices; j++){
			printf( " %3i ", grafo->custo[i][j]);
		}
		printf( "\n\n");
	}
}

int escolheVertice( Grafo* grafo){
	int vertice;
	printf( "Selecione o vertice desejado: ");
	scanf( "%i", &vertice);
	if( --vertice < grafo->n_vertices)
		return ( vertice);
	else{
		printf( "Vertice não existente!\n");
		return -1;
	}
}