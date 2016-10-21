#include <stdio.h>
#include <stdlib.h>

struct No {
	struct No *p;
	int np;
	int atual;
}

int* flag;

struct No* arvoreLargura(int** grafo, int v, int *atuais){

	int n, i, j;
	for(i = 0; ; i++){
		if(atuais[i] == -1)
			break;
		n++;
	}

	int m;
	
}

int main(void){

	int **grafo;
	int v,a;     // Vertices e Arestas
	int i, j, k  // Auxiliares
	    v1, v2, c;

	flag = malloc(sizeof(int)*v);

	puts("nV nA");
	scanf("%d %d", &v, *a);

	grafo = (int**)malloc(sizeof(int*)*v);
	for(i=0 ; i<v ; i++){
		grafo[i] = (int*)malloc(sizeof(int)*v);
		for(j=0 ; j<v ; j++){
			grafo[i][j] = 0;
		}
	}

	int s,f; // Inicio e Fim
	puts("S F");
	scanf("%d %d", &s, &f);

	i = a;
	puts("V' V'' C");
	while(i--){
		scanf("%d %d %d", &v1, &v2, &c);
		gafo[v1][v2]+=c;
	}

	for(i=0 ; i<v; i++){
		for(j=0 ; j<v; j++){
			printf("%d ", grafo[i][j]);
		}
		printf("\n");
	}

	

	return 0;
}
