#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {

    CasoTest  TestX[MAX_L];
    int index=0;
   printf("SAMPLE INPUT:\n");
   RiempiCasoTest(TestX);
   printf("SAMPLE OUTPUT:\n");
   ElaboraCasoTest(TestX);
   

    system("pause");
    return 0;
}

/*Complessità: O(N^3) con N valore max importo*/

/*Ricorrenza: Caso Base:DP[0][0]=1
              Caso per ogni i: DP[moneta_usata][sommaT]=DP[moneta_usata][sommaT]+DP[moneta_usata-1][sommaT-moneta_valore]; 
                               per ogni moneta_usata,moneta_valore e sommaT che va da 1 a 300

                DP[moneta_usata][sommaT]=Rappresenta il numero di modi per ottenere la somma sommaT usando esattamente moneta_usata monete.

                DP[moneta_usata-1][sommaT-moneta_valore]: Rappresenta i modi per ottenere la somma rimanente (sommaT-moneta_valore) usando una moneta in meno (moneta_usata-1),
                 prima di aggiungere la moneta attuale di valore moneta_valore

*/