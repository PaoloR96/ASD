#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*VAR GLOBALE*/
int DP[MAX_C][MAX_B];
// Inizializziamo tutta la tabella a 0 (nessuna spesa possibile all'inizio)
void InitDP(int DP[MAX_C][MAX_B],int num_classi,int budget){
    for (int i = 0; i <= num_classi; i++) {
        for (int j = 0; j <= budget; j++) {
            DP[i][j] = 0;
        }
    }
}
int CalcolaSequenza(CasoTest ct,int DP[MAX_C][MAX_B]){
    //Caso base:Con 0 classi, l'unica spesa possibile è 0
    DP[0][0]=1;
    //Ricorrenza:
    for (int i = 0; i < ct.num_classi; i++){//per ogni classi i
        int numeroProdotti=ct.num_prodotti[i];
        // Per ogni spesa 'b' che è possibile raggiungere
        for (int b = 0; b <= ct.budget; b++){
            if (DP[i][b]==1){
                //Provo ad aggiungere un prodotto alla classe corrente
                for (int k = 0; k <numeroProdotti ; k++){
                    int prezzo_prodotto = ct.prezzi[i][k];
                    // Se la nuova spesa totale non supera il budget, segnala come possibile
                    if (b+prezzo_prodotto<=ct.budget){
                        DP[i+1][b+prezzo_prodotto]=1;
                    }
                }
            }  
        } 
    }
    // Cerchiamo nell'ultima riga la spesa più alta possibile (partendo dal budget B)
    for (int j = ct.budget; j >= 0; j--) {
        if (DP[ct.num_classi][j] == 1) return j; // Abbiamo trovato la spesa massima!
        
    }
    return -1; // Se non troviamo nulla di possibile, ritorniamo -1   
}

void RiempiClasse(CasoTest *ct, int index) {
    // 1. Leggiamo quanti prodotti la classe index (M)

    int num_modelli;
    scanf("%d", &num_modelli); 
    ct->num_prodotti[index] = num_modelli;

    // 2. Leggiamo i prezzi dei modelli per questa classe
    for (int i = 0; i < num_modelli; i++) scanf("%d", &ct->prezzi[index][i]);
}