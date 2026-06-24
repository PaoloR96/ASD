#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
Node *CreateNode(int value){
     Node* node=malloc(sizeof(Node));
     node->value=value;
     node->next=NULL;
     return node;
}
void InsertNode(Node **LinkedList,int value){ 
    Node *currentNode=CreateNode(value);
    if(*LinkedList==NULL){
        *LinkedList=currentNode;
        return;
    }
    Node* tmpList= *LinkedList;
    while(tmpList->next!=NULL)tmpList=tmpList->next;
    tmpList->next=currentNode;

}
void PrintList(Node *LinkedList){
     Node* tmpList= LinkedList;
     while(tmpList->next!=NULL){
        printf("%d -> ",tmpList->value);
        tmpList=tmpList->next;
     }
     printf("NULL\n");

}
Node * MiddleNode(Node *LinkedList){
    if(LinkedList==NULL)return LinkedList;

    Node * fast=LinkedList->next,*slow=LinkedList;
     while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}
// Divide la lista a metà e somma i valori di ciascuna parte
void SumHalflist(Node *LinkedList){
    if (LinkedList == NULL) return;

    Node *middle = MiddleNode(LinkedList);
    Node *rightHalf = middle->next;
    middle->next = NULL;  // divide la lista
    Node *leftHalf = LinkedList;

    printf("\nParte destra:\n");
    PrintList(rightHalf);

    int sommaDestra = 0;
    while (rightHalf != NULL) {
        sommaDestra += rightHalf->value;
        rightHalf = rightHalf->next;
    }
    printf("Somma parte destra: %d\n", sommaDestra);

    printf("\nParte sinistra:\n");
    PrintList(leftHalf);

    int sommaSinistra = 0;
    while (leftHalf != NULL) {
        sommaSinistra += leftHalf->value;
        leftHalf = leftHalf->next;
    }
    printf("Somma parte sinistra: %d\n", sommaSinistra);
}
