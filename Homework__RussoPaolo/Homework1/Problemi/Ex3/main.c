#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    // Inizializzo la struttura Heap che passeremo alla funzione
    Struttura_Heap heap;

    // Passo 1: Definisco i casi di test
    printf("SAMPLE INPUT:\n");
    
    /* TEST 1: Caso Base (Array k-ordinato)
    Un array disordinato ma in cui ogni elemento dista al massimo k=2 dalla sua posizione finale. */
    int array1[] = {2, 3, 1, 5, 6, 4};
    int dim1 = sizeof(array1) / sizeof(array1[0]);
    int k1 = 2;
    printf("\nCaso di Test 1 (k=%d): ", k1);
    StampaVettore(array1, dim1);
    
    /* TEST 2: Caso Migliore (Array gia' ordinato)
    L'array e' gia' ordinato, ogni elemento dista 0 posizioni dallasua collocazione finale, possiamo usare un k piccolo a piacere. */
    int array2[] = {1, 2, 3, 4, 5, 6, 7};
    int dim2 = sizeof(array2) / sizeof(array2[0]);
    int k2 = 1;
    printf("\nCaso di Test 2 (k=%d): ", k2);
    StampaVettore(array2, dim2);
    
    /* TEST 3: Caso Peggiore (Array ordinato in modo decrescente)
    In questo caso, gli elementi sono all'opposto della loro posizione corretta.
    Affinché l'algoritmo funzioni, k deve per forza coprire tutto l'array (k = dim - 1). */
    int array3[] = {9, 8, 7, 6, 5, 4, 3};
    int dim3 = sizeof(array3) / sizeof(array3[0]);
    int k3 = dim3 - 1; // k deve essere 6 in questo caso
    printf("\nCaso di Test 3 (k=%d): ", k3);
    StampaVettore(array3, dim3);
    
    printf("\n\n");
    
    // Passo 2: Parto con l'ordinamento
    printf("SAMPLE OUTPUT:\n");
    printf("\nTest 1: \n");
    EseguiTest(&heap, array1, dim1, k1);
    printf("\nTest 2: \n");
    EseguiTest(&heap, array2, dim2, k2);
    printf("\nTest 3: \n");
    EseguiTest(&heap, array3, dim3, k3);

    printf("\n");
    system("pause");
    return 0;
}

/*
  Complessità temporale: O(n log k),dove: 
    n è il numero totale di elementi nell'array 
    k è la distanza massima di un elemento dalla sua posizione ordinata finale (finestra).
*/