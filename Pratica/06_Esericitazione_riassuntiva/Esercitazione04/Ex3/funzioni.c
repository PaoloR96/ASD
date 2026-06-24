#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

// Inserisce i diametri dei pancake in una riga
void InserisciElementi(int A[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &A[i]);
        if (A[i] < 1 || A[i] > 100) {
            printf("Diametro non valido!\n");
            return;
        }
    }
}

// Stampa l'intera matrice delle pile
void StampaPila(int A[][MAX_D], int h, int d){
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < d; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

// Trova il massimo nella sotto-pila A[0 ... d-1]
int TrovaPosMAX(int A[], int d){
    int pos = 0;
    int max = A[0];
    for (int i = 1; i < d; i++){
        if(A[i] > max){
            pos = i;
            max = A[i];
        }
    }
    return pos;
}

// Flip dei primi k elementi (stampa la posizione)
void Flip(int A[], int k, int n){
    if (k <= 1) return;
    int i = 0, j = k - 1;
    while (i < j){
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        i++;
        j--;
    }

    // stampa posizione
    printf("%d ", n - k + 1);
}

// Ordinamento ricorsivo pancake
void OrdinaPila(int A[], int n, int curr) {
    // Caso base: una sotto-pila di 0 o 1 elementi è già ordinata
    if (curr <= 1) return;
    // Trova la posizione del pancake più grande nella parte non ordinata A[0 .. curr-1]
    int pos = TrovaPosMAX(A, curr);
    // Se il pancake più grande NON è già nella sua posizione finale (curr - 1)…
    if (pos != curr - 1) {
        // Se il massimo non è in cima (pos != 0), lo portiamo in cima con un flip
        if (pos != 0)Flip(A, pos + 1, n);   // Flip dei primi pos+1 elementi
        // Ora il massimo è in cima; lo portiamo nella posizione finale curr - 1
        Flip(A, curr, n);          // Flip dei primi 'curr' elementi
    }
    // Ricorsione sulla parte rimanente della pila (escludendo l’ultimo elemento ordinato)
    OrdinaPila(A, n, curr - 1);
}


// Ordina tutte le pile e stampa i risultati
void OrdinaElementi(int A[][MAX_D], int h, int d) {
    for (int i = 0; i < h; i++) {
        // stampa pila originale
        for (int j = 0; j < d; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
        // ordina ricorsivamente
        OrdinaPila(A[i], d, d);
        // fine seq
        printf("0\n");
    }
}


/*
| Funzione             | Tempo       |
| -------------------- | ----------- |
| InserisciElementi    | O(d)        |
| StampaPila           | O(h·d)      |
| TrovaPosMAX          | O(d)        |
| Flip                 | O(d)        |
| OrdinaPila           | O(d²)       |
| OrdinaElementi       | O(h·d²)     |
| Programma totale     | O(h·d²)     |
*/