#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    char words[N][MaxLen] = {"AAA", "BB", "C", "DDDD"};

    printf("Parole originali:\n");
    printWordsInline(words, N);

    // Calcolo lunghezze
    calculateLengths(words, N, lengths);

    // Calcolo tabella Bandness
    CalcolaBandness(Bandness, lengths, N);

    // Stampa tabella
    stampaBandness(Bandness, N);

    // Inizializza DP a -1
    for (int i = 0; i <= N; i++) DP[i] = -1;

    // Calcolo DP dall'inizio
    int costoMinimo = computeDP(0, N);
    printf("\nCosto minimo totale = %d\n", costoMinimo);

    // Stampa righe ottimali
    stampaRigheOttimali(words, N);
    system("PAUSE");
    return 0;
}
/*
# - Numero di sottoproblemi: N
# - Per ogni sottoproblema, esploro fino a N possibili j
# Complessità asintotica: O(N^2)

*/


/*

# Giustificazione del testo - Ricorrenze e formule

# 1. Bandness(i,j)
# Costo di mettere le parole da i a j sulla stessa riga

Bandness(i,j) =
    (PageWidth - sum_{k=i}^{j} len(words[k]) - (j-i))^3      se sum_{k=i}^{j} len(words[k]) + (j-i) <= PageWidth
    INF                                                        altrimenti


# 2. Funzione DP(i)
# DP(i) = costo minimo per giustificare le parole da i fino alla fine

DP(i) =
    0                                                              se i = N
    min_{j=i..N-1} { Bandness(i,j) + DP(j+1) }                     altrimenti

*/