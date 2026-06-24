#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++) scanf("%d",&A[i]);
}

int TrovaValore(int A[], int start,int end){
    /*condizione di uscita*/
    if(start==end)return -1;
    /*condizione ricorsiva*/
    int mid=(start+end)/2;
    if (mid > start && A[mid] == A[mid - 1])return A[mid];
    if (mid < end && A[mid] == A[mid + 1])return A[mid];

    // Ricorsione su entrambi i lati
    int left = TrovaValore(A, start, mid);
    if (left != -1) return left;
    return TrovaValore(A, mid + 1, end);
}