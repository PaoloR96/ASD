#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int T = 1;  // numero di casi di test
    int N[MAX_TEST] = {11};
    char campo[MAX_TEST][MAX_CELLE] = {"...##....##"};

    for (int t = 0; t < T; t++) {
        printf("Caso %d:\n", t + 1);
        stampaCampo(N[t], campo[t]);
        CalcolaSoluzione(N[t],campo[t]);
    }
   

    system("pause");
    return 0;
}