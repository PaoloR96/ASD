#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int n, index = 0;
    char riga[130];
    int Risultato[MAX];
    int DP[MAX][MAX]; 

    if (scanf("%d", &n) != 1) return 0;
    getchar(); // Necessario: consuma il carattere '\n' rimasto nel buffer dopo scanf

    while (index < n) {
        if (!fgets(riga, sizeof(riga), stdin)) break;
        
        // Rimuove il newline (\n) e il carriage return (\r) per compatibilità
        riga[strcspn(riga, "\r\n")] = 0;
        
        int N = strlen(riga);
        
        // Gestione stringa vuota (Regola A)
        if (N == 0) {
            Risultato[index] = 1;
        } else {
            CalcolaDP(DP, riga, N);
            if (DP[0][N-1]) Risultato[index] = 1;
            else Risultato[index] = 0;
        }
        
        index++;
    }

    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++) {
        if (Risultato[i] == 1) {
            printf("Yes\n"); 
        } else {
            printf("No\n");  
        }
    }
    
    system("pause");
    return 0;
}

/*
Ricorrenza per la concatenazione:DP[i][j] = Vero se esiste un k in [i, j-1] tale che: DP[i][k] AND DP[k+1][j]
Ricorrenza per il racchiudimento:Se (S[i], S[j]) è una coppia valida (ovvero () oppure []),allora:DP[i][j] = DP[i+1][j-1]
COmplessitàO(N^3)
*/