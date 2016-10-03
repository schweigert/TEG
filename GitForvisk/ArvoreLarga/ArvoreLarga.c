// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include <stdlib.h>
#include <stdio.h>
#include "ArvoreLarga.h"
#include "CGrafos.h"

/*	Fuções de Criação
*
*
*
*
*/
Arvore* criarArvore(){
	Arvore* new = (Arvore*)malloc(sizeof(Arvore));
	new->n_vertices = 0;
	new->inicio = NULL;

	return new;
}

void addPrimeiroVerticeArvore(Vertice* vertice, Arvore* arvore){
	arvore->inicio = vertice;
	arvore->n_vertices++;
}


Vertice* criarVerticeArvore(int nome){
	Vertice* new = (Vertice*)malloc(sizeof(Vertice));
	new->pai = NULL;
	new->nome = nome;
	new->filho = NULL;

	return new;
}

void addVerticeArvore(Vertice* verticePai, Vertice* verticeFilho, Arvore* arvore){

	ListaV* novaSeccao = (ListaV*)malloc(sizeof(ListaV));
	novaSeccao->vertice = verticeFilho;
	verticeFilho->pai = verticePai;
	novaSeccao->proximo = NULL;

	if(verticePai->filho == NULL){
		verticePai->filho = novaSeccao;
		//printf("primeirofilho %i %i\n",verticePai->nome, verticeFilho->nome);
	}else{
		//printf("novo filho %i %i\n",verticePai->nome, verticeFilho->nome);
		ListaV* listaAux = verticePai->filho;
		while(listaAux->proximo != NULL){
			//printf("Proximo\n");
			listaAux = listaAux->proximo;
		}
		listaAux->proximo = novaSeccao;
	}
	arvore->n_vertices++;
}


/*	Funções de busca
*
*
*
*
*/
/*Buscar um vertice na arvore*/
Vertice* buscaVerticeArvore( int nome, Arvore* arvore){
	Vertice* verticeProc = NULL;
	Vertice* primeiro = arvore->inicio;

	if(primeiro->nome == nome){
		verticeProc = primeiro;
	}else{
		verticeProc = buscaVerticeFilhoArvore( nome, arvore->inicio);
	}
	return verticeProc;
}

/*Buscar um vertice a partir de um ramo da arvore com um vertice*/
Vertice* buscaVerticeFilhoArvore( int nome, Vertice* verticePai){
	Vertice* verticeFilho = NULL;
	Vertice* verticeProc = NULL;

	if(verticePai->filho != NULL){

		ListaV* listaAux = verticePai->filho;

		int leave = 0;
		do{

			leave = 0;
			Vertice* verticeFilho = listaAux->vertice;

			if(verticeFilho->nome == nome){
				return verticeFilho;
			}

			if(listaAux->proximo == NULL){
				leave = 1;
			}
			listaAux = listaAux->proximo;
		}while(!leave);

		if(verticeProc == NULL){
			listaAux = verticePai->filho;
			do{
				leave = 0;

				verticeProc = buscaVerticeFilhoArvore( nome, listaAux->vertice);

				if(verticeProc != NULL){
					if(verticeProc->nome == nome){
						return verticeProc;
					}else{
						return NULL;
					}
				}
				if(listaAux->proximo == NULL){
					leave = 1;
				}
				listaAux = listaAux->proximo;
			}while(!leave);
		}
	}
	return verticeProc;
}


/*	Funções de Leitura de Grafo	
*
*
*
*
*/
Arvore* criarArvoreLargura( int verticeInicial, Grafo* grafo){
	if(verticeInicial < grafo->vertices){

		Arvore* arvore = criarArvore();

		int verticeVisitado[grafo->vertices];
		for(int i = 0; i < grafo->vertices; i++)
			verticeVisitado[i] = 0;


		verticeVisitado[verticeInicial] = 1;
		int leave = 1;
		int i;
		do{
			if(verticeVisitado[i] == 1){
				Vertice* verticePai = buscaVerticeArvore(i,);

				for(int j = 0; j < grafo->vertices; j++){
					if((grafo->matriz_adj[i][j] > 0) && (i != j)){
						verticeVisitado[j] = 1;
						Vertice* verticeFilho = criarVerticeArvore(j, arvore);
					}
				}
				leave = 0;
			}
			i++;
			if(i >= grafo->vertices){
				i = 0;
			}
		}while(!leave);

		return arvore;
	}else{
		printf("Vertice não existe\n");
		putsGrafo(grafo);
		return NULL;
	}
}


/*	Funções de Impressão
*
*
*
*
*/
void putsArvore(Arvore* arvore){
	printf("\nNumero de Vertices: %i.\n", arvore->n_vertices);
	if(arvore->inicio != NULL){
		putsFilhos(arvore->inicio);
	}else{
		printf("\nArvore vazia!\n");
	}
	printf("\n");
}

void putsFilhos(Vertice* verticePai){
	if(verticePai->filho != NULL){
		printf("\nFilhos de %i:  ", verticePai->nome);

		ListaV* listaAux = verticePai->filho;
		int leave = 0;
		do{
			leave = 0;
			Vertice* verticeFilho = listaAux->vertice;
			printf("%i", verticeFilho->nome);
			if(listaAux->proximo != NULL){
				printf("  ");
			}else{
				leave = 1;
			}
			listaAux = listaAux->proximo;
		}while(!leave);

		listaAux = verticePai->filho;
		do{
			leave = 0;
			putsFilhos(listaAux->vertice);
			if(listaAux->proximo != NULL){
				printf("  ");
			}else{
				leave = 1;
			}
			listaAux = listaAux->proximo;
		}while(!leave);
	}else{
		printf("\nVertice %i sem filhos.", verticePai->nome);
	}
}


/*	Função de teste
*
*
*
*
*/
Arvore* testeArvore(){
	Arvore* arvore = criarArvore();
	Vertice* vertice;
	ListaV* lista;

	addPrimeiroVerticeArvore(criarVerticeArvore(0), arvore);

	addVerticeArvore( arvore->inicio, criarVerticeArvore(1), arvore);
	addVerticeArvore( arvore->inicio, criarVerticeArvore(2), arvore);
	addVerticeArvore( arvore->inicio, criarVerticeArvore(3), arvore);
	addVerticeArvore( arvore->inicio, criarVerticeArvore(4), arvore);

	vertice = arvore->inicio;
	lista = vertice->filho;
	addVerticeArvore( lista->vertice, criarVerticeArvore(5), arvore);
	addVerticeArvore( lista->vertice, criarVerticeArvore(6), arvore);


	vertice = arvore->inicio;
	lista = vertice->filho;
	lista = lista->proximo;
	lista = lista->proximo;
	addVerticeArvore( lista->vertice, criarVerticeArvore(7), arvore);
	addVerticeArvore( lista->vertice, criarVerticeArvore(8), arvore);

	vertice = arvore->inicio;
	lista = vertice->filho;
	lista = lista->proximo;
	lista = lista->proximo;
	lista = lista->proximo;
	addVerticeArvore( lista->vertice, criarVerticeArvore(9), arvore);
	return arvore;
}