#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"


int main() {
    int Target[MAX];
    // Matrice 3D: [NumeroCaso][IncrocioA][IncrocioB]
    int Matrice[MAX][MAX][MAX];
    int visitato[MAX];
    int x1Tmp = 0, x2Tmp = 0, stradaTmp = 0;
    int index = 0;
    //Inizializzazione
    memset(Matrice, 0, sizeof(Matrice));
    printf("SAMPLE INPUT:\n");
    /* Inserimento casi di test */
    while (index < MAX && scanf("%d", &stradaTmp) == 1) {
        //Inserisco il target
        Target[index] = stradaTmp;    
        //Inserisco gli incroci
        while (1) {
            if (scanf("%d %d", &x1Tmp, &x2Tmp) != 2) break;
            if (x1Tmp == 0 && x2Tmp == 0) break;

            if (x1Tmp > 0 && x1Tmp < MAX && x2Tmp > 0 && x2Tmp < MAX) {
                // Le strade sono bidirezionali 
                Matrice[index][x1Tmp][x2Tmp] = 1;
                Matrice[index][x2Tmp][x1Tmp] = 1;
            }
        }
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    // Esecuzione dei casi registrati
    for (int i = 0; i < index; i++) {
        memset(visitato, 0, sizeof(visitato));
        numeroTotPercosi = 0;

        printf("CASE %d:\n", i + 1);
        visitato[1] = 1;  // Segna il punto di partenza come visitato prima di iniziare
        // Passiamo la sottomatrice del caso i-esimo
        CalcolaSequenza(1, Target[i], Matrice[i], visitato, 0);
        printf("There are %d routes from the firestation to streetcorner %d.\n", numeroTotPercosi, Target[i]);
    }
    system("PAUSE");
    return 0;
}
/*Complessità: O(numeriTest*N!)*/