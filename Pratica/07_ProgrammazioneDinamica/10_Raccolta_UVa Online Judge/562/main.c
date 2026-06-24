#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int dp[M];
    int m=4;//numero monete nelle borsa
    int monete [M]  = {1,2,4,6}; //insieme di monete presenti nella borsa
    //1.Calcolo l'intero importo
    int somma=SommaMonete(monete,m);
    //2.Inizializzo Dp
    InitDp(dp,(somma/2)+1);
    //3.CalcolaDp deve restituire 'i', ovvero la somma massima possibile <= somma/2
    int val=CalcolaDp(monete,dp,somma/2,m);
    //4.Calcolo della differenza minima positiva
    int valorefinale=somma-(2*val);
    printf("%d\n",valorefinale);
    system("PAUSE");
    return 0;
}

/*
Complessità: O(m*target)dove :
        m è il numero di monete nel bagaglio
        target=somma/2

Ricorrenza:dp[i][s] = dp[i-1][s] OR dp[i-1][s - valore_moneta_i]Dove:

dp[i-1][s]:
Rappresenta il caso in cui non prendi la moneta i.
Se la somma s era già raggiungibile con le monete precedenti, lo è ancora.

dp[i-1][s - valore_moneta_i]:
Rappresenta il caso in cui prendi la moneta i.
Se era possibile formare la somma (s - valore_moneta_i) con le monete precedenti,
aggiungendo la moneta attuale ottieni esattamente s.

OR (operatore logico):
La somma s è possibile se almeno una delle due condizioni sopra è vera.
    
*/