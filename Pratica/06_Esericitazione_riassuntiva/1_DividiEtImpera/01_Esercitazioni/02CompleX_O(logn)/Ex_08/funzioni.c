#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header



void RiempiVettore(int A[], int size){
    for (int i = 0; i < size; i++){ 
        printf("G[%d]=",i+1);
        scanf("%d",&A[i]);
    }
}
void TrovaQuotazioni(int A[], int start,int end){
    /* Condizione di uscita */ 
    if(start >= end) return;

    /* Calcolo del punto centrale */
    int mid = (start + end)/2;

    /* Controllo se il valore è inferiore al giorno precedente */
    if(A[mid] < A[mid-1]){
        printf("Valore %d trovato al giorno %d.\n", A[mid], mid+1);
        return;  // ci fermiamo al primo decremento trovato
    }

    /* Se la diminuzione deve essere a sinistra */
    if(A[start] > A[mid]) 
        TrovaQuotazioni(A, start, mid-1);
    else
        /* Altrimenti cerco a destra */
        TrovaQuotazioni(A, mid+1, end);
}
