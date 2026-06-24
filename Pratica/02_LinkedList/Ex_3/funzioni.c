#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

/*Metodi*/
Node * InitNode(int value){
        Node *node=malloc(sizeof(Node));
        node->value=value;
        node->next=NULL;
        return node;   
}
void InsertNode(Node **LinkedList, int value) {
    Node *newNode = InitNode(value);
    if (*LinkedList == NULL) {
        *LinkedList = newNode;
        return;
    }
    Node *ListCurrent = *LinkedList;
    //scorro fino all'ultimo elemento
    while (ListCurrent->next != NULL)ListCurrent = ListCurrent->next;
    //iserisco il nodo
    ListCurrent->next = newNode;
}
void PrintList(Node *LinkedList) {
    Node *ListCurrent = LinkedList;
    while (ListCurrent != NULL) {
        printf("%d -> ", ListCurrent->value);
        ListCurrent = ListCurrent->next;
    }
    printf("NULL\n");
}
/*Metodi MergeSort*/
Node* GetMiddle(Node *LinkedList){
    if(LinkedList==NULL)return LinkedList;
    Node* slow = LinkedList;
    Node* fast = LinkedList->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;

}
Node* MergeSort(Node* LinkedList) {
     // Caso base: lista vuota o con un solo elemento
    if (LinkedList == NULL || LinkedList->next == NULL)return LinkedList;
    //definisco il punto medio q
    Node *q=GetMiddle(LinkedList);
    // Divido in due sotto-liste: L e R
    Node *R=q->next;
    q->next = NULL; // separa le due metà
    Node *L=LinkedList;
    // Ordino ricorsivamente la parte sinistra e destra
    L = MergeSort(L);   // MergeSort(A, p, q)
    R = MergeSort(R);   // MergeSort(A, q+1, r)
    LinkedList=Merge(L,R);
    return LinkedList;
}






Node* Merge(Node *left, Node *right){
     // Casi base
     if (left == NULL) return right;
     if (right == NULL) return left;
     // Nodo di partenza del risultato
     Node* current = NULL;
     // Seleziona il più piccolo tra L e R, come nell’if(L[i] <= R[j])
     if(left->value<=right->value){
        current=left;
        current->next=Merge(left->next, right);
     }else{
        current=right;
        current->next=Merge(right->next, left);
     }
     return current;

}