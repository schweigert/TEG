#include <stdio.h>

int main(void){
	
	int **grafo, **flag;

	FILE *fp = NULL;
	
	int nVert = 0, nArest = 0;
	
	char arest, direcional = 'n';
	
	int a, b, i, j;
	int ok = 1; // se o grafo é completo
	int linha = 0; // marco da linha atual, esse marco não vai a vertices que ainda não tenham sido visitados
	int vertVist[nVert]; // Se o vertice ja foi visitado
	int mud = 0;
	
	char *arquivo;
	
	printf("Nome do arquivo contendo o grafo: ");
	scanf("%s", arquivo);
	
	//Abertura do arquivo
	fp = fopen( arquivo, "r");
	if(fp == NULL){
		printf("\nArquivo não existe\n");
		return 0;
	}
	
	//leitura do arquivo para vertica, direcionado e arestas
	fscanf( fp, "%c\n", &direcional);
	fscanf( fp, "%i\n", &nVert);
	printf("%i\n", nVert);
	fscanf( fp, "%i\n", &nArest);
	printf("%i\n", nArest);
	
	
	//alocação teste
	grafo = malloc(sizeof(int) * nVert);
	flag = malloc(sizeof(int) * nVert);
	for(i = 0; i < nVert; i++){	
		grafo[i] = malloc( sizeof(int) * nVert);
		flag[i] = malloc( sizeof(int) * nVert);	
	}
	
	//zerar vertices
	for(i = 0; i < nVert; i++)
		for(j = 0;  j < nVert; j++){
			grafo[i][j] = 0;
			flag[i][j] = 0;
		}
	
	//leitura do arquivo para grafo
	for (i = 0; (i < nArest) && (feof(fp) == 0); i++){
		
		fscanf( fp, "%c: %i, %i;\n", &arest, &a, &b);
		printf("%c: %i, %i\n", arest, a, b);
		
		grafo[--a][--b]++;
		flag[a][b] = 0;
		
		if((direcional == 'n') && (a != b)){
			grafo[b][a] += 1;
			flag[b][a] = 0;
		}
	}
	
	fclose(fp);
	arquivo = NULL;
	
	for (i= 0; i < nVert; i++){
		for (j = 0; j < nVert; j++){
			printf("%i ", grafo[i][j]);
		}
		printf("\n");
	}
	
	//grafo completo
	if(direcional == 'n'){
		
		for(i = 0; i < nVert; i++) // zerar as visitas
			vertVist[i] = 0;
		vertVist[0] = 1; // começamos pelo 1
		i = linha;
		j = 0;
		
		do{
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
							
						}else if(flag[i][j]){
							printf("\nJa passamos aqui\n%i -/- %i\n%i", i, j, vertVist[i]);
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
		if(ok == 0){
			
			printf("\nGrafo incompleto\n");
			
		}else{
			
			printf("\nGrafo completo\n");
			
		}
	}else{
		
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
		if(ok == 0){
			
			printf("\nGrafo incompleto\n");
			
		}else{
			
			printf("\nGrafo completo\n");
			
		}
	}
	
	return 0;
}
