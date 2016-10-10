// cc (2016)
// Marlon Henry Schweigert
// Adriano Zanella Jr
/*
	gcc -Wall Grafo.h GrafoConstrutor.c GrafoTools.c GrafoEstado.c BellmanFord.c main.c -o dbellmanford
*/


#include "Grafo.h"

int main(){
	char esc = 'Y';
	while(esc == 'Y'){
		printf( "Deseja criar um grafo [Y/n]: ");
		scanf("%c", &esc);
		if( esc == 'Y'){
			Grafo* grafo = leituraTecladoGrafo();
			if(grafo != NULL){
				putsGrafo( grafo);
			}else{
				printf("Falha na criação do Grafo!\n");
			}
		}else if( esc == 'n'){
			printf("Encerrando programa!\n");
		}else{
			printf( "Escolha invalida! %c\n", esc);
			esc = 'Y';
		}
	}
	return 0;
}

/*Funções Grafo.h

//GrafoConstrutor.c

Grafo* criaGrafo( int n_vertices);
void addVertice( Grafo* grafo);
void addAresta( int origem, int destino, int custo, Grafo* grafo);
int removeVertice( int vertice, Grafo* grafo);
int removeAresta( int origem, int destino, Grafo* grafo);

//GrafoTools.c

Grafo* leituraTecladoGrafo();
Grafo* leituraGrafo();
Grafo* leituraGrafoDirecioado();
void putsGrafo();
int escolheVertice( Grafo* grafo);

//GrafoEstado.c

int seConectado( Grafo* grafo);
int seDirecionado( Grafo* grafo);

//Dijkstra.c

void dijkstra( Grafo* grafo, int verticeInicial);

*/