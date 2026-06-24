#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"  // Include il file header

void CalcolaSottoSequenza(char Stringa1[], char Stringa2[]) {
    int dim1 = strlen(Stringa1);
    int dim2 = strlen(Stringa2);
    int i = 0; // indice per s
    int j = 0; // indice per t

    // Scorriamo t finché non finisce o finché non troviamo tutto s
    while (i < dim1 && j < dim2) {
        if (Stringa1[i] == Stringa2[j]) {
            i++; // Trovato carattere di s, passiamo al prossimo
        }
        j++; // Avanziamo sempre in t
    }

    // Se i ha raggiunto dim1, s è una sottosequenza
    if (i == dim1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}