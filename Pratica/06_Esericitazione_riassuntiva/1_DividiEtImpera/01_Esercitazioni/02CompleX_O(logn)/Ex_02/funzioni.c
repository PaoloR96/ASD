#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void InsNumeri(int A[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d",&A[i]); 
    }
}
int PrimoUno(int A[], int start, int end){
    /* Caso base: intervallo vuoto, nessun 1 trovato */
    if(start > end) return -1;
    int mid = (start + end) / 2;
    /* Se troviamo un 1, controlliamo se è la prima occorrenza */
    if(A[mid] == 1){
        if(mid == 0 || A[mid - 1] == 0)
            return mid;              // mid è la prima posizione con valore 1

        return PrimoUno(A, start, mid - 1);  // altrimenti cerchiamo ancora più a sinistra
    }
    /* Se A[mid] è 0, gli 1 possono trovarsi solo a destra */
    return PrimoUno(A, mid + 1, end);
}

void ContaUno(int A[], int n){
    int p = PrimoUno(A, 0, n - 1);
    if(p == -1){
        printf("Il numero di 1 presenti è 0");
        return;
    }
    /* Il numero di 1 è la parte finale del vettore */
    printf("Il numero di 1 presenti e' %d", n - p);
}
