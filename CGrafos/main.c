#include <stdio.h>
#include "CGrafos.h"


int main (void){
	
	Grafo* grafo = criarGrafo(4);
	
	addAresta(grafo, 0,1,0);
	addAresta(grafo, 0,2,0);
	addAresta(grafo, 0,3,0);
	addAresta(grafo, 2,3,0);
	
	putsGrafo(grafo);
	
	addVertice(grafo, 2);
	
	putsGrafo(grafo);
	
	return 0;
}