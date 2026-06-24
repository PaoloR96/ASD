#include <stdio.h>
#include "funzioni.h"

/*
Legge una sequenza di numeri
Complessità:O(n)
*/
void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &A[i]);
    }
}


/*
Conta le inversioni tra due metà dell'array
Complessità:O(n)
*/
int Merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + 1 + i];

    int i = 0, j = 0, k = left;
    int swaps = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
            swaps += (n1 - i); // tutte le inversioni rimanenti in L
        }
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];

    return swaps;
}

/*
Logica del MergeSort
Complessità:O(n*logn)
*/
int MergeSort(int A[], int left, int right) {
    int swaps = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        swaps += MergeSort(A, left, mid);
        swaps += MergeSort(A, mid + 1, right);
        swaps += Merge(A, left, mid, right);
    }
    return swaps;
}

/*
Calcola gli swap per più sequenze
Complessità:O(∑ n[i] log n[i])
*/
void CalcolaSwap(int A[][SIZE], int n[], int dim) {
    for (int i = 0; i < dim; i++) {
        int swap = MergeSort(A[i], 0, n[i] - 1);
        printf("%d\n", swap);
    }
}
