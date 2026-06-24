#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.h"  // Include il file header con le dichiarazioni delle funzioni

// ==========================
// Funzione di stampa di una sequenza di numeri
// ==========================
void StampaSequenza(int Seq[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", Seq[i]);
    }
    printf("\n");               
}

// ==========================
// Funzione per verificare se un numero è primo
// ==========================
bool isPrime(int n) {
    if (n <= 1) return false;   // 0 e 1 non sono primi
    if (n == 2) return true;    // 2 è primo
    if (n % 2 == 0) return false;  // Esclude tutti i numeri pari > 2

    // Controlla solo i divisori dispari fino alla radice quadrata di n
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;       // Se è divisibile, non è primo

    return true;                // Se non trova divisori → è primo
}


void CalcolaSequenza(int s, int n, int p) {
    int Seq[n];  

    // Avvio della funzione ricorsiva di backtracking
    // Parametri:
    // Seq → array corrente
    // s → somma obiettivo
    // n → lunghezza richiesta della sequenza
    // p → limite inferiore (i numeri devono essere > p)
    // 0 → indice iniziale (nessun numero ancora scelto)
    // 0 → somma iniziale
    // p + 1 → primo numero da considerare
    GeneraSequenza(Seq, s, n, p, 0, 0, p + 1);
}

// ==========================
// Funzione ricorsiva di BACKTRACKING
// ==========================
void GeneraSequenza(int Seq[], int s, int n, int p, int index, int somma, int prossimoNum) {

    // ===== Caso base =====
    // Se ho già scelto n numeri, controllo se la loro somma è uguale a s
    if (index == n) {
        if (somma == s) {
            StampaSequenza(Seq, n); 
        }
        return;
    }

    // ===== Caso ricorsivo =====
    // Scorro tutti i numeri da "prossimoNum" fino a "s"
    for (int i = prossimoNum; i <= s; i++) {
        // Considero solo i numeri primi e maggiori di p
        if (isPrime(i) && i > p) {
            // Potatura: se la somma parziale supererebbe s, fermo il ciclo
            if (somma + i > s)
                break;
            // Scelta: aggiungo il numero corrente alla sequenza
            Seq[index] = i;

            // Chiamata ricorsiva:
            GeneraSequenza(Seq, s, n, p, index + 1, somma + i, i + 1);
            // BACKTRACKING: annullo la scelta fatta
            Seq[index] = 0;
        }
    }
}

