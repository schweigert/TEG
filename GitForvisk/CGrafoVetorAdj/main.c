/*
	gcc -Wall main.c CGrafoVetorAdj.c CGrafoVetorAdj.h -o grafoVetorAdj
*/
/*	TEG - Grafo por matriz de adjacencia
*	Adriano Zanella Junior
*	Marlon Henry
*
*	Esse código somente trabalha com grafos não direcionados.
*	Para grafos direcionados precisa implementar funções adicionais.
*/
#include <stdio.h>
#include "CGrafoVetorAdj.h"

int main(){
	Vetor* vetor = leituraArquivo();
	if(vetor != NULL)
		putsGrafo(vetor);
	return 0;
}