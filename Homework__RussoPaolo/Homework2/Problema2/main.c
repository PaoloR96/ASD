#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    //1.Preparazione dei 3 casi di test
    //Caso1:
    int arr1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n1 = 8;
    //Caso2:
    int arr2[] = {50, 40, 30, 20, 10};
    int n2 = 5;
    //Caso3:
    int arr3[] = {2, 4, 6, 8, 10, 12};
    int n3 = 6;
    //Array di puntatori agli array di test
    int* test_arrays[] = {arr1, arr2, arr3};
    //Array contenente le dimensioni corrispondenti
    int test_sizes[] = {n1, n2, n3};
    int TEST=3;
    // Array per salvare i risultati calcolati
    int risultati[3];
    //Definisco la mia DP
    int DP[MAX];
    //2.Stampa dell'input
    printf("SAMPLE INPUT:\n");
    for (int i = 0; i < TEST; i++) {
        // Ciclo interno per stampare gli elementi dell'array corrente
        for(int j = 0; j < test_sizes[i]; j++)printf("%d ", test_arrays[i][j]);
        printf("\n");
    }
    //3.Calcolo la DP per ogni problema iesimo che abbiamo definito
    for (int i = 0; i < TEST; i++) {
        InitDP(DP, test_sizes[i]);
        risultati[i] = CalcolaDP(DP, test_arrays[i], test_sizes[i]);
    }
    //4.Stampa dei risultati
    printf("\n");
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < TEST; i++) printf("%d\n", risultati[i]);
    
    system("pause");
    return 0;
}


/*
Complessità:Il metodo CalcolaDP ha una complessità O(n^2) ,pertanto valutandolo su T casi, avrò O(T*n^2)

Ricorrenza:
            Caso base:      DP[i]=1 per ogni i appartenente all'intervallo [0, n-1] 
            Passo Ricorsivo:DP[i] = max(DP[j] + 1) per ogni j tale che 0 <= j < i e arr[j] < arr[i]
*/