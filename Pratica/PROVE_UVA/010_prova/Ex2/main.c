#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    // Definizione dei casi di test basati sul Sample Input
    Posizione test_cases[] = {
        {0, 'e', 2, 'e', 4},
        {1, 'a', 1, 'b', 2},
        {2, 'b', 2, 'c', 3},
        {3, 'a', 1, 'h', 8},
        {4, 'a', 1, 'h', 7},
        {5, 'h', 8, 'a', 1},
        {6, 'b', 1, 'c', 3},
        {7, 'f', 6, 'f', 6}
    };
    //Definizione parametri per generare l'output
    Percorso ListaMosse[64];
    Coppia mossaAtt;

    //1.Stampa mosse
    printf("Sample Input:\n");
    stampaMosse(test_cases,8);
    //2.Elaborazione e Stampa mosse min
    printf("\nSample Output:\n");

    for (int i = 0; i < 8; i++) {
        // Inizializziamo recordMin a un valore alto per ogni test 
        recordMin = 64; 
        // Definiamo le coordinate numeriche di partenza,ovvero dal caso di test iesimo
        mossaAtt.x = LetteraInNumero(test_cases[i].start_col);
        mossaAtt.y = test_cases[i].start_row;
        // Segnamo la casella di partenza come visitata nel percorso
        ListaMosse[0].start = test_cases[i].start_col;
        ListaMosse[0].end = test_cases[i].start_row;
        // Eseguiamo il backtracking
        TrovaPercorso(test_cases[i], mossaAtt, ListaMosse, 0);
        // Stampa finale
        printf("To get from %c%d to %c%d takes %d knight moves.\n", 
               test_cases[i].start_col, test_cases[i].start_row, 
               test_cases[i].end_col, test_cases[i].end_row, recordMin);
    }

    printf("\n");
    system("pause"); // Mantiene aperta la console su Windows
    return 0;
}

/*Complessità:O(k^d) 
con k=numero di scelte/mosse(8)
d=numero di volte che faccio quella scelta per raggiungere l'obiettivo(cont)

*/