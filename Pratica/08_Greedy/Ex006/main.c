#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

#define MAX_TEST_CASES 100 // Puoi regolare questo valore

int main() {
    int L, G;
    int risultati[MAX_TEST_CASES]; // Array per memorizzare i risultati (G-used o -1)
    int num_casi = 0;

    // --- FASE 1: INSERIMENTO VALORI (INPUT) ---
    while(scanf("%d %d", &L, &G) == 2 && (L != 0 || G != 0)) {
        Station stations[MAXG];
        Station sequenza[MAXG];

        for(int i = 0; i < G; i++) {
            scanf("%d %d", &stations[i].left, &stations[i].right);
        }

        // Calcoliamo subito il risultato per questo caso e lo salviamo
        CalcolaIntervalli(stations, G, sequenza, L);
        qsort(sequenza, G, sizeof(Station), ComparaValori);
        
        // Modifica: invece di stampare in CalcolaCopertura, 
        // usiamo una funzione che RESTITUISCE il numero (G-used o -1)
        risultati[num_casi] = OttieniRisultatoCopertura(sequenza, G, L);
        num_casi++;

        if(num_casi >= MAX_TEST_CASES) break; // Protezione array
    }

    // --- FASE 2: STAMPA DEGLI OUTPUT ---
    printf("\n--- RISULTATI ---\n");
    for(int i = 0; i < num_casi; i++) {
        printf("%d\n", risultati[i]);
    }

    system("pause");
    return 0;
}
/*Complessità:O(GlogG)*/