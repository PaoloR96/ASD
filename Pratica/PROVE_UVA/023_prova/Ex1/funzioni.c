#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

long long CalcoloPercorso(int P[], int *i) {
    long long percorsi = 1;
    // Continua finché non trovi ELSE (2), END_IF (3) o ENDPROGRAM (5)
    while (P[*i] != 2 && P[*i] != 3 && P[*i] != 5) {
        if (P[*i] == 4) { 
            // Caso S: l'istruzione è sequenziale, basta avanzare
            (*i)++; 
        }else if (P[*i] == 1) { 
            // Caso IF: entriamo nel cuore del Dividi et Impera
            (*i)++; // Consuma l'IF
            
            // 1. Dividi: Calcola ricorsivamente il ramo IF fino all'ELSE
            long long RamoIF = CalcoloPercorso(P, i);
            (*i)++; // Consuma l'ELSE dopo il ritorno dalla ricorsione
            // 2. Dividi: Calcola ricorsivamente il ramo ELSE fino all' END_IF
            long long RamoElse = CalcoloPercorso(P, i);
            (*i)++; // Consuma l'END_IF dopo il ritorno dalla ricorsione
            // 3. Impera: Moltiplica il totale per la somma dei due rami
            percorsi *= (RamoIF + RamoElse);
        }
    }
    return percorsi;
}