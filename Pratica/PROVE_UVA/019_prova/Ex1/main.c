#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    Blocco B[MAX];
    int Sequenza[MAX], Risultato[MAX], index = 0;
    Query Q[MAX];
    int N = 0, q = 0;
    int total_queries = 0; // Per tenere traccia del totale dei risultati stampati

    printf("SAMPLE INPUT:\n");
    while (index < MAX) {
        if (scanf("%d", &N) != 1 || N == 0) break;
        scanf("%d", &q);

        // 1. Inserimento Sequenza
        for (int i = 0; i < N; i++) scanf("%d", &Sequenza[i]);

        // 2. Inserimento Query
        for (int i = 0; i < q; i++) scanf("%d %d", &Q[i].start, &Q[i].end);

        // 3. Creazione Blocco e Segment Tree
        int ultimo_id = CreazioneMappa(B, Sequenza, N);
        buildSegmentTree(B, 1, 0, ultimo_id);

        // 4. Calcoliamo le frequenze per ogni query
        for (int i = 0; i < q; i++) {
            // Passiamo l'ultimo_id come richiesto dalla nuova firma
            Risultato[total_queries++] = CalcolaQuery(B, Sequenza, Q[i].start, Q[i].end, ultimo_id);
        }
        index++;
    }

    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < total_queries; i++) {
        printf("%d \n", Risultato[i]);
    }

    system("pause");
    return 0;
}

/*Complessità:O((n+q)*logn)*/