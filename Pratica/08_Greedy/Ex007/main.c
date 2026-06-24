#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"



int main() {
    static Caso caso[4]; 
    int i = 0;

    printf("SAMPLE INPUT:\n");
    //Lettura dati input: riempiamo la tua struttura fino a EOF
    while (i < MAX_N && scanf("%d %d %d", &caso[i].n, &caso[i].l, &caso[i].w) == 3) {
        
        // Leggiamo i dati di posizione e raggio per ogni irrigatore 
        for (int j = 0; j < caso[i].n; j++) scanf("%d %d", &caso[i].irr[j].posizione, &caso[i].irr[j].raggio);
        i++;
    }
    int fine = i;
    
    printf("SAMPLE OUTPUT:\n");
    for (int k = 0; k < fine; k++) {
        // Calcolo degli intervalli effettivi basati sulla larghezza della striscia
        calcolaIntervalli(caso[k].irr, caso[k].n, caso[k].w);
        
        // Ordinamento degli intervalli
        qsort(caso[k].irr, caso[k].n, sizeof(Irrigatore), ComparaValori);
        
        // Calcolo del numero minimo di irrigatori necessari
        int n_risultato = RisolviSequenza(caso[k].irr, caso[k].n, (double)caso[k].l);
        
        // Stampa il risultato
        printf("%d\n", n_risultato);
    }
    system("pause");
    return 0;
}
/*COmplessità:O(n*logn)*/