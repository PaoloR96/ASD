#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int n = 5;   // numero scatole [cite: 31]
    int d = 2;   // numero dimensioni [cite: 31]
    
    // Il tuo input specifico
    Scatola scatole[5] = {
        {1, {3, 7}},
        {2, {8, 10}},
        {3, {5, 2}},
        {4, {9, 11}},
        {5, {21, 18}}
    };

    // 1. Fase di Normalizzazione: ordina internamente le dimensioni di ogni scatola
    // La scatola {5, 2} diventa {2, 5}
    OrdinaScatole(scatole, n, d);

    // 2. Calcolo della sequenza tramite Programmazione Dinamica
    CalcolaSequenzaMassima(scatole, n, d);

    // 4. Ricerca del Massimo: trova la catena più lunga
    int max_lunghezza = 0;
    int indice_migliore = 0;
    
    for (int i = 0; i < n; i++) {
        if (Ldp[i] > max_lunghezza) {
            max_lunghezza = Ldp[i];
            indice_migliore = i;
        }
    }

    // 5. Output dei Risultati
    printf("%d\n", max_lunghezza); 
    
    // Stampa il percorso ricostruito (ID originali nell'ordine corretto)
    StampaPercorso(indice_migliore, scatole);
    printf("\n");
  
    system("PAUSE");
    return 0;
}
/*Complessità

La complessità totale è O(k^2 * n + k * n log n)

k * n log n:
indica l'ordinamento interno delle n dimensioni per ognuna delle k scatole tramite qsort.

k^2 * n:
rappresenta il doppio ciclo della Programmazione Dinamica (confronto di ogni coppia di scatole) 
moltiplicato per il costo n della funzione IsCompatibile.


Ricorrenza:L(i) = 1 + max({ L(j) | la scatola j si incastra nella scatola i })

*/

