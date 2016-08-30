/*	gcc -Wall grafo_matriz_adj_v2.c -o grafadjv2
*	autor: 	Adriano Zanella Junior
*			Marlon Henry
*/

#include <stdio.h>
#include <stdlib.h>

#define NDIRCOMP "NotDirComp.txt"
#define NDIRINCOMP "NotDirIncomp.txt"

int leituragrafo(int **grafo, char *dir);
int completoNaoDirecional(int **grafo, int nVert);
int completoDirecional(int **grafo, int nVert);
int grauNos(int **grafo, int nVert);


int main(void){
	
	int **grafo;
	int nVert = 0;
	char direcao = 'n';
	
	nVert = leituragrafo(grafo, &direcao);
	if(nVert == -1){
		printf("Falha ao abrir arquivo\n");
	}else if(nVert == 0){
		printf("Não há grafo\n");
	}else{
		printf("Grafo lido\n");
	}

	//ver leitura
	for (int i= 0; i < nVert; i++){
		for (int j = 0; j < nVert; j++){
			printf("%i ", grafo[i][j]);
		}
		printf("\n");
	}

	if(direcao == 'n'){
		completoNaoDirecional(grafo, nVert);
	}

	return 0;
}

int leituragrafo(int **grafo, char *dir){

	char arquivo[50], arestas, direcao;
	FILE *fp;
	int nVert = 0, nArest = 0;
	int i, j, a = 0, b = 0;
/*
	printf("Nome do arquivo contendo o grafo: ");
	scanf("%s", arquivo);
	fp = fopen( arquivo, "r");
*/
	fp = fopen( NDIRCOMP, "r");
	
	
	if(fp == NULL){
		printf("\nArquivo não existe\n");
		return -1;
	}

	//leitura do arquivo para vertica, direcionado e arestas
	fscanf( fp, "%c\n", &direcao);
	fscanf( fp, "%i\n", &nVert);
	printf("Vertices: %i", nVert);
	fscanf( fp, "%i\n", &nArest);
	printf("Arestas: %i\n", nArest);


	//alocação vertices
	grafo = malloc(sizeof(int) * nVert);
	//flag = malloc(sizeof(int) * nVert);
	for(i = 0; i < nVert; i++){	
		grafo[i] = malloc( sizeof(int) * nVert);
		//flag[i] = malloc( sizeof(int) * nVert);	
	}
	
	//zerar vertices
	for(i = 0; i < nVert; i++)
		for(j = 0;  j < nVert; j++){
			grafo[i][j] = 0;
			//flag[i][j] = 0;
		}
	
	//leitura do arquivo para grafo
	for (i = 0; (i < nArest) && (feof(fp) == 0); i++){
		fscanf( fp, "%c: %i, %i;\n", &arestas, &a, &b);
		printf("%c: %i, %i\n", arestas, a, b);
		grafo[--a][--b]++;
		//flag[a][b] = 0;
		if((direcao == 'n') && (a != b)){
			grafo[b--][a--] += 1;
			//flag[b][a] = 0;
		}
	}

	//liberar arquivo
	//fclose(fp);

	//ver leitura
	for (i= 0; i < nVert; i++){
		for (j = 0; j < nVert; j++){
			printf("%i ", grafo[i][j]);
		}
		printf("\n");
	}

	*dir = direcao;
	return nVert;
}

int completoNaoDirecional(int **grafo, int nVert){
	int flag[nVert][nVert];
	int vertVist[nVert];
	int i, j;
	int mud = 0;
	int linha = 0;
	int ok = 1;

	printf("%i\n", grafo[nVert-1][nVert-1]);

	/*Desnecessaria agora
	//alocação das flags
	//grafo = malloc(sizeof(int) * nVert);
	flag = malloc(sizeof(int) * nVert);
	for(i = 0; i < nVert; i++){
		//grafo[i] = malloc( sizeof(int) * nVert);
		flag[i] = malloc( sizeof(int) * nVert);	
	}
	//zerar as flags
	for(i = 0; i < nVert; i++)
		for(j = 0;  j < nVert; j++){
			//grafo[i][j] = 0;
			flag[i][j] = 0;
		}

	//grafo completo
	for(i = 0; i < nVert; i++) // zerar as visitas
		vertVist[i] = 0;
	*/

	vertVist[0] = 1; // começamos pelo 1
	i = linha;
	j = 0;
	
	do{
		printf("%i %i\n", linha, vertVist[linha]);
		if(vertVist[linha] == 1){
			do{
				mud = 0;
				do{
					if((grafo[i][j] > 0) && (flag[i][j] == 0) && (i != j)){
						
						printf("\n%i", vertVist[j]);
							
						int aux = i;
						vertVist[j] = 1;
						flag[i][j] = 1;
						i = j;
						j = aux;
						flag[i][j] = 1;
						mud = 1;
						printf("\nAresta encontrada\n%i <-> %i\n%i", j, i, vertVist[i]);
					}else if(flag[i][j] && (grafo[i][j] > 0)){
						printf("\nJa passamos aqui\n%i <-> %i\n%i", i, j, vertVist[i]);
						j++;
					}else{
						printf("\nAresta não encontrada\n%i -/- %i\n%i", i, j, vertVist[i]);
						j++;
					}
				}while( j < nVert);
				j = 0;
				i = linha;
			}while(mud == 1);
		}
		linha++;
		i = linha;
		printf("\nlinha %i\n", linha);
	}while(linha < nVert);
	
	for(linha = 0; linha < nVert; linha++){
		if(vertVist[linha] == 0)	
		ok = 0;
	}

	//finalização
	if(ok == 0)
		printf("\nGrafo incompleto\n");
	else
		printf("\nGrafo completo\n");	

	return 0;
}

int completoDirecional(int **grafo, int nVert){

	/*}else{
		printf("\ngrafo direcionado: implementação a ser feita");
		
		int ok = 1;
		int linha = 0;
		int vertVist[nVert];
		for(i = 0; i < nVert; i++)
			vertVist[i] = 0;
		vertVist[0] = 1;
		i = linha;
		j = 0;
		
		for(linha = 0; linha < nVert; linha++){
			if(vertVist[linha] == 0)	
				ok = 0;
		}

		//finalização
		if(ok == 0)	
			printf("\nGrafo incompleto\n");	
		else
			printf("\nGrafo completo\n");	
	}*/

	return 0;
}

int grauNos(int **grafo, int nVert){
	int i, j;
	int grau[nVert];
	for(i = 0; i < nVert; i++){
		for(j = i; j < nVert; j++){
			if( (i == j) && (grafo[i][j] > 0))
				grau[i] += grafo[i][j]*2;
			else if(grafo[i][j] > 0){
				grau[i] += grafo[i][j];
				grau[j] += grafo[i][j];
			}
		}
	}
	for( i = 0; i < nVert; i++){
		printf("grau do nó %i: %i.\n", i+1, grau[i]);
	}
	return 0;
}

int removerNo(int **grafo, int nVert){

	
	/*
	// Remover e Adicionar
	{
		char resp;
		
		while (1) {
			puts ("Deseja remover (r) ou adicionar (a) [Continuar - (c)]?");
			scanf ("%c", &resp);

			if (resp == 'c')
				break;
				
			if (resp == remover){
				puts ("Qual vertice deseja remover?");
				int i;
				scanf ("%d", &i);
				
			} else {
				
			}
			
		}
	}
	*/
	return 0;
}