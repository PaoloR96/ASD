#include <stdio.h>
#include <limits.h>
#include "funzioni.h"

// --- Definizione delle variabili globali ---
int lengths[N];
int Bandness[N][N];
int DP[N+1];
int bestSplit[N];

// --- Funzioni ---

void printWordsInline(char words[][MaxLen], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%s", words[i]);
    }
    printf("\n");
}

void calculateLengths(char words[][MaxLen], int n, int lengths[]) {
    for (int i = 0; i < n; i++) {
        lengths[i] = 0;
        while (words[i][lengths[i]] != '\0') lengths[i]++;
    }
}

void CalcolaBandness(int Bandness[N][N], int lengths[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int total_length = 0;
            for (int k = i; k <= j; k++) total_length += lengths[k];
            total_length += (j - i); // spazi tra parole
            if (total_length <= PageWidth) {
                int spazio = PageWidth - total_length;
                Bandness[i][j] = spazio * spazio * spazio;
            } else {
                Bandness[i][j] = INT_MAX;
            }
        }
    }
}

void stampaBandness(int Bandness[N][N], int n) {
    printf("\nTabella Bandness(i,j):\n");
    printf("i\\j\t");
    for (int j = 0; j < n; j++) printf("%d\t", j);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", i);
        for (int j = 0; j < n; j++) {
            if (j < i) printf("-\t");
            else if (Bandness[i][j] == INT_MAX) printf("INF\t");
            else printf("%d\t", Bandness[i][j]);
        }
        printf("\n");
    }
}

int computeDP(int i, int n) {
    if (i == n) return 0;  // caso base
    if (DP[i] != -1) return DP[i];

    int minCost = INT_MAX;
    int bestJ = -1;

    for (int j = i; j < n; j++) {
        if (Bandness[i][j] == INT_MAX) continue;
        int costo = Bandness[i][j] + computeDP(j+1, n);
        if (costo < minCost) {
            minCost = costo;
            bestJ = j;
        }
    }

    DP[i] = minCost;
    bestSplit[i] = bestJ;
    return minCost;
}

void stampaRigheOttimali(char words[][MaxLen], int n) {
    printf("\nRighe ottimali:\n");
    int i = 0;
    while (i < n) {
        int j = bestSplit[i];
        for (int k = i; k <= j; k++) {
            if (k > i) printf(" ");
            printf("%s", words[k]);
        }
        printf("\n");
        i = j + 1;
    }
}