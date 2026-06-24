#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"

int main() {
    // Strutture per memorizzare i dati
    int n;
    CasoTest soluzioneCorretta;
    CasoTest studenti[100]; // Array per memorizzare fino a 100 studenti
    int numStudenti = 0;
    int DP[MAX+1][MAX+1];

    printf("SAMPLE INPUT:\n");
    
    // 1. FASE DI INSERIMENTO
    // Leggiamo numero eventi
    if (scanf("%d", &n) != 1) return 0;
    // Leggiamo la soluzione corretta
    for (int i = 0; i < n; i++) {
        scanf("%d", &soluzioneCorretta.posizione[i]);
        soluzioneCorretta.Sequenza[i] = i + 1;
    }
    //Inserimento sequenza studenti
    while (numStudenti < 100) {
        int primoValore;
        if (scanf("%d", &primoValore) != 1) break;
        //Inserisco il primo valore e aggiorno la sequenza
        studenti[numStudenti].posizione[0] = primoValore;
        studenti[numStudenti].Sequenza[0] = 1;
        //Inserisco le altre sequenze
        for (int j = 1; j < n; j++) {
            scanf("%d", &studenti[numStudenti].posizione[j]);
            studenti[numStudenti].Sequenza[j] = j + 1;
        }
        numStudenti++;
    }

    printf("SAMPLE OUTPUT:\n");

    // 2. FASE DI ELABORAZIONE
    // 1. Ordinamento Soluzione Corretta
    OrdinaCaso(&soluzioneCorretta, n);

    for (int s = 0; s < numStudenti; s++) {
        // 1. Ordinamento Studente
        OrdinaCaso(&studenti[s], n);
        // 2. Inizializza la DP
        InizializzaDP(DP, n);
        
        // 3. Calcola la DP (LCS) 
        int punteggio = CalcolaSequenzaDP(DP, soluzioneCorretta.Sequenza, studenti[s].Sequenza, n);
        
        // Stampa il risultato per ogni studente 
        printf("%d\n", punteggio);
    }

    system("pause");
    return 0;
}

/*
Ricorrenza:
        if(sequenzaCorretta[i-1]==SequenzaStudente[j-1])DP[i][j]=DP[i-1][j-1]+1;
        if(sequenzaCorretta[i-1]!=SequenzaStudente[j-1])DP[i][j]=max2(DP[i-1][j],DP[i][j-1]);
Complessità:O(N^2) con N dimensione delle due sequenze
                    
*/