#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*

N: l'intero originale a 32 bit.
L: limite inferiore dell'intervallo per la maschera M
U: limite superiore dell'intervallo per la maschera M

*/
void risolvi_mask(unsigned int n, unsigned int l, unsigned int u){
        //variabile d'appoggio
        unsigned int m = 0;
        //Parto dal bit meno significativo (31-0)
        for (int i = 31; i >=0; i--){
            // Calcoliamo il valore del bit corrente (2^i)
            unsigned int bit_corrente = (1U << i);
            
            // Caso 1: Il bit i-esimo di N è 0
            // Cerchiamo di impostare il bit i di M a 1 per massimizzare N OR M
            if (!(n & bit_corrente)) {
                // Possiamo accendere il bit in M solo se non superiamo il limite U
                if ((m | bit_corrente) <= u) m |= bit_corrente;
            }
            // Caso 2: Il bit i-esimo di N è 1
            // Poiché N OR M darebbe comunque 1, preferiamo lasciare il bit di M a 0 per ottenere il valore minimo di M.
            else {
                // Dobbiamo forzare il bit a 1 se, lasciandolo a 0, non potremmo mai raggiungere il limite inferiore L anche accendendo tutti i bit successivi.
                if ((m | (bit_corrente - 1)) < l) m |= bit_corrente;
            }
        }
        // Stampa il valore minimo di M trovato
        printf("%u\n", m);
}

