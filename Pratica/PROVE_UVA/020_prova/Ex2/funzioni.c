#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void InserisciDati(Grafo * G){
    scanf("%d %d",&G->n,&G->k);
    for (int i = 0; i < G->k; i++) scanf("%d %d", &G->K[i][0], &G->K[i][1]);
}

/*Varibili globali*/
int Max = 0;               // Massimo numero di nodi neri trovato finora
int SoluzioneOttima[MAX];  // Per salvare i nodi neri della migliore configurazione
int Colorato[MAX];         // Array dei colori corrente

void ColoraGrafo(int nodo_attuale, Grafo *G) {
    //Condizione di uscita:Colorato  tutti i nodi (da 1 a n)
    if(nodo_attuale>G->n){
        int contatore_corrente = 0;
        //Conto il numero di nodi neri
        for (int i = 1; i < G->n; i++)if(Colorato[i]==1)contatore_corrente++;
        if (contatore_corrente>Max){
            //definisco la soluzione ottima, ossia quali sono i nodi neri colorati
            Max=contatore_corrente;
            for (int i = 1; i < G->n; i++)SoluzioneOttima[i]=Colorato[i];
        }
        return; //terminazione
    }
    //Ricorsione:
    //Tentativo1:Provo a coloro il nodo_attuale di nero
    if(ColoroNero(nodo_attuale,G)){
        Colorato[nodo_attuale]=1; //coloro il nodo di nero
        ColoraGrafo(nodo_attuale+1,G); //passo al nodo successivo
        Colorato[nodo_attuale]=0; //BACKTRACKING :lo coloro bianco
    }
    //Tentativo2:Sempre possibile che il nodo sia bianco
    Colorato[nodo_attuale]=0; // coloro bianco il nodo
    ColoraGrafo(nodo_attuale+1,G); //passo al nodo successivo
}


int ColoroNero(int nodo_attuale, Grafo *G){
    for (int i = 0; i < G->k; i++){//per ogni arco
        /* Per ogni coppia di nodi(u,v) valuto il nodo attuale e tutti i suoi vicini */
        int u=G->K[i][0];
        int v=G->K[i][1];
        // Se il nodo_attuale è uno dei due estremi dell'arco
        //Caso1:Estremo sinistro
        if (u==nodo_attuale){
            if(Colorato[v]==1)return 0; // Conflitto: vicino nero
        //Caso2:Estremo destro
        }else if (v==nodo_attuale){
            if(Colorato[u]==1)return 0; // Conflitto: vicino nero
        }  
    }
    return 1; // Nessun conflitto: può essere NERO
}

    