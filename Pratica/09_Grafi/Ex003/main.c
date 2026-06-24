#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    char start[5], end[5];

    // Messaggio iniziale richiesto dal tuo stile
    printf("SAMPLE INPUT:\n");

    /* Il ciclo continua finché scanf riesce a leggere due stringhe.
    */
    while (scanf("%s %s", &start, &end) != EOF) {
        
        // Calcoliamo il risultato usando il motore BFS
        int mosse = bfs(start, end);

        // Stampiamo l'output nel formato esatto richiesto dal problema
        printf("To get from %s to %s takes %d knight moves.\n", start, end, mosse);
    }

    system("pause");
    return 0;
}
/*Complessità:O(E+V) se avessi usato un minHeap avrei avuto O(ElogV+VlogV)*/