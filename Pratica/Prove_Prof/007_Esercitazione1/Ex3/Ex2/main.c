#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   printf("SAMPLE INPUT:\n");
   int index=0;
   int numR,numC=0;
   int W[MAX][MAX];
   while (index<3){
        //1.Inserisco le righe e le colonne
        scanf("%d %d",&numR,&numC);
        //2.Inseriso i pesi della matrice
        for (int i = 0; i < numR; i++){
            for (int j = 0; j < numC; j++){
                scanf("%d",&W[i][j]);
            }
        }
        //3.Inizializo e Calcolo la matrice DP
        InitDP(DP,W,numC,numR);
        CalcolaDP(DP,W,numR,numC);
        //4.Elaboro il percoso con il costo minimo
        printf("SAMPLE OUTUPUT CASO%d:",index+1);
        ElaboraPercorso(DP,numR,numC);
        int rigaMiglioreIniziale = TrovaIlMinimo(DP, 0, numR);
        int costoMinimo = DP[rigaMiglioreIniziale][0];
        printf("%d\n", costoMinimo);
        //5.Passo al caso di test successivo
        index++;
        
   }
    system("pause");
    return 0;
}
/*
Complessità:O(numRighe*numColonne)

Ricorrenza: Caso base:DP[r][ultimaColonna]=W[r][ultimaColonna] per ogni r £(0,numRighe)   
            DP[r][c]=W[r][c]+min2(DP[rigaSu][c+1],DP[rigaGiu][c+1],DP[r][c+1]);  con c £(NumColonne-2,0) mentre r£(0,numRighe)
*/