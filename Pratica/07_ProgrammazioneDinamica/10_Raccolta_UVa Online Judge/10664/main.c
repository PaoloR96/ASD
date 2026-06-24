#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
        int dp[MAX_N][WEIGHT_N];
        int dimTest=3;
        TestCase tests[TEST_CASES] = {
            {5,  {1, 2, 1, 2, 1}},
            {10, {2, 3, 4, 1, 2, 5, 10, 50, 3, 50}},
            {20, {3, 5, 2, 7, 1, 7, 5, 2, 8, 9, 1, 25, 15, 8, 3, 1, 38, 45, 8, 1}}
        };
        //1.Stampa casi di test
        printf("SAMPLE INPUT:\n");
        StampaCasiTest(tests,dimTest);
        printf("SAMPLE OUTPUT:\n");
        //2.Analizziamo ogni singolo caso di Test
        for (int i = 0; i < dimTest; i++) {
              //a.Sommo le wights di ogni caso di test
              int somma = Somma(tests[i].weights, tests[i].n);
              // Gestione somma dispari 
              if (somma % 2 != 0) {
                  printf("NO\n");
                  continue;
              }
              //b. Definisco il target ed inizializzo la mia dp[MAX_N][WEIGHT_N]
              int target=somma/2;
              InitDp(dp,tests[i].n,target);
              //c. Calcolo la ricorrenza
              int possibile=CalcolaDp(dp,tests[i].weights,tests[i].n,target);
              if (possibile) 
                  printf("YES\n");            // Output richiesto: YES 
              else printf("NO\n");           // Output richiesto: NO
         }
        system("PAUSE");
        return 0;
}

/*

Complessità: O(TEST_CASES*MAX_N*TARGET)


Ricorrenza:dp(i, j) = dp(i-1, j) OR dp(i-1, j - W[i])

Dove:

- dp(i-1, j):
  Non prendo la valigia i.
  Se potevo già ottenere il peso j con le valigie precedenti, posso farlo ancora.

- dp(i-1, j - W[i]):
  Prendo la valigia i.
  Posso ottenere il peso j se potevo ottenere il peso (j - W[i])
  usando le valigie precedenti.
  Questa opzione è valida solo se j >= W[i].

*/
