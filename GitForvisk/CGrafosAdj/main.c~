//gcc -Wall CGrafos.c FGrafos.c CGrafos.h main.c -o grafoAdjv3

#include <stdio.h>
#include "CGrafos.h"


int main (void){

	Grafo* grafo = leituraArquivo();

	//seConexo(grafo);

	seConexoDirecionado(grafo);

	putsGrafo(grafo);
	putsGrafoIncidencia(grafo);

	/*grafo = RemoveVertice(grafo, 3);

	putsGrafo(grafo);

	grafo = addVertice(grafo, 4);

	putsGrafo(grafo);*/

	grauNos(grafo);

	putsGrafo(grafo);

	return 0;
}

/* 	exemple

	Grafo* grafo = criarGrafo(4);
	
	addAresta(grafo, 0,1);
	addAresta(grafo, 0,2);
	addAresta(grafo, 0,3);
	addAresta(grafo, 2,3);
	
	putsGrafo(grafo);
	
	addVertice(grafo,2);
*/