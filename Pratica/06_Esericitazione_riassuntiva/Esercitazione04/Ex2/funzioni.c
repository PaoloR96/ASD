#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void InserimentoElementi(int A[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d",& A[i]);
    }
}

void InsertSort(int A[], int size){
    for (int j = 1; j < size; j++){
        int key=A[j];//elemento n+1 da confrontare
        int i=j-1; //definisco l'indice per il range di confronto
        while (i>=0 && A[i]>key){
                A[i+1]=A[i];
                i--;
        }
         A[i+1]=key;
    }
}

int RicercaBinaria(int A[], int left, int right, int key) {

    // Caso base: se l'intervallo è vuoto, l'elemento non è presente
    if (left > right)return -1;
    // Calcolo dell'indice centrale
    int mid = (left + right) / 2;
    // Se l'elemento centrale è quello cercato, ritorna l'indice
    if (A[mid] == key)return mid;

    // Se l'elemento centrale è maggiore di quello cercato,continua la ricerca nella metà sinistra dell'array
    if (A[mid] > key)
        return RicercaBinaria(A, left, mid - 1, key);
    // Altrimenti continua la ricerca nella metà destra dell'array
    else
        return RicercaBinaria(A, mid + 1, right, key);
}
