#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"

int main() {
    // Definizione dei 3 casi di test
    int test1[] = {4, 6, 4, 3, 2, 2, 1, 1};
    int test2[] = {5, 3, 2, 1, 1};
    int test3[] = {400, 12, 50, 50, 50, 50, 50, 50, 25, 25, 25, 25, 25, 25};
    // Array di puntatori ai test
    int* tests[] = {test1, test2, test3};
    int numTest = 3;
    for (int t = 0; t < numTest; t++) {
        printf("\n--- TEST %d ---\n", t + 1);
        int* InsiemeSK = tests[t];
        int dim;
        // Calcolo dimensione in base al test
        if (t == 0) dim = sizeof(test1) / sizeof(int);
        else if (t == 1) dim = sizeof(test2) / sizeof(int);
        else dim = sizeof(test3) / sizeof(int);
        int attuale[100];
        int SommaCorrente = 0;
        int trovato = 0;
        StampaArray(InsiemeSK, dim);
        trovaSomme(InsiemeSK, dim, InsiemeSK[0], 1,attuale, 0, SommaCorrente, &trovato);
        if (!trovato)printf("NONE\n");
    }
    system("pause");
    return 0;
}
/*Complessità: O(2^n)*/