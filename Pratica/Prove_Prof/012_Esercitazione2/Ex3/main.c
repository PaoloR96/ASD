#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int Matrice[MAX][MAX],Percorso[MAX];
    int test=2;
    int N=0,M=0;
    for (int i = 0; i < test; i++){
        //1.Inizializzo la matrice
        printf("Caso Test %d:\n",i+1);
        scanf("%d %d",&N,&M);
        InizializzaMatrice(Matrice,Percorso,N,M);
        //2.Riempio la matrice
        RiempiMatrice(Matrice,N,M);
        //3.Applico il backtracking
        printf("Stampa Percorsi:\n");
        TrovaPercorsi(Matrice,Percorso,0,0,N,M,0);
    }
    
    system("pause");
    return 0;
}
/*
Complessità: O(casiTest* K^(N+M)) dove k=2 rappresenta le direzioni

*/