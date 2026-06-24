#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

// Array globale per supportare l'alto numero di coppie senza usare puntatori/malloc
CoppiaY archivioCoppie[MAX_COPPIE];

int main() {
    int n = 5;
    Punto punti[MAX] = {{0, 0}, {2, 0}, {0, 2}, {2, 2}, {1, 1} };

    // 1. Ordina i punti
    qsort(punti, n, sizeof(Punto), confrontaPunti);

    // 2. Genera le coppie usando l'array statico globale
    int totaleCoppie = GeneraTutteLeCoppie(punti, n, archivioCoppie);

    // 3. Conta i rettangoli col metodo dedicato
    int risultato = ContaRettangoli(archivioCoppie, totaleCoppie);

    printf("Case 1: %d\n", risultato); 
    system("pause");

    return 0;
}
/*
Complessità:O(n^2*logn)
*/

