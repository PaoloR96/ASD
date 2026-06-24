#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
int Ldp[K];
int Pdp[K];
void OrdinaScatole(Scatola lista[], int k, int n) {  
    for (int i = 0; i < k; i++) {
        // Ordiniamo le n dimensioni della scatola i-esima
        qsort(lista[i].dimensioni, n, sizeof(int), confronta_dimensioni);
    }
}

int confronta_dimensioni(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

bool IsCompatibile(Scatola A, Scatola B, int n) {
    for (int i = 0; i < n; i++) {
        // Se anche una sola dimensione di A non è STRETTAMENTE minore di B,
        // allora A non può stare in B.
        if (A.dimensioni[i] >= B.dimensioni[i]) {
            return false;
        }
    }
    return true; 
}

void InitDp(int Ldp[K],int Pdp[K],int k){
    /*Inizializzo Ldp*/
    for (int i = 0; i < k; i++)Ldp[i]=1;
    /*Inizializzo Pdp*/
    for (int i = 0; i < k; i++)Pdp[i]=-1;    
}

void CalcolaSequenzaMassima(Scatola lista[], int k, int n){
    //Inizializzo Ldp e Pdp
    InitDp(Ldp,Pdp,k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            // Se la scatola j si incastra in i
            if (IsCompatibile(lista[j], lista[i], n)) {
                // Se estendere la catena di j è vantaggioso
                if (Ldp[j] + 1 > Ldp[i]) {
                    Ldp[i] = Ldp[j] + 1;
                    Pdp[i] = j;
                }
            }
        }
    }
}
void StampaPercorso(int indice, Scatola lista[]) {
    // Caso base: se non c'è un predecessore (Pdp è -1), ci fermiamo 
    if (indice == -1) return;

    // Chiama ricorsivamente sul predecessore PRIMA di stampare
    StampaPercorso(Pdp[indice], lista);

    // Stampa l'ID originale (memorizzato durante l'input) 
    // Aggiungi uno spazio se necessario per separare i numeri
    printf("%d ", lista[indice].id);
}