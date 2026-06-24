#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

Node *CreateNode(int val){
    Node* node = malloc(sizeof(Node));
    node->value=val;
    node->next=NULL;
    node->prev=NULL;
    return node;
}
void InsertNode(Node** LinkedList, int val){
    Node * newNode=CreateNode(val);
    if(*LinkedList==NULL){
        *LinkedList=newNode;
         return;
    }
   Node *current = *LinkedList;
    while(current->next!=NULL)current = current->next;
    // Collega il nuovo nodo all’ultimo
    current->next = newNode;
    newNode->prev = current;
          
}
void DeleteNode(Node **LinkedList, int val) {
    if (*LinkedList == NULL) return; // lista vuota
    Node *current = *LinkedList;
    // cerca il nodo con il valore val
    while (current != NULL && current->value != val) current = current->next;
    if (current == NULL) return; // nodo non trovato

    // caso 1: il nodo da eliminare è la testa
    if (current->prev == NULL) {
        *LinkedList = current->next;
        if (current->next != NULL)current->next->prev = NULL;
    }
    // caso 2: il nodo da eliminare è in mezzo
    else if (current->next != NULL) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    // caso 3: il nodo da eliminare è l'ultimo
    else {
        current->prev->next = NULL;
    }

    free(current); // libera la memoria del nodo eliminato
}

void PrintListForward(Node* LinkedList) {
    Node* current = LinkedList;
    printf("Lista in avanti: ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void PrintListBack(Node* LinkedList) {

    // vai all’ultimo nodo
    Node* current = LinkedList;
    while (current->next != NULL) current = current->next;
    
    // stampa all’indietro
    printf("Lista all' indietro: ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->prev;
    }
    printf("NULL\n");
}
