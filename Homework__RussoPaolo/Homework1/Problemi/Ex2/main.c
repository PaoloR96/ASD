#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    //Passo1:Definisco i casi di test
    printf("SAMPLE INPUT:");
    /* TEST 1: Caso Medio (Array disordinato)
    Un array casuale per verificare il corretto funzionamento di base. */
    int array1[] = {5, 3, 7, 2, 4, 8};
    int dim1 = sizeof(array1) / sizeof(array1[0]);
    printf("\nCaso di Test 1:");
    StampaVettore(array1, dim1);
    /* TEST 2: Caso Peggiore / Controesempio (Array già ordinato in modo crescente)
    Questo è il caso ideale per dimostrare che le due procedure generano heap visibilmente diversi. */
    int array2[] = {1, 2, 3, 4, 5, 6, 7};
    int dim2 = sizeof(array2) / sizeof(array2[0]);
    printf("\nCaso di Test 2:");
    StampaVettore(array2, dim2);
    /* TEST 3: Caso Migliore per V2 (Array già ordinato in modo decrescente)
    In questo caso gli elementi inseriti come foglie sono già più piccoli dei padri, 
    quindi non ci sarà bisogno di farli risalire. */
    int array3[] = {9, 8, 7, 6, 5, 4, 3};
    int dim3 = sizeof(array3) / sizeof(array3[0]);
    printf("\nCaso di Test 3: ");
    StampaVettore(array3, dim3);
    
    printf("\n\n");
    //Passo2:Parto con l'ordinamento
    printf("SAMPLE OUTPUT:");
    // Eseguiamo i test
    EseguiTest(array1, dim1, "Test 1 (Disordinato)");
    EseguiTest(array2, dim2, "Test 2 (Controesempio)");
    EseguiTest(array3, dim3, "Test 3 (Decrescente)");

    system("pause");
    return 0;
}

/*
Complessità:
BUILD-MAX-HEAP:Theta(n)
BUILD-MAX-HEAP_v2:Theta(n*logn)

*/