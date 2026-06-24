#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {

    int dp[DIM_N][DIM_K];
    int C[DIM_N][DIM_K];
    int N[DIM_N], K[DIM_N];
    int index = 0;
    int NumeriTest = 0;
    printf("SAMPLE INPUT:\n");
    scanf("%d", &NumeriTest);
    while (NumeriTest != 0) {
        scanf("%d", &N[index]);
        scanf("%d", &K[index]);
        for (int i = 0; i < N[index]; i++) scanf("%d", &C[index][i]);
        index++;
        NumeriTest--;
    }
    NumeriTest=index;
    index=0;
    printf("\n");
    printf("SAMPLE OUTPUT:\n");
     
    while (NumeriTest != 0) {
      // 1. Pulisci la matrice per il caso attuale
      InitDp(dp, K[index], N[index]);
      // 2. Esegui il calcolo della ricorrenza
      CalcolaDp(dp, C[index],K[index], N[index]);
      // 3. Verifica se il resto 0 è raggiungibile dopo l'ultimo numero
      // L'indice dell'ultimo numero è N-1 
      if (dp[N[index] - 1][0] == 1) {
        printf("Divisible\n"); 
      } else {
      printf("Not divisible\n");
      }  
      index++;
      NumeriTest--;
    }
    system("PAUSE");
    return 0;
}
/*Complessità O(M*N*K) 
  con M= numero casi da analizzare
  con N=Numero di elementi della iesima sequenza
  con K=k possibili resti


Ricorrenza:
  Caso Base (Primo numero):
  Il primo intero determina il resto di partenza senza operatori precedenti.
  dp[0][(|C[0]| mod K)] = 1

  Passo Induttivo (Numeri successivi):
    Per ogni numero C[i] (con 1 <= i < N) e per ogni resto r che era possibile ottenere al passo precedente (dp[i-1][r] == 1):
      NuovoRestoSomma = (r + (|C[i]| mod K)) mod K
      NuovoRestoSottrazione = (r - (|C[i]| mod K) + K) mod K
      Si imposta:
        dp[i][NuovoRestoSomma] = 1
        dp[i][NuovoRestoSottrazione] = 1

*/