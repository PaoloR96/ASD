#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

// Definizione  delle variabili
char Risultato[2000];
int idx = 0;


void CalcolaSequenza(int m,int n, Nodo R, Nodo L){
    // 1. Calcola il nodo corrente
    int curr_num=L.num+R.num;
    int curr_den=L.den+R.den;
    //2.Condizione di uscita
    if (curr_num==m && curr_den==n){
        Risultato[idx]='\0';//Chiudo la sequenza
        return;
    }
    //3.Confronto e Ricorsione
    if (m*curr_den<n*curr_num){
        //Vado a sinistra 'L'
        Risultato[idx++]='L';
        // Il nodo corrente diventa il nuovo confine DESTRO
        R.num=curr_num;
        R.den=curr_den;
    }else{
        //Vado a destra 'R'
        Risultato[idx++]='R';
        // Il nodo corrente diventa il nuovo confine SINISTRO
        L.num=curr_num;
        L.den=curr_den;
    }
    //Chiamata ricorsiva per il livello successivo
     CalcolaSequenza(m,n,R,L);
}

void StampaSequenza() {
    printf("%s\n", Risultato);
}
