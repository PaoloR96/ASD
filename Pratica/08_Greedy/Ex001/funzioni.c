#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

int ComparaValori(const void *a,const void *b){
    return(*(int*)a-*(int*)b);
}


// Funzione per risolvere il problema dell'attraversamento del ponte
void RisolviPercorso(int t[MAX], int n) {
    int tempo_totale = 0;
    int temp_n = n;

    // --- FASE 1: CALCOLO DEL TEMPO TOTALE ---
    // Dobbiamo calcolare il tempo prima di stampare i movimenti perché il 
    // totale deve apparire sulla prima riga dell'output.
    while (temp_n > 3) {
        // Opzione 1: Il più veloce (t[0]) accompagna i due più lenti uno alla volta.
        // Formula: (Z + A) + (Y + A) -> t[n-1] + t[0] + t[n-2] + t[0]
        int opt1 = t[temp_n - 1] + t[0] + t[temp_n - 2] + t[0];

        // Opzione 2: I due più veloci (t[0], t[1]) preparano il terreno per i due più lenti.
        // Formula: (B + A) + (Z + B) -> t[1] + t[0] + t[temp_n-1] + t[1]
        int opt2 = t[1] + t[0] + t[temp_n - 1] + t[1];

        // Scegliamo la strategia più economica per questo turno
        if (opt1 < opt2) tempo_totale += opt1;
        else tempo_totale += opt2;

        // Abbiamo portato 2 persone oltre il ponte, riduciamo il gruppo rimanente
        temp_n -= 2;
    }

    // Gestione dei casi base rimasti sulla sponda di partenza (n <= 3)
    if (temp_n == 3) {
        // Con 3 persone: (A+Z) + A + (A+B) -> t[2] + t[0] + t[1]
        tempo_totale += t[2] + t[0] + t[1];
    } else if (temp_n == 2) {
        // Con 2 persone: (A+B) -> t[1]
        tempo_totale += t[1];
    } else if (temp_n == 1) {
        // Con 1 persona: (A) -> t[0]
        tempo_totale += t[0];
    }

    // STAMPA IL RISULTATO FINALE (Prima riga dell'output) [cite: 13]
    printf("%d\n", tempo_totale);

    // --- FASE 2: STAMPA DELLA STRATEGIA (I MOVIMENTI) ---
    // Ripetiamo la logica, ma stavolta stampiamo chi attraversa[cite: 14, 15].
    temp_n = n;
    while (temp_n > 3) {
        int opt1 = t[temp_n - 1] + t[0] + t[temp_n - 2] + t[0];
        int opt2 = t[1] + t[0] + t[temp_n - 1] + t[1];

        if (opt1 < opt2) {
            // Strategia A: Andata A+Z, Ritorno A, Andata A+Y, Ritorno A
            printf("%d %d\n%d\n", t[0], t[temp_n - 1], t[0]);
            printf("%d %d\n%d\n", t[0], t[temp_n - 2], t[0]);
        } else {
            // Strategia B: Andata A+B, Ritorno A, Andata Y+Z, Ritorno B
            printf("%d %d\n%d\n", t[0], t[1], t[0]);
            printf("%d %d\n%d\n", t[temp_n - 2], t[temp_n - 1], t[1]);
        }
        temp_n -= 2;
    }

    // Gestione dell'output per le ultime persone rimaste 
    if (temp_n == 3) {
        // A e Z vanno, A torna, A e B vanno
        printf("%d %d\n%d\n%d %d\n", t[0], t[2], t[0], t[0], t[1]);
    } else if (temp_n == 2) {
        // A e B vanno e finisce
        printf("%d %d\n", t[0], t[1]);
    } else if (temp_n == 1) {
        // Solo A attraversa
        printf("%d\n", t[0]);
    }
}