#include <stdio.h>
#include <stdbool.h>
#include "funzioni.h"

// Definizione della memoria globale per evitare Segmentation Fault
int DP[MAX_A][MAX_L];

int InserisciDati(int V[MAX_A]) {
    int i = 0;
    int len;
    while (scanf("%d", &len) == 1 && len != 0) {
        if (i < MAX_A) {
            V[i] = len;
            i++;
        }
    }
    return i; // Ritorna il numero di auto lette prima dello 0 
}

void InitDP(int DP[MAX_A][MAX_L], int numeroAuto, int lunTraghetto) {
    // Inizializziamo solo la porzione necessaria per il caso corrente
    int limite = lunTraghetto * 100;
    if (limite >= MAX_L) limite = MAX_L - 1;
    
    for (int i = 0; i <= numeroAuto; i++) {
        for (int j = 0; j <= limite; j++) {
            DP[i][j] = 0;
        }
    }
}

void CalcolaDP(int DP[MAX_A][MAX_L], int Auto[MAX_A], int n_auto, int limite_cm) {
    //Stato iniziale: auto caricate, 0 cm a bordo
    DP[0][0] = 1;
    int sommaCumulata = 0;
    int max_auto_caricate = 0;
    
    for (int i = 1; i <= n_auto; i++) { //per ogni auto i
        int Lx = Auto[i - 1]; //lunghezza attuale auto i
        bool caricata = false;

        for (int j = 0; j <= limite_cm; j++) {
            if (DP[i - 1][j]) { // Se lo stato precedente era possibile
                //1. Prova Babordo 
                if (j + Lx <= limite_cm) {
                    DP[i][j + Lx] = 1;
                    caricata = true;
                }
                //2. Prova Tribordo
                //Lo spazio a tribordo è: somma totale finora - spazio a babordo
                int spazio_tribordo = sommaCumulata - j;
                if (spazio_tribordo + Lx <= limite_cm) {
                    DP[i][j] = 1; // La lunghezza a babordo non cambia
                    caricata = true;
                }
            }
        }
        if (!caricata) break; // Se non posso metterla da nessuna parte, mi fermo 
        
        max_auto_caricate = i;
        sommaCumulata += Lx; 
    }

    //stampo massimo auto caricate 
    printf("%d\n", max_auto_caricate);

    //Ricostruzione del percorso 
    int current_j = 0;
    for (int j = 0; j <= limite_cm; j++) {
        if (DP[max_auto_caricate][j]) {
            current_j = j;
            break;
        }
    }

    const char* risposte[MAX_A];
    for (int i = max_auto_caricate; i >= 1; i--) {
        int Lx = Auto[i - 1];
        // Se lo stato dp[i][curr_j] è arrivato da Port
        if (current_j >= Lx && DP[i - 1][current_j - Lx]) {
            risposte[i - 1] = "port"; 
            current_j -= Lx;
        } else {
            risposte[i - 1] = "starboard"; 
        }
    }

    // Stampo le direzioni per ogni auto caricata
    for (int i = 0; i < max_auto_caricate; i++) printf("%s\n", risposte[i]);
}