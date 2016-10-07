#include <stdio.h>
#include <stdlib.h>

void imprime(int **grafo, int v, int a, int n){
	int c = n;
	while(c--) printf("  ");
	printf("%d\n", a);
	for(c = 0; c < v; c++){
		if(grafo[a][c] == 0) continue;
		imprime(grafo, v, c, n+1);
	}
}

void preordem(int **grafo, int v, int a){
	int i = 0;
	printf("%d  ", a);
	for(i = 0; i < v; i++){
		if(grafo[a][i] == 0) continue;
		preordem(grafo, v, i);
	}
}

void posordem(int **grafo, int v, int a){
	int i = 0;
	for(i = 0; i < v; i++){
		if(grafo[a][i] == 0) continue;
		posordem(grafo, v, i);
	}
	printf("%d  ", a);
}

void simetrico(int **grafo, int v, int a){
	int i = 0;
	for(i = 0; i < v; i++){
		if( i == a )
			printf("%d  ", a);
		if(grafo[a][i] == 0) continue;
		simetrico(grafo, v, i);
	}
}

int main(void){
	
	int i, j;

	puts("Quantos nós terá a sua árvore?");
	int v;
	scanf("%d", &v);
	int **grafo = NULL;
	
	grafo = malloc(sizeof(int*)*v);
	for(i = 0; i < v; i++){
		grafo[i] = malloc(sizeof(int)*v);
		for(j = 0; j < v; j++){
			grafo[i][j] = 0;
		}
	}

	for (i = 0; i < v; i++){
		int q = 0;
		printf("O vértice %d liga a quantos vértices? ", i);
		scanf("%d", &q);
		while(q--){
			int b = 0;
			printf("%d - ", i);
			scanf("%d", &b);
			grafo[i][b] = 1;
		}
	}

	for(i = 0; i < v; i++){
		for(j = 0; j < v; j++){
			printf("%d ",grafo[i][j]);
		}
		printf("\n");
	}

	int r = 0;
	printf("Qual é a raíz da árvore?");
	scanf("%d", &r);

	imprime(grafo, v, r, 0);
	printf("\n Pre-ordem:\n");
	preordem(grafo, v, r);
	printf("\n Simetrico:\n");
	simetrico(grafo, v, r);
	printf("\n Pos-ordem:\n");
	posordem(grafo, v, r);
	puts("");
	return 0;
}
