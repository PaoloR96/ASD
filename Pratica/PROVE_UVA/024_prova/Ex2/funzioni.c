#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void GeneraSequenza(int S[], int A[], int indiceS, int posA, int k){
    // CONDIZIONE DI FINE: Abbiamo selezionato 6 numeri
    if(posA==6){
        StampaSequenza(A);//Sequenza creata,la stampo
        return;
    }
    //Bisogna creare la sequenza
    // CICLO: Prova tutti i numeri rimasti in S
    for (int i = indiceS; i < k ; i++){
        A[posA]=S[i];// Inserisco il numero nella posizione attuale della sestina
        GeneraSequenza(S,A,i+1,posA+1,k);//passo all'elemento successivo
        //il backtracking avvine il modo automatico, se la ricorsione non ha seguito termina ed il valore verrà sovrascritto   
    }
}


void StampaSequenza(int A[]) {
    for (int i = 0; i < 6; i++) {
        printf("%d%s", A[i], (i == 5 ? "" : " ")); 
    }
    printf("\n");
}