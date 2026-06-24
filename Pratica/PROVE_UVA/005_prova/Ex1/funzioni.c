#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funzioni.h"  // Include il file header
int compare(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return x - y;
}

Dati AggiungiZero(Dati dataset, int numeroZero) {
    int tmp[MAX_SAMPLES];
    // Copio i primi numeroZero zeri
    for (int i = 0; i < numeroZero; i++)tmp[i] = 0;
    // Copio i campioni originali dopo gli zeri
    for (int i = 0; i < dataset.S; i++) tmp[i + numeroZero] = dataset.masses[i];
    // Aggiorno S per includere i nuovi elementi
    dataset.S += numeroZero;
    // Ricopio tutto nel vettore della struct
    for (int i = 0; i < dataset.S; i++) dataset.masses[i] = tmp[i];
    return dataset;
}


double Somma(Dati dataset) {
    double totale = 0.0;
    for (int i = 0; i < dataset.S; i++) {
        totale += dataset.masses[i];
    }
    return totale;
}



double CalcolaSbilanciamento(Dati dataset, double AM) {
    double sbilanciamento_totale = 0.0;    
    // Iteriamo per il numero di CAMERE (C)
    for (int i = 0; i < dataset.C; i++) {
        int j = (2 * dataset.C) - 1 - i; // Indice del campione accoppiato
        // Calcoliamo la massa della camera i-esima
        double CM_i = dataset.masses[i] + dataset.masses[j];
        // Sommiamo il valore assoluto della differenza (utilizzando fabs per i double)
        sbilanciamento_totale += fabs(CM_i - AM);
    }
    return sbilanciamento_totale;
}