#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
#include <string.h>  // Serve per strcmp()

int main() {
    char parola[20];     // Buffer per leggere parole (IF, ELSE, ecc.)
    int P[100];          // Array che conterrà i codici numerici
    int index = 0;       
    int numP = 0;        // Numero di programmi da leggere
    int stato = 0;       // Conta quanti ENDPROGRAM sono stati letti
    long long Risultato[100];
    printf("SAMPLE INPUT:\n");
    scanf("%d", &numP);
    while (stato != numP) {
        scanf("%s", parola);
        //Conversione:
        if (strcmp(parola, "IF") == 0) {
            // Se la parola è "IF", assegna 1
            P[index++] = 1;
        } else if (strcmp(parola, "ELSE") == 0) {
            // Se la parola è "ELSE", assegna 2
            P[index++] = 2;
        } else if (strcmp(parola, "END_IF") == 0) {
            // Se la parola è "END_IF", assegna 3
            P[index++] = 3;
        } else if (strcmp(parola, "S") == 0) {
            // Se la parola è "S", assegna 4
            P[index++] = 4;
        } else if (strcmp(parola, "ENDPROGRAM") == 0) {
            // Fine di un programma → assegna 5
            P[index++] = 5;
            //Calcolo i percorsi per il programma attuale
            int currentIndex=0;
            Risultato[stato] = CalcoloPercorso(P,&currentIndex);
            // Incrementa il contatore dei programmi letti
            stato++;
            // Reset dell'indice per il prossimo programma
            index = 0;
        }
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < stato; i++)printf("%lld\n",  Risultato[i]);
    
    system("pause"); 
    return 0;
}

/*Complessità: O(N)*/