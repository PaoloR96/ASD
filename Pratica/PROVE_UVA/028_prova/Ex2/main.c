#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"

int main() {
    printf("SAMPLE INPUT:\n");
    CasoTest T[100]; 
    int num_casi = 0, t = 0;
    
    if (scanf("%d", &t) != 1) return 0;
    
    while (num_casi < t) {
        scanf("%d %d", &T[num_casi].r, &T[num_casi].c);
        RiempiMappa(T[num_casi].Mappa, T[num_casi].r, T[num_casi].c);
        num_casi++;
    }

    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < num_casi; i++) {
        // Reset della variabile globale per ogni nuovo caso di test
        idx = 0; 
        Posizione pos_part = TrovaCoordinate(T[i].Mappa, T[i].r, T[i].c, '@'); 
        Posizione pos_arrivo = TrovaCoordinate(T[i].Mappa, T[i].r, T[i].c, '#'); 
        TrovaSequenza(T[i].Mappa, T[i].r, T[i].c, pos_part, pos_arrivo);
    }

    system("pause");
    return 0;
}

/*Complessità:O(T*L) dove T è il numero di casi di test L lunghezza sequnza target*/