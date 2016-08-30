/*	TEG - Grafo por matriz de adjacencia
*	Adriano Zanella Junior
*	Marlon Henry
*
*	Esse código somente trabalha com grafos não direcionados.
*	Para grafos direcionados precisa implementar funções adicionais.
*/
#ifndef __CGrafoVetorAdj__
#define __CGrafoVetorAdj__

#define NDIRCON "NotDirConexo.txt"
#define NDIRDESCON "NotDirDesconexo.txt"


typedef struct{
	struct Arestas *next;
	int vertice;
} Arestas;

typedef struct{
	int* vertices;
	int n_vertices;
	int n_arestas;
	int isDir;
	struct Arestas *arestas;
} Vetor;

Vetor* criaGrafo(int nV, int nA);
Vetor* leituraArquivo();

Arestas* criaAresta(int a);
void addAresta(Vetor* vetor, int a, int b);
//void addArestaDirecional(Vetor* vetor, int a, int b);

//Grafo* addVertice(Vetor* vetor);

void putsGrafo(Vetor* vetor);

#endif