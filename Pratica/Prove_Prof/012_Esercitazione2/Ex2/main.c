#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int test=0,N=0,M=0;
    int Labirinto[MAX][MAX],Percorso[MAX][MAX];
    scanf("%d",&test);
    for (int i = 0; i < test; i++){
        //Inizializzo le Matrici
        scanf("%d %d",&N,&M);
        InitMatrice(Labirinto,Percorso,N,M);
        //Riempio il labirinto
        RiempiMatice(Labirinto,N,M);
        //Calcola percorso
        printf("CASO TEST:\n");
        TrovaPercorso(Labirinto,Percorso,N,M,0,0);
    }
    system("pause");
    return 0;
}
/*
Complessità:O(k^(N+M)) dove k=2 rappresenta le direzioni dove mi sposto(destra,giù)
Dato il problema non mi sposterò  a serpentina né tornare indietro, 
quindi in un singolo percorso non attraversa mai tutte le celle della matrice: ogni mossa lo avvicina alla destinazione finale. 
Nel caso peggiore, l'algoritmo esplora tutte le possibili diramazioni e l'albero delle decisioni 
raggiunge una profondità massima di N+M−2 passi. 
Poiché a ogni passo esistono 2 scelte (destra o giù), la complessità risulta esponenziale: O(2^(N+M)).

*/