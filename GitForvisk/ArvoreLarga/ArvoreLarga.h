// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include "CGrafos.h"

#ifndef __ArvoreProfunda__
#define __ArvoreProfunda__

#define MARCA 1
#define SEMMARCA 0
#define SUCESSO 1
#define FRACASSO 0

typedef struct {
	struct Vertice *inicio;
	int n_vertices;
} Arvore;

typedef struct {
	int nome;
	struct ListaV *filho;
	struct Vertice *pai;
} Vertice;

typedef struct {
	//struct Arestas *aresta;
	struct Vertice *vertice;
	struct ListaV *proximo;
} ListaV;

/*typedef struct {
	struct Vertice *filho;
	struct Vertice *pai;
	int peso;
} Arestas;*/

/*	Funções de Criação	*/
Arvore* criarArvore();
Vertice* criarVerticeArvore(int nome);
void addPrimeiroVerticeArvore(Vertice* vertice, Arvore* arvore);
void addVerticeArvore(Vertice* novoVertice, Vertice* pai, Arvore* arvore);

/*	Funções de busca	*/
Vertice* buscaVerticeArvore(int nome, Arvore* arvore);
Vertice* buscaVerticeFilhoArvore(int nome, Vertice* verticePai);

/*	Funções de Leitura de Grafo	*/
Arvore* criarArvoreLargura( int verticeInicial, Grafo* grafo);

/*	Funções de Impressao	*/
void putsArvore(Arvore* arvore);
void putsFilhos(Vertice* verticePai);

/*	Função de Teste 	*/
Arvore* testeArvore();

#endif