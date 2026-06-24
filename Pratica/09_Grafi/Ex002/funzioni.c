#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"
/*Metodo per convertire il carattere in un indice*/
int charToIndex(char c) {
    return c - 'A';
}
/*Inizializzo il nodo*/
Nodo * CreaNodo(int v) {
    Nodo * newNodo = (Nodo*)malloc(sizeof(Nodo));
    if(newNodo != NULL){
        newNodo->v_indice = v;
        newNodo->next = NULL;
    }
    return newNodo;
}
/*Creo i nodi e li collego aggiornado la lista di adiacenza*/
void AggiungiCollegamento(Arco arco[], int u, int v) {
    // Aggiungo v alla lista di u
    Nodo *NodoV = CreaNodo(v);
    NodoV->next = arco[u].testa;
    arco[u].testa = NodoV;

    // Aggiungo u alla lista di v
    Nodo *NodoU = CreaNodo(u);
    NodoU->next = arco[v].testa;
    arco[v].testa = NodoU;
}

void RiempiCasoDiTest(CasoTest test[], int dim) {
    char linea[10];
    for (int i = 0; i < dim; i++) {
        // Leggo il carattere massimo per il caso corrente 
        if (scanf(" %c", &test[i].c) != 1) return;
        
        // Inizializzo le liste e i visitati
        for (int k = 0; k < MAX; k++) {
            test[i].arco[k].testa = NULL;
            test[i].visitato[k] = 0;
        }

        // Leggo i collegamenti (coppie di lettere) finché sono validi
        while (scanf("%s", linea) == 1 && strlen(linea) == 2) {
            int u = charToIndex(linea[0]);
            int v = charToIndex(linea[1]);
            AggiungiCollegamento(test[i].arco, u, v);
        }
    }
}

void dfs(int attuale, Arco arco[], int visitato[]) {
    visitato[attuale] = 1; // Segno il nodo corrente come visitato
    Nodo * NodoCorrente = arco[attuale].testa;//uso nodo d'appoggio per scorrere la lista di adiacenza
    
    while (NodoCorrente != NULL) {
        int vicino = NodoCorrente->v_indice;
        if (visitato[vicino] == 0) {
            dfs(vicino, arco, visitato);
        }
        NodoCorrente = NodoCorrente->next;
    }
}

void ElaboraCasiDiTest(CasoTest test[], int dim) {
    for (int i = 0; i < dim; i++) {
        int nodoMax = charToIndex(test[i].c);
        int NumSottoGrafiConnessi = 0;

        // Scorro tutti i nodi da 'A' al nodoMax 
        for (int j = 0; j <= nodoMax; j++) {
            if (test[i].visitato[j] == 0) {
                // Se trovo un nodo non visitato, ho trovato una nuova componente
                NumSottoGrafiConnessi++;
                dfs(j, test[i].arco, test[i].visitato);
            }
        }
        printf("%d\n", NumSottoGrafiConnessi);
        if (i < dim - 1) printf("\n");
    }
}