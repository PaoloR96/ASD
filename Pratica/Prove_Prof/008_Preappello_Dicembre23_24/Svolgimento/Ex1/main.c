#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int Risultato[MAX];
    int Matrice[MAX][MAX];
    int index=0,test=0;
    int N=0,M=0;
    scanf("%d",&test);
    while (index<test){
        //1.Inserisco le dimensioni ed i parametri della matrice
        scanf("%d %d",&N,&M);
        InserisciMatrice(Matrice,N,M);
        //2.Ordino elementi per riga
        OrdinaPerRiga(Matrice,N, M);
        //3.Trovo il minimo Ass
        Risultato[index]=CalcolaDiff(Matrice, N, M);
        //4.Passo al prossimo caso di test
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++){
        printf("%d \n",Risultato[i]);
    }
    
    

    system("pause");
    return 0;
}

/*
  Complessità: O(N * M * log M)
  
  L'algoritmo si divide in due fasi principali, entrambe con la stessa complessità:
  1. Ordinamento: Per ognuna delle N righe, ordino i suoi M elementi (costo: N * M * log M).
  2. Ricerca: Per ognuna delle N-1 coppie di righe adiacenti, prendo gli M elementi 
     della prima e applico una ricerca binaria nella seconda (costo: N * M * log M).
 
 */