#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
// Stampa la matrice a video
void StampaMatrice(int M[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]); // 1 indica regina, 0 casella vuota
        }
        printf("\n");
    }
}
int TrovaPercorso(int M[N][N],int riga, int colonna,int visitato[N][N]){
     /*controllo i limiti della matrice e muri*/
     if (riga<0||riga>=N||colonna<0||colonna>=N||M[riga][colonna]==0||visitato[riga][colonna]==1)return 0;
     /*caso base: raggiunto la fine del labirinto*/
     if (riga==N-1 && colonna==N-1){
            printf("(%d,%d)\n", riga, colonna);
            visitato[riga][colonna] = 1;
            return 1;
     }else{
     /*caso ricorsivo: sono all'interno del labirinto*/
     visitato[riga][colonna]=1;
     printf("(%d,%d)->",riga,colonna);
     /*controllo sulle varie direzioni*/
     if(TrovaPercorso(M,riga,colonna+1,visitato))return 1;//destra
     if(TrovaPercorso(M,riga,colonna-1,visitato))return 1;//sinistra
     if(TrovaPercorso(M,riga+1,colonna,visitato))return 1;//sali
     if(TrovaPercorso(M,riga-1,colonna,visitato))return 1;//scendi
     /*nel caso in devo tornare indietro per altre soluzioni*/
     visitato[riga][colonna]=0; //backtracking
     return 0;

     }
     
}
    
