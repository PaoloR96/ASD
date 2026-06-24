#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int confrontaPunti(const void *a, const void *b) {
    Punto *pa = (Punto *)a;
    Punto *pb = (Punto *)b;
    if (pa->x != pb->x) return pa->x - pb->x;
    return pa->y - pb->y;
}

// Funzione interna per ordinare le coppie Y
int confrontaCoppie(const void *a, const void *b) {
    CoppiaY *ca = (CoppiaY *)a;
    CoppiaY *cb = (CoppiaY *)b;
    if (ca->y1 != cb->y1) return ca->y1 - cb->y1;
    return ca->y2 - cb->y2;
}

int GeneraTutteLeCoppie(Punto punti[], int n, CoppiaY tutteLeCoppie[]) {
    int k = 0; // Indice per l'array globale delle coppie (segmenti verticali)
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        // Identifica un blocco di punti che appartengono alla stessa colonna (stessa X)
        while (j < n && punti[j].x == punti[i].x) {
            /* Per ogni nuovo punto 'j' trovato nella colonna, crea una coppia 
               con TUTTI i punti precedenti 'm' della stessa colonna. 
               Questo genera tutte le combinazioni possibili di segmenti verticali. */
            for (int m = i; m < j; m++) {
                tutteLeCoppie[k].y1 = punti[m].y; // Estremo inferiore del segmento
                tutteLeCoppie[k].y2 = punti[j].y; // Estremo superiore del segmento
                k++; // Incrementa il numero totale di segmenti trovati nel piano
            }
            j++;
        }
        
        /* Salta l'indice 'i' alla fine del blocco appena processato. 
           j-1 perché il ciclo for esterno farà i++ */
        i = j - 1;
    }
    return k; // Ritorna il numero totale di coppie (K) caricate nell'archivio
}

int ContaRettangoli(CoppiaY tutteLeCoppie[], int totaleCoppie) {
    if (totaleCoppie == 0) return 0;

    /* Ordina l'archivio delle coppie. 
       Questo mette segmenti verticali identici (stessa y1 e y2) uno dopo l'altro. */
    qsort(tutteLeCoppie, totaleCoppie, sizeof(CoppiaY), confrontaCoppie);

    int rettangoliTotali = 0;
    int k = 1; // Conta quante volte appare consecutivamente lo stesso segmento

    for (int i = 1; i <= totaleCoppie; i++) {
        /* Se il segmento corrente è uguale al precedente, 
           appartengono alla stessa "famiglia" di segmenti paralleli. */
        if (i < totaleCoppie && tutteLeCoppie[i].y1 == tutteLeCoppie[i-1].y1 &&tutteLeCoppie[i].y2 == tutteLeCoppie[i-1].y2) {
            k++;
        } else {
            /* Se abbiamo trovato 'k' segmenti identici su 'k' ascisse diverse, 
               il numero di rettangoli formabili è dato dalle combinazioni di k su 2: 
               Formula: k * (k - 1) / 2 */
            rettangoliTotali += (k * (k - 1)) / 2;
            k = 1; // Reset per iniziare a contare il prossimo tipo di segmento
        }
    }
    return rettangoliTotali;
}