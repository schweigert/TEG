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
	int mud = 0, linha = 0, ok = 1;
	int i, j;
	for(j = 0; j < grafo->vertices; j++){
		vertVisit[j] = 0;
		for(i = 0; i < grafo->vertices; i++)
			flag[i][j] = 0;
	}
	vertVisit[linha] = 1;
	j = 0; i = linha;
	do{
		if(vertVisit[linha] == 1){
			do{
				mud = 0;
				do{
					if((grafo->matriz_adj[i][j] > 0) && (flag[i][j] == 0) && (i != j)){
						int aux = i;
						vertVisit[j] = 1;
						flag[i][j] = 1;
						i = j;
						j = aux;
						flag[i][j] = 1;
						mud = 1;
					}
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
	for(linha = 0; linha < grafo->vertices; linha++)
		if(vertVisit[linha] == 0)
			ok = 0;
	if(ok == 0)
		printf("\nGrafo desconexo\n");
	else
		printf("\nGrafo Conexo\n");
}

/*	Função grafo direcionado conexo
*	essa função define se o grafo direcionado é conexo ou não
*/
void seConexoDirecionado(Grafo* grafo){
	int flag[grafo->vertices][grafo->vertices];
	int vertVisit[grafo->vertices][2];
	int mud = 0, linha = 0, ok = 1;
	int i, j;

	for(j = 0; j < grafo->vertices; j++){
		vertVisit[j][0] = 0;
		vertVisit[j][1] = 0;
		for(i = 0; i < grafo->vertices; i++)
			flag[i][j] = 0;
	}
	j = 0; i = linha;
	vertVisit[linha][0] = 1;
	vertVisit[linha][1] = 0;

	do{
		if(vertVisit[linha][0] == 1){
			vertVisit[linha][1] = 1;
			do{
				mud = 0;
				do{
					if((grafo->matriz_adj[i][j] > 0) && (flag[i][j] == 0) && (i != j)){
						int aux = i;
						vertVisit[j][0] = 1;
						vertVisit[j][1] = 1;
						flag[i][j] = 1;
						i = j;
						j = aux;
						flag[i][j] = 1;
						mud = 1;
					}
					j++;
				}while(j < grafo->vertices);
				j = 0;
				i = linha;
			}while(mud == 1);
		}else{
			vertVisit[linha][1] = 1;
			do{
				mud = 0;
				do{
					if((grafo->matriz_adj[i][j] > 0) && (flag[i][j] == 0) && (i != j) && (vertVisit[j][0] == 1)){
						int aux = i;
						vertVisit[i][0] = 1;
						vertVisit[i][1] = 1;
						vertVisit[j][0] = 1;
						vertVisit[j][1] = 1;
						flag[i][j] = 1;
						i = j;
						j = aux;
						flag[i][j] = 1;
						mud = 1;
					}
					j++;
				}while(j < grafo->vertices);
			}while(mud == 1);
		}
		linha++;
		i = linha;
		j = 0;
	}while(linha < grafo->vertices);

	for(linha = 0; linha < grafo->vertices; linha++)
		if(vertVisit[linha][0] != 1)
			ok = 0;
	if(ok == 0)
		printf("\nGrafo desconexo\n");
	else
		printf("\nGrafo Conexo\n");

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

/*	Função grau de nós para grafo direcionado
*	essa função calcula o grau de cada nó em um grafo direcionado
*	grau[i][0] -> entrada; grau[i][1] -> saida; grau[i][2] -> total
*/
void grauNosDirecionado(Grafo* grafo){
	int i, j;
	int grau[grafo->vertices][3];
	for(i = 0; i < grafo->vertices; i++){
		grau[i][0] = 0;
		grau[i][1] = 0;
		grau[i][2] = 0;
	}
	for(i = 0; i < grafo->vertices; i++)
		for(j = 0; j < grafo->vertices; j++)
			if((i == j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i][0]++;
				grau[i][1]++;
				grau[i][2] += 2;
			}else if((i != j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i][1]++;
				grau[j][0]++;
				grau[i][2]++;
				grau[j][2]++;
			}
	for(i = 0; i < grafo->vertices; i++)
		printf("\nGrau do nó %i: \n\tentrada: %i;\n\tsaida: %i;\n\ttotal: %i;", i+1, grau[i][0], grau[i][1], grau[i][2]);

}