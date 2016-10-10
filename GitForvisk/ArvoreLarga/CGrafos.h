// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include <stdlib.h>
#include <stdio.h>

#ifndef __CGrafos__
#define __CGrafos__

#define GRAFO1 "grafo1.txt"
#define GRAFO2 "grafo2.txt"
#define GRAFO3 "grafo3.txt"
#define GRAFO4 "grafo4.txt"
#define GRAFO5 "grafo5.txt"

typedef struct {
	int** matriz_adj;
	int vertices;
	int arestas;
	int isDir;
} Grafo;

Grafo* criarGrafo(int n_vertices);
Grafo* leituraArquivo();
Grafo* leituraTeclado();

void addAresta(Grafo* grafo, int a, int b);
void addArestaDirecionado(Grafo* grafo, int a, int b);

int direcionado(Grafo* grafo);

Grafo* addVertice(Grafo* grafo, int quant);
Grafo* RemoveVertice(Grafo* grafo, int a);

Grafo* addVerticeDirecional(Grafo* grafo, int quant);
Grafo* RemoveVerticeDirecional(Grafo* grafo, int a);

void putsGrafo(Grafo* grafo);

void seConexoDirecionado(Grafo* grafo);
void seConexo(Grafo* grafo);

void completo(Grafo* grafo);

Grafo* complemento(Grafo* grafo);

void grauNosDirecionado(Grafo* grafo);
void grauNos(Grafo* grafo);

#endif
