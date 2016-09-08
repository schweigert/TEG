#include <stdio.h>
#include <stdlib.h>





void conexoRec(int** grafo, int* marca, int v, int a){
  printf(" Caminhando em: %d\n", a);
  int i;
  if(marca[a] >= 1) return;
  marca[a] = 1;
  printf("[ ");
  for(i = 0; i < v; printf("%d ", marca[i++]));
  printf("]\n");
  for(i = 0; i < v; i++){
    if(grafo[a][i] >= 1)conexoRec(grafo, marca,v, i);
  }
}

int ePonte(int** grafo,int v, int a, int b){
  int i,j;

  printf("Testando se %d é ponte\n", v);

  // Realizar copia do Grafo, retirando caminho de a para b

  int** nGrafo = malloc(sizeof(int**)*v);
  for(i=0;i<v;i++){
    nGrafo[i] = malloc(sizeof(int*)*v);
    for(j=0;j<v;j++){
      nGrafo[i][j] = grafo[i][j];
    }
  }

  nGrafo[a][b]--;
  nGrafo[b][a]--;

  // Realizar preparação para marcação
  int* marca = malloc(sizeof(int)*v);
  for(i=0;i<v;i++){
    marca[i] = 0;
  }
  conexoRec(nGrafo, marca, v, 0);
  int visitou = 0;
  // Verificar locais visitados
  printf("Você visitou:\n");
  for(i=0;i<v;i++){
    if(marca[i] >= 1){
      printf("\t%d\n",marca[i]);
      visitou++;
    }
  }

  return (visitou == v);
}

int Fleury(int** grafo, int v, int a){
  int i,j;
  printf("Fleury visitando %d\n", a);
  // Não vai pra ponte e para vertice de origem (Origem sempre = 0)
  for(i=0; i < v; i++){
    if (grafo[a][i] <= 0) continue;
    if(i == 0 || !ePonte(grafo,v,a,i)) continue;
    grafo[a][i]--;
    grafo[i][a]--;
    return Fleury(grafo, v, i);
  }

  // Neste caso, somente se existir uma ponte, mas exclui a Origem
  for(i=0; i < v; i++){
    if (grafo[a][i] <= 0) continue;
    if(i == 0) continue;
    grafo[a][i]--;
    grafo[i][a]--;
    return Fleury(grafo,v,i);
  }

  // neste caso, vai para qualquer lugar possível
  for(i=0; i < v; i++){
    if (grafo[a][i] <= 0) continue;
    grafo[a][i]--;
    grafo[i][a]--;
    Fleury(grafo,v,i);
    return 0;
  }
  puts ("Busca concluída");
  return a;

}


int main(void){

  // Iniciando o Grafo

  int** grafo = NULL;
  int v = 0, arr=0;

  int i, j;
  int a, b;
  printf("Quantos vértices? ");
  scanf ("%d", &v);
  printf("Quantas arestas? ");
  scanf("%d", &arr);

  grafo = (int**)malloc(sizeof(int*)*(v+1));
  for (i = 0; i < v; i++){
    grafo[i] = (int*)malloc(sizeof(int)*(v+1));
  }

  for (i = 0; i < v; i++){
    for (j = 0; j < v; j++){
      grafo[i][j] = 0;
    }
  }

  while (arr--){
    puts("Quais vértices deseja ligar?");
    scanf("%d %d", &a,&b);
    grafo[a][b]++;
    grafo[b][a]++;
  }
  int res = Fleury(grafo, v, 0);
  puts("");
  printf ("Fleury terminou em %d\n",res);
  if(res == 0) puts ("Este grafo pode ser euleriano");
  puts("Grafo final após remocoes:\n");

  int kaplaukasus = 0;

  for(i = 0; i < v; i++){
    for (j = 0; j < v; j ++){
      kaplaukasus += grafo[i][j];
      printf(" %d ", grafo[i][j]);
    }
    printf("\n");
  }

  if (kaplaukasus == 0 && res == 0) puts("Este grafo é euleriano");
  else puts ("Este grafo não é euleriano");

  return 0;
}
