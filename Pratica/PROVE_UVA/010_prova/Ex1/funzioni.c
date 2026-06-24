#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

Risultato DividiSequenza(long long A[MAX_SEQ], int p, int r) {
    // CASO BASE: se c'è un solo elemento, esso è sia il massimo che il minimo
    if (p == r) {
        Risultato base;
        base.maxVal = A[p];
        base.minVal = A[p];
        return base;
    }

    int q = (p + r) / 2; // Calcolo punto medio

    // Chiamate ricorsive per ottenere i risultati dalle due metà
    Risultato risSx = DividiSequenza(A, p, q);
    Risultato risDx = DividiSequenza(A, q + 1, r);

    // Qui andrebbe la logica di Cross
    Risultato risCross=CalcolaCrossProduction(A, p,q,r);
    //Confronto finale per trovare il max e min 
    Risultato finale;
    finale.maxVal = maxVal(maxVal(risSx.maxVal, risDx.maxVal), risCross.maxVal);
    finale.minVal = minVal(minVal(risSx.minVal, risDx.minVal), risCross.minVal);
    return finale;


}


// Funzione che restituisce il massimo tra due numeri
long maxVal(long a, long b) {
    return (a > b) ? a : b;
}

// Funzione che restituisce il minimo tra due numeri
long minVal(long a, long b) {
    return (a < b) ? a : b;
}


Risultato CalcolaCrossProduction(long long A[MAX_SEQ], int p, int q, int r) {
    // 1. Analisi della parte SINISTRA (da q a p) 
    Risultato valTmp1;
    valTmp1.maxVal = A[q];
    valTmp1.minVal = A[q];
    long long Prodotto1 = A[q];
    for (int i = q - 1; i >= p; i--) { // Vado da q-1 a p
        Prodotto1 = A[i] * Prodotto1;
        valTmp1.maxVal = maxVal(Prodotto1, valTmp1.maxVal);
        valTmp1.minVal = minVal(Prodotto1, valTmp1.minVal);   
    }

    // 2. Analisi della parte DESTRA (da q+1 a r)
    Risultato valTmp2;
    valTmp2.maxVal = A[q + 1];
    valTmp2.minVal = A[q + 1];
    long long Prodotto2 = A[q + 1];
    for (int i = q + 2; i <= r; i++) { // Vado da q+2 a r
        Prodotto2 = A[i] * Prodotto2;
        valTmp2.maxVal = maxVal(Prodotto2, valTmp2.maxVal);
        valTmp2.minVal = minVal(Prodotto2, valTmp2.minVal);   
    }

    // 3. Calcolo delle 4 combinazioni di cross (fondamentali per i segni negativi)
    long long c1 = valTmp1.maxVal * valTmp2.maxVal;
    long long c2 = valTmp1.maxVal * valTmp2.minVal;
    long long c3 = valTmp1.minVal * valTmp2.maxVal;
    long long c4 = valTmp1.minVal * valTmp2.minVal;
    // 4. Definizione del risultato finale usando i tuoi metodi maxVal e minVal
    Risultato finale;
    
    // Trovo il massimo assoluto tra le 4 combinazioni
    long long maxIntermedio1 = maxVal(c1, c2);
    long long maxIntermedio2 = maxVal(c3, c4);
    finale.maxVal = maxVal(maxIntermedio1, maxIntermedio2);

    // Trovo il minimo assoluto tra le 4 combinazioni
    long long minIntermedio1 = minVal(c1, c2);
    long long minIntermedio2 = minVal(c3, c4);
    finale.minVal = minVal(minIntermedio1, minIntermedio2);

    return finale;
}

