#include <stdio.h>
#include "grafos.c"

int main (void){

	int v, a, d;	

	printf ("O grafo será direcionado? (1 - SIM, 0 - NÃO)");
	scanf ("%d", &d);

	printf ("Digite a quandidade de Vértices e Arestas:"\n);
	scanf ("%d %d", &v,&a);

	
	Grafo* grafo = CriarGrafo(v,a,d);

	int j = 0;

	for (j = 0; j < a; j++){
		
	}

	return 0;
}
