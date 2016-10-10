// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

//gcc -Wall ArvoreLarga.c ArvoreLarga.h CGrafos.c CGrafos.h main.c -o arvoreLargura

#include <stdlib.h>
#include <stdio.h>
#include "CGrafos.h"
#include "ArvoreLarga.h"

int main(void){
	Grafo* grafo = leituraTeclado();
	putsGrafo(grafo);
	/*Arvore* tree = testeArvore();
	putsArvore(tree);
	buscaVerticeArvore(0, tree);
	buscaVerticeArvore(3, tree);
	buscaVerticeArvore(6, tree);
	buscaVerticeArvore(9, tree);*/
	Arvore* tree = criarArvoreLargura( pedeVerticeInicial(),grafo);

	printf("\n\n");
	putsArvore(tree);
	
	printf("Descentes de um vertice:");
	putsDescendentes(pedeVerticeDesejado(), tree);

	printf("Ancestrais de um vertice:");
	putsAscendentes(pedeVerticeDesejado(), tree);
	return 0;
}
