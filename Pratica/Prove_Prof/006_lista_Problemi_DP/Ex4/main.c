#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    // Array per salvare i risultati di ogni caso di test e stamparli alla fine
    Risultato ris[100]; 
    int contatore_test = 0;
    char stringa_input[MAX * 10];
    
    // Dichiarazione locale delle matrici DP per passarle correttamente a InitDP e CalcolaDP
    int DPMax[MAX][MAX];
    int DPMin[MAX][MAX];

    while (contatore_test < 100) {
        // 1. Inserisco e acquisisco la stringa dall'utente (CORRETTO CON scanf)
        if (scanf("%s", stringa_input) == EOF) {
            break; 
        }
        
        if (strcmp(stringa_input, "0") == 0) break; // se ho inserito 0 termino
        
        // 2. Effettuo l'operazione di parsing
        int numeri[MAX];
        char operatori[MAX];
        int dim_num = 0;
        int dim_op = 0;
        int i = 0;
        int len_stringa = strlen(stringa_input);
        
        while (i < len_stringa) {
            // Se la stringa contiene caratteri numerici
            if (isdigit(stringa_input[i])) {
                int valore = 0;
                // finché ci sono caratteri ed il carattere in posizione i sia una cifra "0-9"
                while (i < len_stringa && isdigit(stringa_input[i])) {
                    // trasformo una sequenza di caratteri numerici in un numero intero
                    valore = valore * 10 + (stringa_input[i] - '0');
                    i++;
                }
                numeri[dim_num++] = valore;
            } else {
                operatori[dim_op++] = stringa_input[i];
                i++;
            }
        }
        
        // 3. Inizializzo DpMin e DpMax
        InitDP(DPMax, DPMin, numeri, dim_num);
        
        // 4. Calcoliamo il massimo e il minimo e salviamo nell'array dei risultati
        ris[contatore_test] = CalcolaDP(DPMax, DPMin, operatori, dim_num);
        contatore_test++;
    }

    printf("\nSAMPLE OUTPUT: \n");
    // Stampiamo tutti i risultati accumulati nel formato richiesto: "Massimo Minimo"
    for (int i = 0; i < contatore_test; i++) {
        printf("%d %d\n", ris[i].massimo, ris[i].minimo);
    }

    system("pause");
    return 0;
}

/*
La complessità è O(N^3)

Ricorrenza per ogni k ∈ (i, j), dove i va da 0 a dim_len e j = i + len - 1:

if (operatori[k] == '+') {   // se ho un'addizione
    succ_max = DPMax[i][k] + DPMax[k+1][j];
    succ_min = DPMin[i][k] + DPMin[k+1][j];

} else if (operatori[k] == '*') {   // se ho una moltiplicazione
    succ_max = DPMax[i][k] * DPMax[k+1][j];
    succ_min = DPMin[i][k] * DPMin[k+1][j];
}


*/