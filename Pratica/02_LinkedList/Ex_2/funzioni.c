#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

Node *InitNode(int val){
    Node *node=malloc(sizeof(Node));
    node->value=val;
    node->next=NULL;
    return node;
}
void InsertNode(Node **LinkedList,int val){
    //instazio il nuovo nodo
    Node *node=InitNode(val);
    /*se la lista è vuota vuol dire che è il primo
    elemento da inserire*/
    if(*LinkedList==NULL){
        *LinkedList=node;
        return;
    }
    /*uso un node di appoggio,con il while faccio 
    scorrere fino all'ultimo elemento che poi vado
    a collegare*/
    Node *current= *LinkedList;
    while(current->next!=NULL) current=current->next;
    current->next=node;
    
}
void PrintList(Node* LinkedList) {
    Node* current = LinkedList;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
void InsertSort(Node **LinkedList) {
    if (*LinkedList == NULL || (*LinkedList)->next == NULL)
        return; // già ordinata o vuota

    Node *sorted = NULL;          // lista ordinata
    Node *current = *LinkedList;  // nodo che stiamo spostando

    while (current != NULL) {
        Node *next = current->next; // salva il prossimo nodo

        // Inserisci current nella posizione giusta di sorted
        if (sorted == NULL || current->value < sorted->value) {
            // Inserisci in testa
            current->next = sorted;
            sorted = current;
        } else {
            // Trova la posizione giusta nella lista ordinata
            Node *scan = sorted;
            while (scan->next != NULL && scan->next->value < current->value)
                scan = scan->next;

            // Inserisci current dopo scan
            current->next = scan->next;
            scan->next = current;
        }

        current = next; // passa al prossimo nodo della lista originale
    }

    *LinkedList = sorted; // aggiorna la testa
}