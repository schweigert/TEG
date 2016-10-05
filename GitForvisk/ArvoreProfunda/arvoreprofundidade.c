#include <stdio.h>
#include <stdlib.h>

struct no {
	struct no** nos;
	int camp;
	int size;
};

struct no* ArvoreProfundidade (int**grafo,int* flag, int v, int atual){
	printf("Analisando %d\n", atual);
	flag[atual] = 1;
	struct no* ret =  malloc(sizeof(struct no));
	ret->camp = atual;
	ret->nos = NULL;
	int i;

	ret->size = 0;

	ret->nos = malloc(sizeof(struct no**)*v);


	for(i = 0; i < v; i++){
		if(!grafo[atual][i]) continue;
		if(flag[i])continue;
		printf("Gerando ramo de %d para %d\n", atual, i);
		struct no* proximo = ArvoreProfundidade(grafo, flag, v, i);
		ret->nos[ret->size] = proximo;
		ret->size++;
	}

	return ret;

}

void imprimeArvore(struct no* arv, int nivel){

	int i = nivel;
	while(i--)printf("  ");
	printf("%d(%d):\n", arv->camp, arv->size);
	if(arv->nos == NULL) return;
	if(arv->size == 0) return;
	for(i = 0; i < arv->size; i++){
		imprimeArvore(arv->nos[i], nivel+1);
	}
}

int imprimeArvoreApartirDe(struct no* arv, int v){

	if (arv->camp == v){
		imprimeArvore(arv, 0);
		puts("Ansc:");
		return 1;
	} else {
		int i = 0;
		int b;
		for( ; i < arv->size; i++){
			b = imprimeArvoreApartirDe(arv->nos[i], v);
			if (b == 1) {
				printf("%d\n", arv->camp);
				return 1;
			}
		}
	}
	return 0;

}

int main (void){

	int** grafo= NULL;
	int v, a, b, i, j;
	scanf("%d %d", &v, &a);

	grafo = malloc(sizeof(int*)*v);
	for (i = 0; i < v; i++){
		grafo[i] = malloc(sizeof(int)*v);
	}
	j = a;
	while(j--){
		scanf("%d %d", &a, &b);
		grafo[a][b] = 1;
		grafo[b][a] = 1;
	}
	
	int inicio = 0;
	scanf("%d", &inicio);
	int* flag = malloc(sizeof(int)*v);
	for(i = 0; i < v; i++) flag[i] = 0;
	struct no* arv = ArvoreProfundidade(grafo, flag, v, inicio);
	imprimeArvore(arv, 0);

	int opt = 0;
	int res = 1;
	while(res){
		puts("Buscando Ansc:");
		scanf("%d", &opt);
		res = imprimeArvoreApartirDe(arv, opt);
	}
	return 0;
}
