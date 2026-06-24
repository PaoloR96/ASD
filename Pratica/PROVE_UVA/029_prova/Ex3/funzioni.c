#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
// Inizializzazione: le stringhe vuote sono corrette
void InitDP(int DP[MAX][MAX], int N){
    for (int i = 0; i <= N; i++) {
        if (i > 0) DP[i][i-1] = 1; // Intervallo vuoto (base per la regola c)
        DP[i][i] = 0;              // Lunghezza 1: sempre Falso
    }

}
int DP[MAX][MAX];
void CalcolaDP(int DP[MAX][MAX], char Seq[], int N){
    //1_CasoBase:Inizializzo DP
    InitDP(DP,N);
    //2_Ricorrenza
    for (int len = 2; len <= N; len++){// len: lunghezza della sottostringa da analizzare (da 2 a N)
        //Devo definire l'intervallo di inizio e di fine della mia sottostringa da poter analizzare
        for (int i = 0; i <= N-len; i++){//i rappresenta l'intervallo di inizio
            int j=i+len-1; // j raprresenta l'intervallo di fine
            //(i,j) rappresenta il mio intervallo di osservazione
            //A:Verifico la regola C (Racchiudimento)
            if ((Seq[i]=='(' && Seq[j]==')')||Seq[i]=='[' && Seq[j]==']'){
                // Se len è 2 (es. "()") o se l'interno DP[i+1][j-1] è corretto
                if (len==2 ||DP[i+1][j-1])DP[i][j]=1;
            }
            //B: Verifico la REGOLA B  (Concatenazione)
            // Se non è già corretta, prova a dividerla in due parti S[i..k] e S[k+1..j]
            if (!DP[i][j]){
                for (int k = i; k < j; k++){
                    if (DP[i][k] && DP[k+1][j]){
                        DP[i][j] = 1;
                        break; // Trovata una divisione valida, passa alla prossima sottostringa
                    }
                    
                }  
            }
        } 
    }
}
