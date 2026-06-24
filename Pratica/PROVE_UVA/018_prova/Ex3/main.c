 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    char S1[MAX], S2[MAX];
    int Risultati[MAX];
    int index = 0;
     printf("SAMPLE INPUT:\n");
    // Legge le stringhe riga per riga finché non finisce l'input
    while (index < MAX && fgets(S1, MAX, stdin) != NULL) {
        if (fgets(S2, MAX, stdin) == NULL) break;

        // Rimuove il carattere 'invio' (\n) catturato da fgets
        S1[strcspn(S1, "\n")] = 0;
        S2[strcspn(S2, "\n")] = 0;

        Risultati[index] = CalcolaSequenza(S1, S2);
        index++;
    }

    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++) {
        printf("%d\n", Risultati[i]); 
    }
    system("pause");

    return 0;
}
/*
Complessità:O(n*m)
Ricorrenza: DP(i)(j) ==> Se s(i-1)==s(j-1) allora   DP(i)(j)=1+DP(i-1)(j-1)
                        altrimenti se sono diversi  DP(i)(j)=max(DP(i-1)(j),DP(i-1)(j))
*/
