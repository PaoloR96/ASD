#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void InserisciCasoTest(CasoTest *T, int lTmp) { 
    T->l = lTmp; // Lunghezza totale
    scanf("%d", &T->n);
    
    T->punti[0] = 0; // Il punto iniziale deve essere 0
    for (int i = 1; i <= T->n; i++) {
        scanf("%d", &T->punti[i]); // I tagli dell'utente vanno da indice 1 a N
    }
    T->punti[T->n + 1] = lTmp; // L'ultimo punto è la lunghezza L
}
int DP[MAX_N][MAX_N];
void InizializzaDP(int DP[MAX_N][MAX_N],int N){
    for (int i = 0; i < N+2; i++){
        for (int j = 0; j < N+2; j++){
            if (j==i+1){
                DP[i][j]=0;
            }else{
                DP[i][j]=INT_MAX;
            }
        }
    }
}


int CalcolaDP(int DP[MAX_N][MAX_N], int P[MAX_N], int N) {
    // Il primo ciclo 'd' definisce la distanza tra gli indici dei punti di taglio.
    // d=2 significa che stiamo considerando un segmento che contiene un solo taglio
    // d arriva a N+1 perché copre l'intero bastone.
    for (int d = 2; d <= N + 1; d++) {
        // Calcoliamo il limite superiore per l'indice di inizio 'i' in modo che
        // il punto di fine 'j' non superi mai l'ultimo indice disponibile (N+1)
        int dim = N + 1 - d;
        for (int i = 0; i <= dim; i++) {
            // j è il punto finale della "finestra" che stiamo analizzando
            int j = i + d;  
            // Proviamo ogni possibile punto di taglio intermedio 'k' tra l'inizio 'i' e la fine 'j'
            for (int k = i + 1; k < j; k++) {
                
                // La formula di ricorrenza:
                // 1. DP[i][k]: costo minimo per tagliare la parte sinistra.
                // 2. DP[k][j]: costo minimo per tagliare la parte destra.
                // 3. (P[j] - P[i]): costo del taglio attuale (lunghezza del bastone corrente).
                int costo_attuale = DP[i][k] + DP[k][j] + (P[j] - P[i]);
                // Aggiorniamo la cella con il valore minimo trovato tra tutte le possibili scelte di 'k'
                DP[i][j] = min2(DP[i][j], costo_attuale);
            }    
        } 
    }
    // Il risultato finale si trova nella cella che rappresenta l'intero bastone:
    // dal primo punto (0) all'ultimo punto (N+1)
    return DP[0][N+1];
}

int min2(int a, int b){
    return (a<b)?a:b;
}