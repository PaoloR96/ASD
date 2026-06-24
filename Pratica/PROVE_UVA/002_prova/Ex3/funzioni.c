#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void InitDP(int dp[W]){
    for (int i = 0; i < W+1; i++)dp[i]=0;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
int CalcolaDP(int dp[W],Oggetto oggetto[N],int dim,int mw[MW],int g){
        
    for (int x = 0; x < dim; x++){//per ogni oggetto x
            int peso_x=oggetto[x].peso;//peso attuale dell'oggetto x selezionato
            int prezzo_x=oggetto[x].prezzo;//peso attuale dell'oggetto x selezionato
            for (int w = W; w >= peso_x; w--){
                    dp[w] = max(dp[w], dp[w - peso_x] + prezzo_x);  // Usiamo max per decidere se conviene aggiungere l'oggetto x
            }
    }
    //Calcolo del valore totale per tutta la famiglia
    int total_val = 0;
    for (int i = 0; i < g; i++) {
        // Ogni persona i-esima ha una sua capacità specifica mw[i]
        // Sommiamo il valore massimo corrispondente a quella capacità
        total_val += dp[mw[i]];
    }
    return total_val;

}