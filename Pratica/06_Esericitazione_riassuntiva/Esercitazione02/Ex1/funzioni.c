#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*variabili globali*/
int occorrenzeMax = 0;
int startMax = 0;
int endMax = 0;
int j = 0;   // fine finestra

/*Metodi Base*/
void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

/*Metodi*/
void CalcolaOccorrenze(int A[], int i,int y){
    /*Caso base: Ho raggiunto la fine del vettore*/
    if(i==N)return;
    /*caso ricosivo:*/
    while(j < N && A[j] <= A[i] + y - 1) j++;//allargo la finestra
    int occ=j-i;//definisco il perido
    if (occ>occorrenzeMax){ //salvo i parametri
        occorrenzeMax=occ;
        startMax=A[i];
        endMax=A[j-1];
    }
    CalcolaOccorrenze(A,i+1,y);//passo all'elemento successivo
}


void CalcolaRicorsivo(int A[], int y) {
    
    CalcolaOccorrenze(A, 0,y);

    printf("Numero di eventi massimo in un periodo di Y = %d anni e': CalcolaOccorrenze %d, occorsi tra l'anno %d e l'anno %d\n",
           y, occorrenzeMax, startMax, endMax);
}


/*
Complessità:

Avanzamento di i → O(N)

Avanzamento totale di j → O(N)

Operazioni costanti per aggiornare il massimo → O(N)

Totale complessivo = O(N + N + N) = O(N)
*/