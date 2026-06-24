#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
// Metodo di stampa semplice
void stampaScenario(Scenario s) {
    printf("%d\n", s.n);
    for (int i = 0; i < s.n; i++)printf("%d ", s.prezzi[i]);
    printf("\n");
}

//Metodo Compare per il qsort
int ComparaValori(const void *a,const void *b){
    int x=*(const int *)a;//conversione puntatori
    int y=*(const int *)b;
    return y-x; //ordino i valori in senso decrescente 
}

void CalcolaSConto(Scenario s){
    int SommaTotale=0;
    //Logica Greedy: prendi ogni terzo elemento
    // Partiamo dall'indice 2 (il terzo elemento), poi 5, 8, ecc.
    // Usiamo il salto di 3 (i += 3)
    for (int i = 2; i < s.n; i+=3){
        SommaTotale+=s.prezzi[i];
    }
    printf("SAMPLE INPUT:\n");
    printf("%d",SommaTotale);
    

}
      