#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int array_V[MAX_TESTS];
    int array_n[MAX_TESTS];
    int matrice_Monete[MAX_TESTS][MAX_MONETE]; 
    
    int num_tests = 0;
    char riga[1024];
    printf("SAMPLE INPUT:\n");
    while (fgets(riga, sizeof(riga), stdin) != NULL) {
        
        // Se la riga inizia con "END", interrompiamo il ciclo
        if (strncmp(riga, "END", 3) == 0) break;

        // Usiamo un puntatore per scorrere la riga man mano che leggiamo i numeri
        char *puntatore = riga;
        int caratteri_letti = 0;
        
        // Estraiamo V e n. %n salva in 'caratteri_letti' il numero di caratteri consumati
        sscanf(puntatore, "%d %d%n", &array_V[num_tests], &array_n[num_tests], &caratteri_letti);
        
        // Avanziamo il puntatore della stringa oltre i primi due numeri
        puntatore += caratteri_letti;
        
        // Cicliamo per estrarre tutti gli n valori delle monete
        for (int i = 0; i < array_n[num_tests]; i++) {
            sscanf(puntatore, "%d%n", &matrice_Monete[num_tests][i], &caratteri_letti);
            puntatore += caratteri_letti; // Avanziamo il puntatore al numero successivo
        }
        
        num_tests++;
    }
    printf("SAMPLE OUTPUT:\n");
    int limite=0;
    for (int i = 0; i < num_tests; i++) {
        int monetaMax=ValoreMax(array_n[i],matrice_Monete[i]);
        limite=array_V[i]+monetaMax;
        InitDP(DP,limite);
        int risultato = CalcolaDP(DP, array_V[i],limite, array_n[i], matrice_Monete[i]);
        printf("%d\n", risultato);
        limite=0;
    }
    system("pause");
    return 0;
}


/*
Complessità:O(numTest*numMonete*limiteV)

Questo esercizio appartiene al problema del Coin Change Problem, noto
anche come Zaino Illimitato.
Nel problema classico si richiede di trovare il numero minimo di monete
necessario per ottenere esattamente un importo V.
In questa variante, invece, l’obiettivo cambia leggermente: bisogna
trovare il numero minimo di monete per raggiungere l’importo esatto V
oppure il più piccolo importo strettamente maggiore di V.
Per risolverlo, il primo passo consiste nel determinare un limite
superiore che permetta di estendere la ricerca oltre V. Tale limite è
dato da: limite = V + monetaMax

dove monetaMax rappresenta il valore della moneta più grande
disponibile.

Una volta completata la DP, si analizzano gli importi a partire
da V fino al limite individuato, così da trovare il primo importo
raggiungibile maggiore o uguale a V e il numero minimo di monete
associato.


*/