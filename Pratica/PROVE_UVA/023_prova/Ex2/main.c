#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"

int main() {
    int M[MAX][MAX];
    
    printf("SAMPLE INPUT:\n"); // Nota: UVa non vuole questa stringa in output
    RiempiMatrice(M);
    
    // TROVA LA POSIZIONE DELLO SPAZIO VUOTO (2)
    Coordinate c = TrovaPosizioneLibera(M);
    
    // ERRORE PRECEDENTE: minMosseGlobal veniva messo a 11 DOPO la funzione.
    // Deve essere inizializzato PRIMA affinché la funzione possa aggiornarlo.
    minMosseGlobal = 11; 

    // AVVIO DEL CALCOLO
    CalcolaNumeroMinSequenze(M, c.x, c.y, 0);

    printf("SAMPLE OUTPUT:\n"); // Nota: UVa non vuole questa stringa in output
    
    // CONTROLLO DEL RISULTATO
    // Se è rimasto 11, significa che non è stata trovata una soluzione in <= 10 mosse.
    if (minMosseGlobal > 10) {
        printf("Unsolvable in less than 11 move(s).\n");
    } else {
        printf("Solvable in %d move(s).\n", minMosseGlobal);
    }

     system("pause"); 
    return 0;
}

/*Complessità :O(8^d)*/