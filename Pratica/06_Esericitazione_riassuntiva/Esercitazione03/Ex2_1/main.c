#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   int T;
   scanf("%d", &T);  // Numero di casi di test
   while (T--) {
        int n;
        scanf("%d", &n);
        int A[n];
        InserisciSequenza(A, n);  // legge i n numeri della sequenza
        if (n == 1) {
            printf("Jolly\n");
        } else {
            CheckSequenza(A, n, 0, 0);
        }
    }

    system("pause");
    return 0;
}
/*Complessità O(N)*/