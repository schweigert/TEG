#include <stdio.h>
#include <stdlib.h>


int removeMenorCaminho(int v1, int v2, int** grafo, int v, int distMaxima){
  // printf("Entrou em %d (Buscando %d)\n", v1, v2);
  if (distMaxima < 0) return 0;
  if (v1 == v2) return 1;
  int resp = 0;
  int respp = 0;
  int i = 0;
  for(i = 0; i < v; i++){
    // printf("Analisando %d para %d\n", v1, i);
    if(grafo[v1][i] == 0)
      continue;
    resp = removeMenorCaminho(i, v2, grafo, v, distMaxima - grafo[v1][i]);

    if(resp == 1){
      grafo[v1][i] = 0;
      // printf("Removeu caminho de %d para %d\n", v1, i);
    }

    respp = respp | resp;
  }

  return respp;

}

int encontraMenorMarcado(int** r, int v){
	int i;
	int resp = -1, custo = -1;
	for(i = 0; i < v; i++){
		if(r[i][2] != 1) continue;
		if(r[i][1] < custo || custo == -1){
			resp = i;
			custo = r[i][1];
		}
	}
	return resp;
}

int** dijkstra(int** grafo, int v, int s){
	int i,j;
	int** r = malloc(sizeof(int*)*v);
	for(i = 0; i < v; i++){
		r[i] = malloc(sizeof(int)*3);
		r[i][0] = 0; // De onde
		r[i][1] = 0; // Com tal custo
		r[i][2] = 0; // Estado de relaxação

		// Estado de relaxação:
		// 0 = Não alcançado
		// 1 = Alcançado
		// 2 = Relaxado
	}

	// Primeiro Vértice
	r[s][0] = s; // Dele mesmo
	r[s][1] = 0; // Custo zero
	r[s][2] = 2; // Relaxado

	// Marcar todos apartir da saída
	for(i = 0; i < v; i++){
		if (grafo[s][i] == 0) continue;
		if (r[i][2] == 2) continue;
		r[i][0] = s;
		r[i][1] = grafo[s][i];
		r[i][2] = 1;
	}

	// Próximos Vértices
	while(1){

		int vertice =	encontraMenorMarcado(r, v);

		if(vertice == -1){
			return r;
		}


		r[vertice][2] = 2;
		for(i = 0; i < v; i++){
			if(grafo[vertice][i] == 0 || r[i][2] == 2){
				continue;
			}


			if(r[i][1] >= r[vertice][1]+grafo[vertice][i] || r[i][2] == 0){
				r[i][0] = vertice;
				r[i][1] = r[vertice][1]+grafo[vertice][i];
				r[i][2] = 1;
			}



			r[vertice][2] = 2;

		}
	}
}


void printGrafo(int** g, int v){
	int i, j;
	for(i = 0; i < v; i++){
		for(j = 0; j < v; j++){
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

int main(void){

  while (1){
    int N, M;
    int** grafo;
    scanf("%d %d", &N, &M);

    if (N == 0) return 0;

    int i,j;

    grafo = malloc(sizeof(int*)*N);
    for(i=0; i < N; i++){
      grafo[i] = malloc(sizeof(int)*N);
      for(j=0; j < N; j++){
        grafo[i][j] = 0;
      }
    }

    int S, D;
    scanf("%d %d", &S, &D);
    int U, V, P;
    while(M--){
      scanf("%d %d %d", &U, &V, &P);
      grafo[U][V] = P;
    }

    int** respDkst = dijkstra(grafo, N, S);
    int d = respDkst[D][1];

    // printGrafo(grafo, N);

    removeMenorCaminho(S, D, grafo, N, d);

    respDkst = dijkstra(grafo, N, S);
    // puts("");
    // printGrafo(grafo, N);

    if(respDkst[D][2] == 0){
      puts("-1");
      continue;
    } else {
      printf("%d\n", respDkst[D][1]);
    }

  }


	return 0;
}
