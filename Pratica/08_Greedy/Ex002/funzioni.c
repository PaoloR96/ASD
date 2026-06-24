#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header




// Funzione di confronto per ordinare i segmenti in base all'inizio (x) 
int comparaPunti(const void *a, const void *b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;
    if (p1->x != p2->x)
        return (p1->x - p2->x);
    return (p2->y - p1->y); // In caso di parità, metti prima chi arriva più lontano
}



void TrovaSegmentoM(Punto p[], int n, int M){
        // Array per memorizzare i segmenti scelti per la soluzione minima
        Punto scelti[100000]; 
        int conteggio = 0;
        int fine_copertura_attuale = 0; // Il punto fino a cui siamo arrivati a coprire
        int i = 0; // Indice per scorrere i segmenti disponibili
        int possibile = 1; // Flag per verificare se la copertura è fattibile
        while (fine_copertura_attuale<M){ // Continuiamo finché non abbiamo coperto fino a M
            int max_r = fine_copertura_attuale;
            int indice_migliore = -1;
            // LOGICA GREEDY: Tra tutti i segmenti che iniziano "prima o a" fine_copertura_attuale,
            // cerchiamo quello che ha il valore Y (R) MASSIMO.
            while (i < n && p[i].x <= fine_copertura_attuale){
                if (p[i].y>max_r){
                         max_r=p[i].y;
                         indice_migliore=i;
                }
                i++;
            }
            // Se non abbiamo trovato nessun segmento che estenda la copertura attuale
            if (indice_migliore == -1) {
                    possibile = 0;
                    break;
            }
            // Aggiungiamo il segmento migliore trovato alla nostra soluzione
            scelti[conteggio++] = p[indice_migliore];
            // Aggiorniamo il limite della nostra copertura
            fine_copertura_attuale = max_r;
        }
        // --- STAMPA DEI RISULTATI ---
        if (!possibile) {
            printf("0\n"); // Impossibile coprire [0, M] 
        } else {
            printf("%d\n", conteggio); // Numero minimo di segmenti [cite: 9]
            for (int j = 0; j < conteggio; j++) printf("%d %d\n", scelti[j].x, scelti[j].y); // Coordinate dei segmenti 
        }
}