#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int TrovaFirstUno(int A[], int left, int right) {
    /* Caso base: intervallo vuoto → 1 non trovato */
    if (left > right)return -1;
    /* Punto centrale dell'intervallo */
    int mid = (left + right) / 2;
    /* Caso in cui A[mid] == 1:
       potrebbe essere il primo 1, ma devo controllare se ce ne sono altri più a sinistra */
    if (A[mid] == 1) {
        // Cerco ancora più a sinistra
        int pos = TrovaFirstUno(A, left, mid - 1);

        // Se a sinistra non ho trovato nulla, mid è davvero il primo
        if (pos == -1)
            return mid;
        else
            return pos;
    }

    /* Se A[mid] < 1, allora gli 1 possono trovarsi solo a destra */
    else if (A[mid] < 1) {
        return TrovaFirstUno(A, mid + 1, right);
    }

    /* Se A[mid] > 1, gli 1 possono trovarsi solo a sinistra */
    else {
        return TrovaFirstUno(A, left, mid - 1);
    }
}


int TrovaLastUno(int A[], int left, int right) {
    /* Caso base: intervallo vuoto → 1 non trovato */
    if (left > right)return -1;
    /* Punto centrale dell'intervallo */
    int mid = (left + right) / 2;
    /* Caso in cui A[mid] == 1:
       potrebbe essere l'ultimo 1, ma devo controllare se ce ne sono altri più a dx */
    if (A[mid] == 1) {
        // Cerco ancora più a destra
        int pos = TrovaLastUno(A,mid + 1,right);

        // Se a dx non ho trovato nulla, mid è davvero l'ultimo
        if (pos == -1)
            return mid;
        else
            return pos;
    }

    /* Se A[mid] < 1, allora gli 1 possono trovarsi solo a destra */
    else if (A[mid] < 1) {
        return TrovaLastUno(A, mid + 1, right);
    }

    /* Se A[mid] > 1, gli 1 possono trovarsi solo a sinistra */
    else {
        return TrovaLastUno(A, left, mid - 1);
    }
}


void contaOccorrenzeUno(int A[], int n) {

    /* Trovo il primo 1 nel vettore */
    int first = TrovaFirstUno(A, 0, n - 1);
    /* Se non esistono 1 nel vettore, esco */
    if (first == -1) {
        printf("Nessuna occorrenza del valore 1.\n");
        return;
    }
    /* Trovo l'ultimo 1 nel vettore */
    int last = TrovaLastUno(A, 0, n - 1);

    /* Stampo il numero totale di 1 */
    printf("Numero occorrenze del valore 1: %d\n", last - first + 1);
}
