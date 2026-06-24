#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

Node* InitNode(int val) {
    Node* node = malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
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
void DeleteNode(Node** LinkedList, int val){
      if (*LinkedList == NULL) return; // lista vuota
      Node* current = *LinkedList;
      Node* prev = NULL;
      // cerca il nodo con il valore val
      while (current != NULL && current->value != val) {
            prev=current;
            current = current->next;
    
     } 
     if (current == NULL) return; // nodo non trovato
     if (prev == NULL) {
        // nodo da eliminare è la testa
        *LinkedList = current->next;
    } else {
        // nodo da eliminare è nel mezzo o alla fine
        prev->next = current->next;
    }

    free(current); // libera memoria

}
int SearchNode(Node** LinkedList, int val) {
    Node* current = *LinkedList;

    while (current != NULL) {
        if (current->value == val) {
            return 1;  // nodo trovato
        }
        current = current->next;
    }
    return 0; // nodo non trovato
}
