#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n\n");
    
    // Definisco i casi di test
    int CasiTest = 2; 
    int inputN[2] = {6, 6}; // riga iesima associata ad ogni caso di test
    int inputM[2] = {7, 7}; // colonna iesima associata ad ogni caso di test
    
    int inputMatrici[2][6][7] = {
        // --- Primo caso di test ---
        {
            {0, 1, 1, 0, 1, 1, 0},    
            {0, 0, 0, 0, 0, 1, 0},  
            {1, 0, 0, 0, 0, 0, 1},  
            {0, 1, 0, 0, 0, 0, 1},  
            {1, 1, 0, 0, 0, 1, 0},  
            {1, 1, 0, 1, 1, 0, 0}
        },
        // --- Secondo caso di test ---
        {
            {0, 1, 1, 0, 1, 1, 0}, 
            {0, 0, 0, 0, 0, 1, 0}, 
            {1, 1, 0, 0, 0, 0, 1}, 
            {0, 1, 0, 1, 0, 0, 1}, 
            {1, 1, 0, 0, 0, 1, 0}, 
            {1, 1, 0, 1, 1, 0, 0}
        }
    };

    int N = 0, M = 0; // dimensioni matrice N*M
    int Matrice[DIM_N][DIM_M];
    int index = 0;
    int Risultato[DIM_N]; // Array per salvare i risultati
    
    // Definisco la mia DP
    int DP[DIM_N][DIM_M];
    
    while (index < CasiTest) {
        // Fase 1: Inserimento
        N = inputN[index];
        M = inputM[index];

        // Copio i parametri nella matrice di appoggio e li stampo
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Matrice[i][j] = inputMatrici[index][i][j];
                printf("%d ", Matrice[i][j]); // Stampa l'elemento appena copiato
            }
            printf("\n"); 
        }
        printf("\n");
        
        // Fase 2: Calcolo DP
        InitDP(DP, N, M);
        Risultato[index] = CalcolaDP(DP, Matrice, N, M);
        // Fase 3: Passo al prossimo caso di test
        index++;
    }
    // Fase 4: Stampa Risultati
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < CasiTest; i++) printf("%d \n", Risultato[i]);
    
    
    system("pause");
    return 0;
}

/*
Complessità: O(N * M^2 * T) dove N = numero di righe; M = numero di colonne; T = numero di casi di test.
(Nota: la complessità è quadratica rispetto a M per via dell'espansione iterativa a destra e sinistra per ogni barra dell'istogramma).

Ricorrenza: DP[i][j] => vale DP[i-1][j] + 1  Se l'elemento nella matrice è 0 e i > 0
                        vale 1               Se l'elemento nella matrice è 0 e i == 0 (Caso base) 
                        vale 0               Se l'elemento nella matrice è 1
*/