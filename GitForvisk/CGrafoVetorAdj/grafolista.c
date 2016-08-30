#include <stdio.h>
#include <stdlib.h>

typedef struct NoV {
	struct NoV *Proximo;
	struct NoA *Primeira;
	int vertice;
} Vertice;

typedef struct NoA {
	struct NoA *Proximo;
	int vertice;
} Aresta;

typedef struct {
	Vertice *primeiro;
} Grafo;

Vertice* criaVertice(int n);
Aresta* criaAresta(int n);
void inserirAresta(Grafo* grafo, int a, int b);
Vertice* procuraInsersaoVertice (Vertice *atual, int a, int b);
Aresta* procuraInsersaoAresta (Aresta *atual, int b);
void putsGrafo(Grafo* grafo);
void putsVertice(Vertice* vertice);
void putsAresta(Aresta* aresta);

Vertice* criaVertice(int n){
	Vertice *vertice = (Vertice*)malloc(sizeof(Vertice));
	vertice->Proximo = NULL;
	vertice->Primeira = NULL;
	vertice->vertice = n;
	return vertice;
}

Aresta* criaAresta(int n){
	Aresta *aresta = (Aresta*)malloc(sizeof(Aresta));
	aresta->Proximo = NULL;
	aresta->vertice = n;
	return aresta;
}

void inserirAresta(Grafo* grafo, int a, int b){
	printf ("Ligando %d -> %d", a, b);
	grafo->primeiro = procuraInsersaoVertice(grafo->primeiro, a, b);
	printf ("Ligando %d -> %d", b, a);
	grafo->primeiro = procuraInsersaoVertice(grafo->primeiro, b, a);
}

Vertice* procuraInsersaoVertice (Vertice *atual, int a, int b){
	puts ("\n!");
	
	
	if(atual == NULL){
		printf("%d", a);
		Vertice *novo = criaVertice(a);
		novo->Primeira = (Aresta*)procuraInsersaoAresta(novo->Primeira, b);
		return novo;
	} else {
		printf("%d", atual->vertice);
		if (atual->vertice == a){
			atual->Primeira = (Aresta*)procuraInsersaoAresta(atual->Primeira, b);
			return atual;
		}	else {
			atual->Proximo = (Vertice*)procuraInsersaoVertice(atual->Proximo, a, b);
			return atual;
		}
	}
}

Aresta* procuraInsersaoAresta (Aresta *atual, int b){
	
	if(atual == NULL){
		printf (" -> %d -> ||\n",b);
		return criaAresta(b);
	} else {
		printf ("-> %d", atual->vertice);
		atual->Proximo = procuraInsersaoAresta(atual->Proximo, b);
		return atual;
	}
}

void putsGrafo(Grafo* grafo){
	putsVertice(grafo->primeiro);
}

void putsVertice(Vertice* vertice){
	if (vertice == NULL)
		return;
	printf ("%d |", vertice->vertice);
	putsAresta(vertice->Primeira);
	printf("|| \n");
	putsVertice(vertice->Proximo);
}

void putsAresta(Aresta* aresta){
	if (aresta == NULL)
		return;
	printf ("%d ->", aresta->vertice );
	putsAresta(aresta->Proximo);
}

int main(void){

	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));

	while (1){
		int a, b;
		puts ("Diga de que vértice para que vértice deseja adicionar uma nova aresta:");
		scanf("%d %d", &a,&b);
		inserirAresta(grafo, a, b);
		puts("Inserido. Listas:");
		putsGrafo(grafo);
	}
	
	return 0;

}

