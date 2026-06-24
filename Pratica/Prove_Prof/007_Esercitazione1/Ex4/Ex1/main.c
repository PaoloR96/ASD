#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header con la definizione di Segmento e MAX

int main() {
    int num_test;
    printf("SAMPLE INPUT:\n");
    // Legge il numero di casi di test totali
    if (scanf("%d", &num_test) != 1) return 0;
    static Segmento S[MAX];
    for (int t = 0; t < num_test; t++) {
        int M;
        // Legge il valore M per il caso di test corrente
        if (scanf("%d", &M) != 1) break;
        // 1. Inserimento dei segmenti (ritorna il numero 'n' di elementi letti)
        int n = InserisciSegmento(S);
        // 2. Ordinamento dei segmenti tramite la tua funzione ComparaValori
        qsort(S, n, sizeof(Segmento), ComparaValori);
        // 3. Formattazione dell'output: stampa una riga vuota *prima* di ogni 
        // caso di test successivo al primo, come richiesto dalle specifiche
        if (t > 0) printf("\n");
        printf("SAMPLE OUTPUT CASO %d:\n",t+1);
        // 4. Esecuzione della logica greedy e stampa del risultato
        CalcolaSequenza(S, M, n);
    }
    system("PAUSE");
    return 0;
}

/*
Complessità:O(N log N)

Per quanto riguarda la complessità, a un primo impatto potrebbe sembrare O(N²) a causa della presenza dei cicli. 
Tuttavia, la variabile i non viene mai reimpostata né riportata all’inizio, 
quindi la fase di ricerca complessivamente richiede un tempo lineare O(N). 
Di conseguenza, l’elemento che incide maggiormente sulle prestazioni complessive è l’algoritmo di ordinamento qsort, 
portando la complessità totale a O(N log N).


*/