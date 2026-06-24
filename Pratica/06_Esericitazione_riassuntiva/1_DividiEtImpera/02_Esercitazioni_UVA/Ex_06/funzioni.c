#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 1000

/*********************
 * FUNZIONI DI SUPPORTO
 *********************/

/*Legge un array di dimensione 'size' - Complessità: O(n)*/
void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++) scanf("%d", &A[i]);
}

/*Genera tutte le somme di coppie distinte - Complessità: O(n^2)*/
int GeneraSommeCoppie(int A[], int dim, int S[]) {
    int indice = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = i + 1; j < dim; j++) {
            S[indice++] = A[i] + A[j];
        }
    }
    return indice;
}

/*Partizione per QuickSort - Complessità: O(n)*/
int Partizion(int A[], int start, int end) {
    int pivot = A[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (A[j] <= pivot) {
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int tmp = A[i + 1];
    A[i + 1] = A[end];
    A[end] = tmp;
    return i + 1;
}

/*QuickSort ricorsivo - Complessità media: O(n log n), peggior caso: O(n^2)*/
void QuickSort(int A[], int start, int end) {
    if (start < end) {
        int p = Partizion(A, start, end);
        QuickSort(A, start, p - 1);
        QuickSort(A, p + 1, end);
    }
}

/*Ricerca binaria ricorsiva per somma più vicina - Complessità: O(log n^2) = O(log n)*/
int RicercaBinariaVicino(int S[], int low, int high, int x, int closest) {
    if (low > high) return closest;

    int mid = low + (high - low) / 2;

    if (abs(S[mid] - x) < abs(closest - x)) {
        closest = S[mid];
    }

    if (S[mid] == x) return S[mid];
    else if (S[mid] < x) return RicercaBinariaVicino(S, mid + 1, high, x, closest);
    else return RicercaBinariaVicino(S, low, mid - 1, x, closest);
}

/*Confronta le query con le somme ordinate - Complessità: O(m log n^2) ≈ O(log n) per query*/
void ConfrontaElementi(int S[], int sindex, int query[], int m) {
    for (int i = 0; i < m; i++) {
        int x = query[i];
        int closest = RicercaBinariaVicino(S, 0, sindex - 1, x, S[0]);
        printf("La somma più vicina a %d è %d.\n", x, closest);
    }
}

/*Elabora tutti i casi - Complessità totale per caso: O(n^2 + n^2 log n + m log n) ≈ O(n^2 log n)*/
void CaolcolaElementi(int N[][SIZE], int n[SIZE], int query[][SIZE], int m[SIZE], int index) {
    int S[SIZE * SIZE];
    for (int i = 0; i < index; i++) {
        int sindex = GeneraSommeCoppie(N[i], n[i], S);  // O(n^2)
        QuickSort(S, 0, sindex - 1);                     // O(n^2 log n)
        printf("Caso %d:\n", i + 1);
        ConfrontaElementi(S, sindex, query[i], m[i]);   // O(m log n^2)
    }
}
