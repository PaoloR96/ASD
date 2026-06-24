#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++)scanf("%d",&A[i]);
}
int DefinisciShift(int A[],int low,int high){
    // caso base: vettore già ordinato in questo intervallo → il minimo è in low
    if (A[low] <= A[high])return low;
    int mid = (low + high) / 2;
     // Controllo se mid è punto di rottura
    if(mid<high && A[mid]>A[mid+1])return mid+1;
     // Controllo se mid-1 è punto di rottura
    if (mid > low && A[mid - 1] > A[mid])return mid;
    // Ricorsione a sinistra
    if (A[mid] >= A[low])return DefinisciShift(A, mid + 1, high);
    // Ricorsione a destra
    return DefinisciShift(A, low, mid - 1);     
}