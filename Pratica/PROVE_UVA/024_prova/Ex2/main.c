#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");

    // Array:
    // k[i] = numero di elementi della sequenza i-esima
    // S[i][j] = elementi della sequenza i-esima
    // R = array risultato (dimensione 6, presumibilmente per combinazioni)
    int k[100], S[100][100], R[6];

    int ktmp = 0;   // Variabile temporanea per leggere la dimensione
    int index = 0;  // Numero di sequenze lette

    // Lettura input
    while (index < 100) {
        scanf("%d", &ktmp);
        // Se l'utente inserisce 0, termina l'input
        if (ktmp == 0) break;
        k[index] = ktmp;
        // Lettura degli elementi della sequenza
        for (int i = 0; i < ktmp; i++) scanf("%d", &S[index][i]);
        //passo al caso di test successivo
        index++;
    }

    printf("SAMPLE OUTPUT:\n");

    for (int i = 0; i < index; i++) {
        for (int j = 0; j < 6; j++) R[j] = 0;
        GeneraSequenza(S[i], R, 0, 0, k[i]);
    }
    system("pause");
    return 0;
}

/*
Complessità: O(k!/6!(k-6)!)

*/