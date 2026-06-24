#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int DP[MAX+1],DPIndici[MAX+1];
    //Caso di test:1
     // Creazione del vettore con gli elementi dati
    int vettore[] = {-7, 10, 9, 2, 3, 8, 8, 6};
    // Calcolo della dimensione del vettore
    int n = sizeof(vettore) / sizeof(vettore[0]);
    //1.Stampa Campioni Vettore
    printf("SAMPLE INPUT:\n");
    StampaVettore(vettore,n);
    //2.Inizializzo i vettori DP e DPIndici
    InizializzaDP(DP,DPIndici,n+1);
    //3.Calcolo DP e DPIndici
    int ultimo = CalcolaDP(vettore, DP, DPIndici, n);
    //4.Stampa
    printf("%d\n-\n", DP[ultimo]);
    StampaSottosequenza(vettore, DPIndici, ultimo);
    system("pause");
    return 0;
}

/*
Complessità:O(n^2) con n numero di elementi

Ricorrenza:
    DP[i]=1+DP[j] per ogni vettore[j]<valAtt && DP[i]<=1+DP[j]
    oppure:
    DP[i] = 1 + max({ DP[j] | 0 <= j < i and vettore[j] < vettore[i] } ∪ {0})



*/