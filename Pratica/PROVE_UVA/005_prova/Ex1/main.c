#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    // Caricamento dati Set #1: 2 camere, 3 campioni (6, 3, 8) 
    Dati dataset = {2, 3, {6, 3, 8}};

    // 1: Bilanciamento degli elementi (2*C = 4, quindi serve 1 zero)
    int numeroZero = 2 * dataset.C - dataset.S;
    dataset = AggiungiZero(dataset, numeroZero);

    // 2: Ordinamento (Risultato: 0, 3, 6, 8)
    qsort(dataset.masses, dataset.S, sizeof(int), compare);

    // 3: Calcolo AM (Somma 17 / 2 camere = 8.5) 
    double AM = Somma(dataset) / dataset.C;

    // 4: Calcolo Sbilanciamento
    double sbil = CalcolaSbilanciamento(dataset, AM);

    // 5: Output formattato 
    printf("Set #1\n");
    for (int i = 0; i < dataset.C; i++) {
        int j = (2 * dataset.C) - 1 - i;
        printf(" %d:", i);
        if (dataset.masses[i] > 0) printf(" %d", dataset.masses[i]);
        if (dataset.masses[j] > 0) printf(" %d", dataset.masses[j]);
        printf("\n");
    }
    printf("IMBALANCE = %.5f\n\n", sbil);

    system("pause");
    return 0;
}
/*Complessità:O(Slog S) con S numero di samples*/