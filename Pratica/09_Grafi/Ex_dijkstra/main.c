#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int adiacenza[MAX_NODI][MAX_NODI];

int main() {
    int n = 5; // Grafo con 5 nodi (0, 1, 2, 3, 4)

    // Inizializziamo la matrice con INF (nessun collegamento)
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            adiacenza[i][j] = INT_MAX;

    // Definiamo i collegamenti manualmente
    // Esempio: Nodo 0 collegato a 1 (peso 10) e a 2 (peso 3)
    adiacenza[0][1] = 10;
    adiacenza[0][2] = 3;
    adiacenza[2][1] = 1;  
    adiacenza[1][3] = 2;
    adiacenza[2][3] = 8;
    adiacenza[3][4] = 5;
    
    int partenza = 0;
    int arrivo = 4;

    int costoMinimo = dijkstra(partenza, arrivo, n, adiacenza);

    if (costoMinimo != -1) {
        printf("Il percorso minimo da %d a %d e': %d\n", partenza, arrivo, costoMinimo);
    } else {
        printf("Nessun percorso possibile.\n");
    }

    system("pause");
    return 0;
}

/*In questo caso la sequenza sarà:0->2->1->3->4, pertanto il costo minimo sarà: 11*/

/*Complessità: O(V^2)*/