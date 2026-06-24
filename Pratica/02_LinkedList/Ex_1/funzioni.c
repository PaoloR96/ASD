#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header



/*metodi*/
Node* InitNode(int val){
    //istanzio il nodo
    Node *node=malloc(sizeof(Node));
    node->value=val;
    node->next=NULL;
    return node;
}
void InsertNode(Node** LinkedList, int val){
     Node * newNode=InitNode(val);
     if(*LinkedList==NULL){
        *LinkedList=newNode;
         return;
     }
     Node *current = *LinkedList;
     while(current->next!=NULL)current = current->next;
     // Collega il nuovo nodo all’ultimo
     current->next = newNode;
}

void PrintList(Node* LinkedList) {
    Node* current = LinkedList;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
void SwapNode(Node** LinkedList) {
    if (*LinkedList == NULL || (*LinkedList)->next == NULL)
        return;

    // Trova la metà della lista
    Node* slow = *LinkedList;
    Node* fast = *LinkedList;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Divide la lista in due metà
    Node* secondHalf = slow->next;
    slow->next = NULL;

    // Inverti la seconda metà
    Node* prev = NULL;
    Node* current = secondHalf;
    while (current != NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    secondHalf = prev; // nuova testa della metà destra invertita

    // Ricollega la lista
    slow->next = secondHalf;
}