#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h" // Assicurati di includerlo per MAX e DividiSequenza

int main() {
    printf("SAMPLE INPUT:\n");
    int A[MAX],Risultato[MAX];
    int stato=0;
    char Buffer[2500];
    while (1){
        // 1. Inserisco la stringa
        if (fgets(Buffer, sizeof(Buffer), stdin) == NULL) break; 
        Buffer[strcspn(Buffer, "\r\n")] = '\0';
        if (strlen(Buffer) == 0) continue;
        if (strcmp(Buffer, "END") == 0) break;
        // 2. Converto la stringa in interi
        int index = 0;
        char *inizio = Buffer; // 'inizio' parte dall'inizio del Buffer
        char *fine;            // 'fine' ci servirà per capire dove finisce il numero
        while (*inizio != '\0') {
            // strtol converte la stringa in base 10 e salva in 'fine' la posizione in cui si ferma
            long numero = strtol(inizio, &fine, 10);
            // Se 'inizio' è uguale a 'fine', significa che ha letto degli spazi o non ci sono più numeri
            if (inizio == fine) break;
            A[index] = (int)numero;
            index++;
            inizio = fine;
        }
        // 3. Calcolo ed elaboro l'output per la riga corrente
        if (index > 0) {
            Risultato[stato] = DividiSequenza(A, 0, index - 1);
            stato++;
        }
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < stato; i++)printf("%d\n", Risultato[i]);
    system("pause");
    return 0;
}