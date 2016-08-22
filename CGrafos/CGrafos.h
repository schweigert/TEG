#ifndef __CGrafos__
#define __CGrafos__

typedef struct {
	int** matriz_adj;
	int** matriz_inc;
	int vertices;
	int arestas;
} Grafo;

Grafo* criarGrafo (int n_vertices);
void addAresta (Grafo* grafo, int a, int b, int dir);
#endif