#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void StampaSequenza(int Insieme[MAX], int dim) {
    for (int i = 0; i < dim; i++)printf("%d ", Insieme[i]);
    printf("\n");
}

void Risolvi(int Insieme [MAX], int Postirestanti, int Hresiduo,int pos){
    // 1. CONDIZIONE DI USCITA (Caso Base)
    // Se non ci sono più posti da riempire, abbiamo completato una stringa
    if(Postirestanti==0){
        StampaSequenza(Insieme,4);
        return;
    }
    // 2. LOGICA DI BACKTRACKING
    // In ogni posizione 'pos', dobbiamo decidere se mettere 0 oppure 1.
    // SCELTA A: Prova a mettere 0
    // Posso mettere uno 0 solo se i posti rimanenti sono più degli 1 necessari
    if(Postirestanti>Hresiduo){
            Insieme [pos]=0;
            Risolvi(Insieme,Postirestanti-1,Hresiduo,pos+1);
    }
    // SCELTA B: Prova a mettere 1
    // Posso mettere un 1 solo se ne ho ancora a disposizione
    if (Hresiduo>0){
            Insieme [pos]=1;
            Risolvi(Insieme,Postirestanti-1,Hresiduo-1,pos+1);
    }
        
}
    


