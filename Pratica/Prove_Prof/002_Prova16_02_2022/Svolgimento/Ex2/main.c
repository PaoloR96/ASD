#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int N=0,M=0;//dimensioni matrice N*M
    int Matrice[DIM_N][DIM_M];
    int CasiTest=0,index=0;
    int Risultato[DIM_N];
    scanf("%d",&CasiTest);
    while (index<CasiTest){
        //Fase1:Inserimento
        //Definisco le dimensioni della matrice
        scanf("%d %d",&N, &M);
        //Inserisco i parametri
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                scanf("%d",&Matrice[i][j]);
            }
        }
        //Fase2:Calcolo DP
        InitDP(DP,N,M);
        Risultato[index]=CalcolaDP(DP,Matrice,N,M);
        //Fase3:Passo al prossimo caso di test
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < CasiTest; i++)printf("%d \n",Risultato[i]);
    system("pause");
    return 0;
}

/*
Complessità: O(N*M*T) dove N numero di righe;M numero di colonne; T numero di casi di test

Ricorrenza: DP[i][j] => vale 1+[i-1][j]  Se l'elemento nella matrice è 0
                        vale 1           Se l'elemento nella matrice è 1 && i=0 (Caso base) 
                        vale 0           Se l'elemento nella matrice è 1

*/