// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include <stdio.h>
#include <stdlib.h>
#include "CGrafoVetorAdj.h"

/*	Função usadad para criar um grafo
*	ao criar um grafo, cria uma matriz (n_vertices) x (n_vertices) e preenche a matriz com zeros
*	retorna a struct do grafo criado
*/
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

/*	Função para adicionar arestas não direcionadas
*	adiciona uma aresta ligando (a) e (b) em um  grafo simples
*	caso (a = b), tudo ocorre nrmal graças ao "if"
*/
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

/*	Função cria aresta
*	esta função cria uma struct Aresta para ser utilizada no grafo
*/
Arestas* criaAresta(int a){
	Arestas* new = (Arestas*)malloc(sizeof(Arestas));
	new->vertice = a;
	new->next = NULL;
	//printf("%i\n", new->vertice);

	return new;
}

/*	Função usada para ler arquivo
*	essa função pedira o nome do arquivo e ira ler as caracteristicas do grafo e criara um grafo com tais caracteristicas
*	então ira continua lendo o arquivo e adcionara os vertices chamando as funções.
*	essa função retorna o frago lido
*/
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

/*	Função imprime grafo adjacente
*	essa função lê o grafo e imprime na tela na forma de grafo de adjacencia
*/
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