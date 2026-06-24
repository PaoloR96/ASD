#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c
#include <math.h>

#include <stdio.h>
#include "funzioni.h"

int main() {
    double Valori[SIZE][3];
    int T = 0, index = 0;

    printf("SAMPLE INPUT:\n");
    scanf("%d", &T);

    while(T != 0){
        scanf("%lf %lf %lf", &Valori[index][0], &Valori[index][1], &Valori[index][2]);
        index++;
        T--;
    }

    printf("SAMPLE OUTPUT:\n");
    TrovaSequenze(Valori, index);
    system("pause");
    return 0;
}

/*
    Complessità totale: O(T * log n) 
    - T = numero di casi di test (righe di input)
    - log n = numero di iterazioni della ricerca binaria per ciascun caso
    - n ≈ W / tolleranza, dove W = min(x, y) dell’input corrente
*/
