#include <stdio.h>
#include <stdlib.h>

#include "funzioni.h"  // Include il file header

void InserisciSequenza(int A[], int size){
    for (int i = 0; i < size; i++) scanf("%d",&A[i]);
}

int CalcolaABS(int A[], int i) {
    return abs(A[i] - A[i + 1]);
}


void CheckSequenza(int A[], int size, int index, int last) {
   /*condizione di uscita nel caso in cui ho raggiunto la fine della sequenza*/
    if (index == size - 1) { 
        printf("Jolly\n");
        return;
    }
    /*calcolo il valore assoluto tra l'elemento n e n+1*/
    int diff = CalcolaABS(A, index);

    // primo passo: inizializza last,definendo la prima coppia di valori
    if (index == 0) {
        CheckSequenza(A, size, index + 1, diff);
        return;
    }

    // controlla se la differenza segue la tua logica: last, last-1, last-2, ...
    if (diff == last - 1) {
        CheckSequenza(A, size, index + 1, diff);
    } else {
        printf("Not jolly\n");
    }
}