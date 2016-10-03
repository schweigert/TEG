// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr

#include <stdlib.h>
#include <stdio.h>
#include "CGrafos.h"

/*	Função grafo direcionado
*	essa função retorna se o grafo é direcionado ou não
*/
int direcionado(Grafo* grafo){
	return grafo->isDir;
}

/*	Função grafo não direcionado conexo
*	essa função define se o grafo não direcionado é conexo ou não
*/
void seConexo(Grafo* grafo){
	int flag[grafo->vertices][grafo->vertices];
	int vertVisit[grafo->vertices];
	int mud = 0, linha = 0;
	int i, j;
	int num_subgrafo = 1, subAtual;
	for(j = 0; j < grafo->vertices; j++){
		vertVisit[j] = 0;
		for(i = 0; i < grafo->vertices; i++)
			flag[i][j] = 0;
	}
	vertVisit[linha] = num_subgrafo;
	j = 0; i = linha;
	do{
		if(vertVisit[linha] == 0){
			num_subgrafo++;
			vertVisit[linha] = num_subgrafo;
		}
		if(vertVisit[linha] > 0){
			do{
				mud = 0;
				do{
					if((grafo->matriz_adj[i][j] > 0) && (flag[i][j] == 0) && (i != j)){
						int aux = i;
						vertVisit[j] = vertVisit[i];
						flag[i][j] = 1;
						i = j;
						j = aux;
						flag[i][j] = 1;
						mud = 1;
					}else	flag[i][j] = 1;
					j++;
				}while(j < grafo->vertices);
				j = 0;
				i = linha;
			}while(mud == 1);
		}
		linha++;
		i = linha;
		j = 0;
	}while(linha < grafo->vertices);

	if(num_subgrafo == 1)
		printf("\nGrafo Conexo\n");
	else{
		printf("\nGrafo desconexo\n");

		for(subAtual = 1; subAtual <= num_subgrafo; subAtual++){
			int sub_nVertices = 0;
			int relacao_vert[grafo->vertices];
			for(i = 0; i < grafo->vertices; i++){
				if(subAtual == vertVisit[i]){
					relacao_vert[i] = sub_nVertices;
					sub_nVertices++;
					//printf("vert %i -> %i\n", i, relacao_vert[i]);
				}else{
					relacao_vert[i] = -1;
				}
			}
			Grafo *subgrafo = criarGrafo(sub_nVertices);
			for(i = 0; i < grafo->vertices; i++){
				if(subAtual == vertVisit[i]){
					for(j = i; j < grafo->vertices; j++){
						if(subAtual == vertVisit[j]){
							//printf("linha %i\tcoluna %i\tnvert: %i\n", i, j, grafo->matriz_adj[i][j]);
							for(mud = 0; mud < grafo->matriz_adj[i][j]; mud++)
								addAresta(subgrafo, relacao_vert[i], relacao_vert[j]);
						}
					}
				}
			}
			putsGrafo(subgrafo);
			printf("\n");
		}
	}
}

/*	Função grau de nós para grafo não direcionado
*	essa função calcula o grau de cada nó em um grafo não direcionado
*/
void grauNos(Grafo* grafo){
	int i, j;
	int grau[grafo->vertices];
	for(i = 0; i < grafo->vertices; i++)
		grau[i] = 0;
	for(i = 0; i < grafo->vertices; i++)
		for(j = i; j < grafo->vertices; j++)
			if((i == j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i] += grafo->matriz_adj[i][j] * 2;
			}else if((i != j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i] += grafo->matriz_adj[i][j];
				grau[j] += grafo->matriz_adj[i][j];
			}
	for(i = 0; i < grafo->vertices; i++)
		printf("Grau do nó %i: %i.\n", i+1, grau[i]);	
}