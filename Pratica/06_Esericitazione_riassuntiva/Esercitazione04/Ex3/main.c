#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c



int main() {
    int h = 0, d = 0;
    int A[MAX_H][MAX_D];

    printf("Definire altezza e diametro della pila di pancake: ");
    scanf("%d %d", &h, &d);

    if (h < 1 || h > MAX_H || d < 1 || d > MAX_D) {
        printf("Valori non validi!\n");
        return 0;
    }

    for (int i = 0; i < h; i++) {
        printf("Inserire i diametri della riga %d: ", i+1);
        InserisciElementi(A[i], d);
       //printf("\n");
    }

    // Stampa della pila inserita
    //printf("Pila inserita:\n");
    //StampaPila(A,h,d);
    OrdinaElementi(A,h,d);
    

    system("pause");
    return 0;
}

