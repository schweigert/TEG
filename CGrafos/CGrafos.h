#ifndef __CGrafos__
#define __CGrafos__

typedef struct {
	int** matriz_adj;
	int vertices;
	int arestas;
	int isDir;
} Grafo;

Grafo* criarGrafo (int n_vertices);

void addAresta(Grafo* grafo, int a, int b);
void addArestaDirecionado(Grafo* grafo, int a, int b);

void addVertice(Grafo* grafo, int quant);
void RemoveVertice(Grafo* grafo, int a);

void putsGrafo (Grafo* grafo);

#endif