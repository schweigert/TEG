#include <stdio.h>
#include <stdlib.h>

void BuscaProfundidade(int** grafo, int* flag, int atual, int tamanho, int nivel){
  if(flag[atual] == 1)
    return;

  int i = nivel;
  while(i--) printf("  ");
  printf ("%d\n", atual);

  flag[atual] = 1;

  for(i = 0; i < tamanho; i++){
    if(grafo[atual][i] == 1)
      BuscaProfundidade(grafo, flag, i, tamanho, nivel+1);
  }
}

int main (void){

  int v = 0, a = 0, **grafo, *flag;

  int i, j, k;

  puts ("Digite a quantia de vértices do seu grafo");
  scanf ("%d", &v);

  puts ("Digite a quantia de arestas do seu grafo");
  scanf ("%d", &a);

  flag = malloc(sizeof(int)*v);
  grafo = malloc(sizeof(int*)*v);
  for (i = 0; i < v; i++){
    grafo[i] = malloc(sizeof(int)*v);
    flag[i] = 0;
    for (j = 0; j < v; j++){
      grafo[i][j] = 0;
    }
  }

  while(a--){
    puts("Qual vértice deseja ligar?");
    scanf("%d %d", &i, &j);

    grafo[i][j] = 1;
    grafo[j][i] = 1;
  }

  puts("Quem será o seu nó inicial?");
  scanf("%d", &k);

  BuscaProfundidade(grafo, flag, k, v, 0);

  return 0;
}
