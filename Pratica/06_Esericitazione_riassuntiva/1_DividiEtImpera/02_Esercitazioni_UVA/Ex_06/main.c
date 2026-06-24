#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c


int main() {
    int n[SIZE];               // numero di elementi per ogni caso
    int N[SIZE][SIZE];         // array di interi per ogni caso
    int m[SIZE];               // numero di interrogazioni per ogni caso
    int query[SIZE][SIZE];     // array di interrogazioni per ogni caso
    int index = 0;             // conta i casi

    printf("SAMPLE INPUT:\n");

    while (1) {
        printf("def n:\n");
        if (scanf("%d", &n[index]) != 1 || n[index] == 0) break;
        if (n[index] < 1 || n[index] > 1000) continue;

        printf("Riempo N:\n");
        RiempiVettore(N[index], n[index]);

        // Controllo m tra 1 e 24
        printf("def m:\n");
        do {
            scanf("%d", &m[index]);
        } while(m[index] <= 0 || m[index] >= 25);

        printf("Riempo M:\n");
        RiempiVettore(query[index], m[index]);

        index++;
    }

    printf("SAMPLE OUTPUT:\n");
    CaolcolaElementi(N, n, query, m, index);
    system("PAUSE");
    return 0;
}
/*

Elabora tutti i casi - Complessità totale per caso: O(n^2 + n^2 log n + m log n) ≈ O(n^2 log n)

*/

