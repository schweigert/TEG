#include <stdlib.h>
#include <stdio.h>
#include "CGrafos.h"


void seConexoDirecionado(Grafo* grafo){ // não esta funcionando no momento
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
		//printf("linha: %i\n", linha);
		if(vertVisit[linha][0] == 1){
			vertVisit[linha][1] = 1;
			do{
				mud = 0;
				do{
					if((grafo->matriz_adj[i][j] > 0) && (flag[i][j] == 0) && (i != j)){
						//printf("%i\n", vertVisit[j][0]);
						//printf("\nAresta encontrada\n%i <-> %i\n%i\n", j, i, vertVisit[i][0]);
						int aux = i;
						vertVisit[j][0] = 1;
						vertVisit[j][1] = 1;
						flag[i][j] = 1;
						i = j;
						j = aux;
						flag[i][j] = 1;
						mud = 1;
					}/*else if(flag[i][j])
						//printf("\nJa passamos aqui\n%i <-> %i\n%i\n", i, j, vertVisit[i][0]);
					else if(i == j){
						//printf("\nDiagonal principal\n");
						flag[i][j] = 1;
					}else*/
						//printf("\nAresta não encontrada\n%i -/- %i\n%i\n", i, j, vertVisit[i][0]);
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
						//printf("%i\n", vertVisit[j][0]);
						//printf("\nAresta encontrada\n%i <-> %i\n%i\n", j, i, vertVisit[i][0]);
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
		//printf("linha: %i\n", linha);
	}while(linha < grafo->vertices);

	for(linha = 0; linha < grafo->vertices; linha++)
		if(vertVisit[linha][0] != 1)
			ok = 0;
	if(ok == 0)
		printf("\nGrafo desconexo\n");
	else
		printf("\nGrafo Conexo\n");

}

void seConexo(Grafo* grafo){ // deu algum problema aqui
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
		//printf("linha: %i\n", linha);
		if(vertVisit[linha] == 1){
			do{
				mud = 0;
				do{
					if((grafo->matriz_adj[i][j] > 0) && (flag[i][j] == 0) && (i != j)){
						//printf("%i\n", vertVisit[j]);
						//printf("\nAresta encontrada\n%i <-> %i\n%i\n", j, i, vertVisit[i]);
						int aux = i;
						vertVisit[j] = 1;
						flag[i][j] = 1;
						i = j;
						j = aux;
						flag[i][j] = 1;
						mud = 1;
					}/*else if(flag[i][j])
						//printf("\nJa passamos aqui\n%i <-> %i\n%i\n", i, j, vertVisit[i]);
					else if(i == j){
						//printf("\nDiagonal principal\n");
						flag[i][j] = 1;
					}else
						//printf("\nAresta não encontrada\n%i -/- %i\n%i\n", i, j, vertVisit[i]);
					*/
					j++;
				}while(j < grafo->vertices);
				j = 0;
				i = linha;
			}while(mud == 1);
		}
		linha++;
		i = linha;
		j = 0;
		//printf("linha: %i\n", linha);
	}while(linha < grafo->vertices);

	for(linha = 0; linha < grafo->vertices; linha++)
		if(vertVisit[linha] == 0)
			ok = 0;
	if(ok == 0)
		printf("\nGrafo desconexo\n");
	else
		printf("\nGrafo Conexo\n");
}

void grauNosDirecionado(Grafo* grafo){
	int i, j;
	int grau[grafo->vertices][3];
	for(i = 0; i < grafo->vertices; i++){
		grau[i][0] = 0;
		grau[i][1] = 0;
		grau[i][2] = 0;
	}
	for(i = 0; i < grafo->vertices; i++){
		for(j = i; j < grafo->vertices; j++){
			if((i == j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i][0] += grafo->matriz_adj[i][j];
				grau[i][1] += grafo->matriz_adj[i][j];
				grau[i][2] += grafo->matriz_adj[i][j] * 2;
			}else if((i != j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i][1] += grafo->matriz_adj[i][j];
				grau[i][2] += grafo->matriz_adj[i][j];
				grau[j][0] += grafo->matriz_adj[i][j];
				grau[j][2] += grafo->matriz_adj[i][j];
			}
		}
	}
	for(i = 0; i < grafo->vertices; i++)
		printf("Grau do nó %i: \n\tentrada: %i;\n\tsaida: %i;\n\ttotal: %i", i+1, grau[i][0], grau[i][1], grau[i][2]);

}

void grauNos(Grafo* grafo){
	int i, j;
	int grau[grafo->vertices];
	for(i = 0; i < grafo->vertices; i++)
		grau[i] = 0;
	for(i = 0; i < grafo->vertices; i++){
		for(j = 0; j < grafo->vertices; j++){
			if((i == j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i] += grafo->matriz_adj[i][j] * 2;
			}else if((i != j) && (grafo->matriz_adj[i][j] > 0)){
				grau[i] += grafo->matriz_adj[i][j];
				grau[j] += grafo->matriz_adj[i][j];
			}
		}
	}
	for(i = 0; i < grafo->vertices; i++)
		printf("Grau do nó %i: %i.\n", i+1, grau[i]);	
}