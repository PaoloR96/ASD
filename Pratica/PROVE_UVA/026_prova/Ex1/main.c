#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    printf("SAMPLE INPUT: \n");
    int index = 0;
    double Risultato[100];
    Parametri p;
    while (index < 100 && scanf("%lf %lf %lf %lf %lf %lf", &p.p, &p.q, &p.r, &p.s, &p.t, &p.u) != EOF) {
        
        //1.Verifico se la soluzione esiste tra 0 e 1
        //Se f(0) e f(1) hanno lo stesso segno, non c'è intersezione con l'asse x
        if (CalcolaFunzione(p, 0.0) < 0 || CalcolaFunzione(p, 1.0) > 0) {
            Risultato[index] = -1.0; // Usiamo -1.0 per indicare "No solution"
        } else {
            Risultato[index] = CalcolaSoluzione(p, 0.0, 1.0);
        }
        index++;
    }

    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < index; i++) {
        if (Risultato[i] < 0) {
            printf("No solution\n"); 
        } else {
            printf("%.4f\n", Risultato[i]); // Stampa con 4 cifre decimali
        }
    }

    system("pause");
    return 0;
}

/*
Complessità: O(T*log(1/eps)) dove T numero di input e eps corrisponde alla precisione desiderata

*/