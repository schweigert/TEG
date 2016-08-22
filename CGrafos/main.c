#include <stdio.h>
#include "CGrafos.h"


int main (void){
	
	Grafo* grafo = criarGrafo(30);
	
	addAresta(grafo, 0,1,1);
	
	return 0;
}