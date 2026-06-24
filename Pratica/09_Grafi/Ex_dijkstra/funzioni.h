#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_NODI 100

typedef struct {
    int id;
    int costo;
}Elemento;
//Metodi Gestione Coda a Priorità
void Push(Elemento coda[], int *size,int id,int costo);
Elemento MinPop(Elemento coda[], int *size);
int dijkstra(int start, int target, int n, int grafo[MAX_NODI][MAX_NODI]);



#endif
