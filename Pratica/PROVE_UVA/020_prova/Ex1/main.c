#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int B[MAX], Mediane[MAX];
    int count = 0;

    printf("SAMPLE INPUT:\n");
    while (count < MAX && scanf("%d", &B[count]) != EOF) count++;
    

    printf("\nSAMPLE OUTPUT:\n");
    for (int i = 0; i < count; i++) {
        
        // 1. Ordino i primi (i + 1) elementi
        qsort(B, i + 1, sizeof(int), Compara);

        // 2. Calcolo N (numero corrente di interi)
        int N = i + 1; 

        if (N % 2 != 0) { 
            // Caso DISPARI: la mediana è il valore centrale
            int indice_centrale = N / 2;
            Mediane[i] = B[indice_centrale];
        } else { 
            // Caso PARI: media dei due valori centrali
            int indice2 = N / 2;
            int indice1 = indice2 - 1;
            long long somma = (long long)B[indice1] + B[indice2];
            // Si stampa solo la parte intera 
            Mediane[i] = (int)(somma / 2);
        }
        
        // Stampa il valore corrente della mediana
        printf("%d\n", Mediane[i]);
    }

    printf("\n");
    system("pause"); 
    return 0;
}
/*Complessità: O(N^2*logN)*/