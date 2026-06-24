#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.h"  // Include il file header

int InsiemeAtt[MAX];
int numeroTotPercosi=0;

void CalcolaSequenza(int valoreAtt,int target,int ListaAdiacenza[MAX][MAX],int visitato[MAX],int pos){
    // 1. Inserisco l'incrocio attuale nel percorso all'indice 'pos'
    InsiemeAtt[pos]=valoreAtt;    
    //2.Condizione di uscita:Ho creato un percorso
    if(valoreAtt==target){
        StampaSequenza(InsiemeAtt,pos);
        numeroTotPercosi++;
        return;

    }
    //3.Creo il percorso
    //3_A:Esploro tutti i vicini in ordine crescente
    for (int prossimo = 1; prossimo <= 20; prossimo++){
        //Passo3_C:Controllo se esiste la strada e se l'incrocio non è già stato visitato
        if (ListaAdiacenza[valoreAtt][prossimo]==1 && !visitato[prossimo]){
            visitato[prossimo]=1;
            CalcolaSequenza(prossimo,target,ListaAdiacenza,visitato,pos+1);
            visitato[prossimo]=0;// BACKTRACKING: libera l'incrocio per altri percorsi
        }
    }
}

void  StampaSequenza(int InsiemeAtt[MAX],int dim){
    for (int i = 0; i <= dim; i++){
        printf("%d \t",InsiemeAtt[i]);
    }
    printf("\n");
    
}