#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Stampa l'array
void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Genera numeri casuali [0..100]
void GeneraNumeri(int A[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 101;
    }
}

// Trova il minimo in un intervallo [start..end]
int TrovaMinimo(int A[], int start, int end) {
    int min = INT_MAX;
    for (int i = start; i <= end; i++) {
        if (A[i] < min) min = A[i];
    }
    return min;
}

// Trova il massimo in un intervallo [start..end]
int TrovaMassimo(int A[], int start, int end) {
    int max = INT_MIN;
    for (int i = start; i <= end; i++) {
        if (A[i] > max) max = A[i];
    }
    return max;
}

// Funzione Divide et Impera per min(A[j]-A[i]) con i <= j
int CalcolaMinMax(int A[], int start, int end) {
    // Caso base: singolo elemento (la differenza minima e' 0 per A[i]-A[i])
    if (start >= end) return 0;
    int mid = (start + end) / 2;
    // Ricorsioni
    int left_diff  = CalcolaMinMax(A, start, mid);
    int right_diff = CalcolaMinMax(A, mid + 1, end);
    // Caso incrociato (i <= mid, j > mid): 
    // Min(A[j] - A[i]) = Min(A[j]) a destra - Max(A[i]) a sinistra
    int max_left  = TrovaMassimo(A, start, mid);
    int min_right = TrovaMinimo(A, mid + 1, end);
    int cross_diff = min_right - max_left;

    // Ritorna il minimo tra i tre
    int result = left_diff;
    if (right_diff < result) result = right_diff;
    if (cross_diff < result) result = cross_diff;

    return result;
}

