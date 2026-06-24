#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
// Funzione per stampare un campo
void stampaCampo(int N, char campo[]) {
    printf("N = %d, campo = ", N);
    for (int i = 0; i < N; i++) {
        printf("%c", campo[i]);
    }
    printf("\n");
}
/*{"...##....##"}*/
void CalcolaSoluzione(int N, char campo[]){
    int conteggio=0;
    for (int i = 0; i < N; ){//per ogni punto del campo 
        
        if(campo[i]=='.'){  // Abbiamo trovato una sezione utile che richiede copertura
            conteggio++;    // Piazziamo uno spaventapasseri
            i+=3;           //saltiamo direttamente di 3 posizion
        }else{
            i++; // campo sterile passo alla cella successiva
        }
    }
    printf("%d\n", conteggio);
}
