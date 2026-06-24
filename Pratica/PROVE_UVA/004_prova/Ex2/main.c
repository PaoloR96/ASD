#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Dizionario d[2]; // due casi di test
    char cifre[10] = {'0','1','2','3','4','5','6','7','8','9'};
    /* ===== CASO 1 ===== */
    d[0].n = 2;
    strcpy(d[0].parola[0], "root");
    strcpy(d[0].parola[1], "super");
    d[0].m = 1;
    strcpy(d[0].regole[0], "#0");
    /* ===== CASO 2 ===== */
    d[1].n = 1;
    strcpy(d[1].parola[0], "admin");
    d[1].m = 1;
    strcpy(d[1].regole[0], "#0#");
    //1.Stampa
    printf("SAMPLE INPUT:\n");
    for (int k = 0; k < 2; k++)stampaDizionario(d[k]);
    //2.Elaborazione Output
    // Ciclo sui due casi di test (Dizionari)
    for (int k = 0; k < 2; k++) {
        // Per ogni set di "dizionario + regole" si stampano due trattini 
        printf("--\n");
        // Ciclo sulle regole del dizionario corrente (m regole)
        for (int j = 0; j < d[k].m; j++) {
            char password_iniziale[512] = ""; // Stringa vuota per iniziare il backtracking
            // Chiamata alla funzione ricorsiva per la regola corrente
            ElaboraPassword(d[k], 0, d[k].regole[j], password_iniziale);
        }
    }
    system("pause");
    return 0;
}
/*
Complessità:o(n^W*10^D) 
con: 
    w=numero di simboli # della regola 
    d=numero di simboli 0 della regola


*/