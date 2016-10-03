// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

/*
	gcc -Wall main.c CGrafoVetorAdj.c CGrafoVetorAdj.h -o grafoVetorAdj
*/
#include <stdio.h>
#include "CGrafoVetorAdj.h"

int main(){
	Vetor* vetor = leituraArquivo();
	if(vetor != NULL)
		putsGrafo(vetor);
	return 0;
}