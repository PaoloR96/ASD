#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c


int main() {
    Sequenza casi[100];
    int numCasi = 0;
    char buffer[MAX];
    printf("SAMPLE INPUT:\n");
    // PRIMO WHILE: Lettura input
    // Il programma termina se legge '#'
    while (scanf("%s", buffer) && buffer[0] != '#' && numCasi < 100) {
        RiempiCasiTest(&casi[numCasi], buffer);
        numCasi++;
    }
     printf("SAMPLE OUTPUT:\n");
    // SECONDO WHILE: Elaborazione
    int j = 0;
    while (j < numCasi) {
        char attuale[MAX] = "";
        
        // Reset variabili globali per il nuovo caso
        trovato = 0;
        concluso = 0;
        // Copiamo l'input del caso corrente nella globale per TrovaSequenza
        strcpy(stringaTarget, casi[j].inputOriginale);

        TrovaSequenza(casi[j].V, attuale, casi[j].usato, 0, casi[j].dimensione);

        if (!concluso) {
            printf("No Successor\n"); // 
        }
        j++;
    }

    printf("\n");
    system("pause");
    return 0;
}
/*Complessità:O(N!)*/