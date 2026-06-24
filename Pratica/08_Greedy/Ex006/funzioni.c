#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

int ComparaValori(const void *a, const void *b){
    Station *s1 = (Station *)a;
    Station *s2 = (Station *)b;
    if(s1->left == s2->left)
        return s2->right - s1->right; // decrescente per 'right'
    return s1->left - s2->left;       // crescente per 'left'
}



//Funzione che calcola gli intervalli di copertura di ogni stazione
 void CalcolaIntervalli(Station stations[], int g, Station sequenza[], int L){ 
    for (int i = 0; i < g; i++){
        int left = stations[i].left - stations[i].right;   // x - r
        int right = stations[i].left + stations[i].right;  // x + r

        // Limiti della strada
        if(left < 0) left = 0;
        if(right > L) right = L;

        sequenza[i].left = left;
        sequenza[i].right = right;
    }
}





//Funzione che calcola quante stazioni possono essere chiuse usando algoritmo greedy
  
int OttieniRisultatoCopertura(Station s[MAXG], int G, int L){
    int current_end = 0;  // Estremo destro coperto finora
    int i = 0;            // Indice stazioni
    int used = 0;         // Numero stazioni effettivamente usate

    // Copriamo la strada fino a L
    while(current_end < L){
        int best = current_end;  // Miglior estremo che possiamo raggiungere in questo passo

        // Logica Greedy:Trova la stazione che estende più in avanti la copertura
        while(i < G && s[i].left <= current_end){
            if(s[i].right > best) best = s[i].right;
            i++;
        }

        // Se non possiamo estendere la copertura allora è impossibile
        if(best == current_end){
            //printf("-1\n");
            return-1;  // Termina la funzione
        }

        // Aggiorna estremo coperto e incrementa stazioni usate
        current_end = best;
        used++;
    }

    // Numero massimo di stazioni che possono essere chiuse
    //printf("%d\n", G - used);
     return G-used;
}       
