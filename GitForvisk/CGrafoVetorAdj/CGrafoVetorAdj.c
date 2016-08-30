/*	TEG - Grafo por matriz de adjacencia
*	Adriano Zanella Junior
*	Marlon Henry
*
*	Esse código somente trabalha com grafos não direcionados.
*	Para grafos direcionados precisa implementar funções adicionais.
*/
#include <stdio.h>
#include <stdlib.h>
#include "CGrafoVetorAdj.h"

Vetor* criaGrafo(int nV, int nA){
	int i;
	Vetor* vetor = (Vetor*)malloc(sizeof(Vetor));

	vetor->n_vertices = nV;
	vetor->n_arestas = 0;
	vetor->arestas = NULL;

	vetor->vertices = (int*)malloc(sizeof(int)*nV);

	for(i = 0; i< nV; i++){
		vetor->vertices[i] = 0;
	}

	return vetor;
}

void addAresta(Vetor* vetor, int a, int b){
	int i = 0, pos_a = 0, pos_b = 0;

	Arestas* newAresta1 = criaAresta(b);
	Arestas* newAresta2 = criaAresta(a);

	Arestas* atual = vetor->arestas;
	Arestas* aux;

	if(vetor->arestas == NULL){ // primeira aresta do grafo
		vetor->arestas = newAresta1;
	}else{
		i = 0;
		while(i <= a){
			pos_a += vetor->vertices[i];
			i++;
		}
		atual = vetor->arestas;
		i = 0;
		while(i < pos_a-1){
			atual = atual->next;
			i++;
		}
		if(atual->next != NULL){
			newAresta1->next = atual->next;
		}
		atual->next = newAresta1;
	}
	vetor->vertices[a]++;

	if(a != b){
		i = 0;
		while(i <= b){
			pos_b += vetor->vertices[i];
			i++;
		}
		atual = vetor->arestas;
		i = 0;
		while(i < pos_b-1){
			atual = atual->next;
			i++;
		}
		if(atual->next != NULL){
			newAresta2->next = atual->next;
		}
		atual->next = newAresta2;

		vetor->vertices[b]++;
	}
	vetor->n_arestas++;
}

Arestas* criaAresta(int a){
	Arestas* new = (Arestas*)malloc(sizeof(Arestas));
	new->vertice = a;
	new->next = NULL;
	//printf("%i\n", new->vertice);

	return new;
}

Vetor* leituraArquivo(){
	char arquivo[50], c_aresta, direcao;
	FILE *fp;
	int i, a = 0, b = 0;
	int nV = 0, nA = 0;

	Vetor* vetor;

	printf("Nome do arquivo contendo o grafo: ");
	scanf("%s", arquivo);
	fp = fopen( arquivo, "r");
	//fp = fopen( NDIRCON, "r");
	//fp = fopen( NDIRDESCON, "r");

	if(fp == NULL){
		printf("\nArquivo não existe\n");
		return NULL;
	}
	//leitura do arquivo para vertica, direcionado e arestas
	fscanf( fp, "%i\n", &nV);
	printf("Vertices: %i\n", nV);
	fscanf( fp, "%i\n", &nA);
	printf("Arestas: %i\n", nA);

	vetor = criaGrafo(nV, nA);
	vetor->isDir = 0;

	for(i = 0; (i < nA) && (feof(fp) == 0); i++) {
		fscanf( fp, "%c: %i, %i;\n", &c_aresta, &a, &b);
		printf("%c: %i, %i\n", c_aresta, a, b);
		addAresta(vetor, --a, --b);
	}
	fclose(fp);
	return vetor;
}

void putsGrafo(Vetor* vetor){
	int i, j = 0, t = 0;
	Arestas* atual = vetor->arestas;

	printf("\nGrafo: %p\n\tVertices: %i\n\tArestas: %i\n", (void*)vetor,  vetor->n_vertices, vetor->n_arestas);

	for(i = 0; i < vetor->n_vertices; i++){
		t += vetor->vertices[i];
		while(j < t){
			if(i <= atual->vertice)
				printf("\t%i - %i;\n",i+1, atual->vertice+1);
			atual = atual->next;
			j++;
		}
	}
}