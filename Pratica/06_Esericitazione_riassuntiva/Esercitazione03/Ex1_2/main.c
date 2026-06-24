#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int T;       // numero di casi di test
    scanf("%d", &T);
    for (int caso = 0; caso < T; caso++) {
        int N;
        scanf("%d", &N);
        int A[N][2];
        float R[N];
        int ordine[N];
        RiempiMatrice(A, N);
        CalcolaResidui(R, A, N);
        OrdinaLavori(ordine, R, N);
        StampaOrdine(ordine, N);
        if (caso < T - 1)
            printf("\n");
    }
    printf("\n");


    system("pause");
    return 0;
}
/*Complessità: Poichè uso il bubbleSort la mia complessità è O(N^2)*/