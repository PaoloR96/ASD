#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    CasoTest Test[MAX_T];
    int index=0;
    int T_input;
    printf("SAMPLE INPUT:\n");
    // Leggo il numero di casi di test
    scanf("%d", &T_input);
    while (index < T_input && index < MAX_T){
        //1.Leggo numero incroci e numero strade
        scanf("%d %d", &Test[index].v, &Test[index].e);
        //2.Riempio la mappa
        RiempiCasoTest(Test[index].Mappa,Test[index].e);
        //passo al caso di test successivo
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++) {
        //1.RESET per ogni caso di test delle variabili globali
        trovato_valido = 0;
        min = MAX; 
        for (int j = 0; j < MAX; j++) PosizionaGuardia[j] = 0;
        

        //2.Avvio del backtracking dall'incrocio 0
        Risolvi(0, Test[i].Mappa, Test[i].e, Test[i].v);

        // Stampa il risultato
        if (trovato_valido) {
            printf("%d\n", min);
        } else {
            printf("-1\n");
        }
    }
    system("PAUSE");
    return 0;
}
/*compl O(T*2^N)*/