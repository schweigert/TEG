// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

//gcc -Wall CGrafos.c FGrafos.c CGrafos.h main.c -o grafoAdjv3

#include <stdio.h>
#include "CGrafos.h"


int main(void){
	Grafo* grafo = leituraArquivo();
	if(grafo != NULL){
		seConexo(grafo);
		grauNos(grafo);
		putsGrafo(grafo);
	}
	return 0;
}
