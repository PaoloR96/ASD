#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

int InserimentoValori(Elefante Valore[MAX]) {
    int i = 0;
    long w, s;
    while (scanf("%ld %ld", &w, &s) == 2) {
        if (i < MAX) {
            Valore[i].W = w;
            Valore[i].S = s;
            Valore[i].id = i+1; // Salvi la posizione originale
            i++;
        }
    }
    return i;
}
//Ordino per W crescente, aparità di peso, ordina per IQ Decrescente S
int comparaElefanti(const void *a, const void *b) {
    const Elefante *x = a;
    const Elefante *y = b;

    if (x->W < y->W) return -1;
    if (x->W > y->W) return 1;

    if (x->S > y->S) return -1;
    if (x->S < y->S) return 1;

    return 0;
}


void InizializzaDP(int DP[MAX],int Parent[MAX],int dim){
    for (int i = 0; i < dim; i++){
        DP[i]=1;
        Parent[i] = -1;
    }
}


//Calcolo la DP
void CalcolaDP(Elefante Valore[MAX],int DP[MAX],int Parent[MAX],int dim){
    // i scorre l'elefante corrente, j quelli precedenti
    for (int i = 1; i < dim; i++){//per ogni elemento i
        for (int j = 0; j < i; j++){ //per tutti gli elementi j precedenti a i
            // Condizione: peso strettamente crescente e IQ strettamente decrescente
            if (Valore[i].W > Valore[j].W && Valore[i].S < Valore[j].S) {
                // Aggiorna solo se trovi una catena effettivamente più lunga
                if (DP[j] + 1 > DP[i]) {
                    DP[i] = DP[j] + 1;
                    Parent[i] = j; 
                }
            }
        }
    }
}


//Trovo il percoso MAX all'interno del DP 
int TrovaMax(int DP[MAX],int dim){
    int max_len = 0;
    int max_idx = -1;
    for (int i = 0; i < dim; i++) {
        if (DP[i] > max_len) {
            max_len = DP[i];
            max_idx = i;
        }
    }
    return max_idx;
}

void StampaPercorsoRicorsivo(Elefante Valore[MAX], int Parent[MAX], int i) {
    // 1. Caso base: se l'indice è -1, la catena è finita
    if (i == -1) return;

    // 2. Risaliamo verso il "padre" (l'elefante precedente nella catena)
    StampaPercorsoRicorsivo(Valore, Parent, Parent[i]);

    // 3. Stampiamo l'ID dell'elefante corrente
    printf("%d\n", Valore[i].id); 
}