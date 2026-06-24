#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void GeneraSequenza(int S[],int n){
    int usato[n];
    int seq[n];
    for(int i=0;i<n;i++)usato[i]=0;
    BackTracking(S,seq,usato,n,0);
    
}
void BackTracking(int S[], int seq[], int usato[], int n, int pos){
    /*Caso base: se la condizione è verificata,allora è stata completata la sequenza*/
    if (pos == n){
        StampaSequenza(seq, n); // stampo la permutazione completa
        return;                  // esco dalla funzione (ritorno all'ultimo livello di ricorsione)
    }

    /*Caso ricorsivo:Ciclo su tutti gli elementi dell'insieme S*/
    for (int i = 0; i < n; i++){
        // Controllo se l'elemento S[i] è già stato usato nella sequenza corrente
        if (!usato[i]){
            seq[pos] = S[i];    // metto S[i] nella posizione corrente della sequenza
            usato[i] = 1;       // segno S[i] come "usato" per non ripeterlo

            // Richiamo ricorsivo per riempire la prossima posizione
            BackTracking(S, seq, usato, n, pos + 1);

            // Backtracking: tolgo S[i] dalla posizione corrente e lo libero
            // per poterlo usare in altre permutazioni
            usato[i] = 0;
        }
    }
}




void StampaSequenza(int S[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", S[i]);
    }
    printf("]\n");
}

