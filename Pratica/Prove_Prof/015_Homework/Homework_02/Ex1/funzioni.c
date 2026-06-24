#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
Node * CreateNode(int key){
    Node *newNode=malloc(sizeof(Node));
    if (newNode!=NULL){
        newNode->value=key;
        newNode->next=NULL;
        newNode->prev = NULL;
    }
    return newNode;
}
Node* CreaListaNodi(int A[], int dim){
    Node *ListaNodi = NULL; // Punta alla testa della lista
    Node *Coda = NULL;      // Punta all'ultimo elemento inserito
    Node *NuovoNodo = NULL;
    for (int i = 0; i < dim; i++){
            // 1. Creo il nodo
            NuovoNodo = CreateNode(A[i]);
            // 2. Controllo le varie casistiche:
            if(NuovoNodo == NULL) return NULL; 
            if (ListaNodi == NULL){
                // Inserisco il primo elemento
                ListaNodi = NuovoNodo;
                Coda = NuovoNodo; // All'inizio testa e coda coincidono
            } else {
                // Inserisco i restanti elementi agganciandoli alla coda
                Coda->next = NuovoNodo;       // Il vecchio ultimo punta al nuovo
                NuovoNodo->prev = Coda;       // Il nuovo punta all'indietro al vecchio
                Coda = NuovoNodo;             // Aggiorno la coda
            }
    }
    return ListaNodi;
}

void StampaLista(Node *ListaNodi){
    Node *NodoCorrente=ListaNodi;
    while (NodoCorrente!=NULL){
        printf("%d\n",NodoCorrente->value);
        NodoCorrente=NodoCorrente->next;//passo al nodo successivo
        
    }
    
}



void InvertiLista(Node *ListaNodi){
    // Se la lista è vuota o ha un solo elemento, non c'è nulla da invertire
    if (ListaNodi == NULL || ListaNodi->next == NULL) return;

    // 1. TROVO IL PUNTO MEDIO (Tecnica Fast & Slow)
    Node *slow = ListaNodi;
    Node *fast = ListaNodi;

    // Poiché la lista ha 2n elementi, fast arriverà esattamente a NULL
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;          // Avanza di 1
        fast = fast->next->next;    // Avanza di 2
    }

    // A questo punto 'slow' è l'(n+1)-esimo elemento
    Node *InizioSecondaMeta = slow;
    Node *FinePrimaMeta = slow->prev;

    // 2. SPEZZARE LA LISTA
    // Svincoliamo temporaneamente i due tronconi per facilitare l'inversione
    FinePrimaMeta->next = NULL;
    InizioSecondaMeta->prev = NULL;

    // 3. INVERTIRE LA SECONDA METÀ 
    Node *Corrente = InizioSecondaMeta;
    Node *NodoTmp = NULL;
    Node *UltimoElaborato = NULL;

    while (Corrente != NULL){
        NodoTmp = Corrente->prev;
        Corrente->prev = Corrente->next;
        Corrente->next = NodoTmp;

        UltimoElaborato = Corrente; // Tengo traccia del nodo per farlo diventare la nuova testa
        Corrente = Corrente->prev;  // Passo al prossimo (uso prev perché i campi sono scambiati)
    }

    Node *NuovaTestaSecondaMeta = UltimoElaborato;

    // 4. RICUCIRE LA LISTA
    // La fine della prima metà deve puntare al nuovo inizio della seconda metà
    FinePrimaMeta->next = NuovaTestaSecondaMeta;
    if (NuovaTestaSecondaMeta != NULL){
        NuovaTestaSecondaMeta->prev = FinePrimaMeta;
    }
}