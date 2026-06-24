#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    Dataset data;
    //Caso di test 1:
    data.num_sequences = 1;
    data.sequences[0].index = 0;
    data.sequences[0].k = 5;
    data.sequences[0].n = 2;

    // Inizializzazione scatole e assegnazione ID originale
    int dims_test[5][2] = {{3,7}, {8,10}, {5,2}, {9,11}, {21,18}};
    for(int i = 0; i < 5; i++) {
        data.sequences[0].boxes[i].id = i + 1;
        data.sequences[0].boxes[i].dims[0] = dims_test[i][0];
        data.sequences[0].boxes[i].dims[1] = dims_test[i][1];
    }

    printf("SAMPLE INPUT:\n");
    printDataset(data);

    // 2. Ordinamento (dimensioni interne e poi boxes)
    ordinaBoxes(&data.sequences[0]);

    // 3. Inizializza DP e PARENT
    int DP[MAX_K];
    int PARENT[MAX_K];
    initDP(DP, PARENT, data.sequences[0].k);

    // 4. Calcola Sequenza
    CalcolaDP(DP, PARENT, data.sequences[0]);

    // 5. Trova la lunghezza massima
    int maxLen = 0, lastIdx = -1;
    for(int i = 0; i < data.sequences[0].k; i++) {
        if(DP[i] > maxLen) { 
            maxLen = DP[i]; 
            lastIdx = i; 
        }
    }

    // 6. Stampa risultati
    printf("\nSAMPLE OUTPUT:\n");
    printf("%d\n", maxLen); 
    stampaPercorso(lastIdx, PARENT, data.sequences[0].boxes); 
    printf("\n");
    system("pause");
    return 0;
}

/*
Complessità: O(K^2) con K=MAX_K
Ricorrenza:

*/

