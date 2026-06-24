#ifndef FUNZIONI_H
#define FUNZIONI_H
//definizione nodo
typedef struct Node {
    int value;           // dato contenuto nel nodo
    struct Node* next;   // puntatore al prossimo nodo
} Node;
// Prototipi delle funzioni lista
Node *CreateNode(int value);
void InsertNode(Node **LinkedList,int value);
void PrintList(Node *LinkedList);
Node * MiddleNode(Node *LinkedList);
void SumHalflist(Node *LinkedList);



#endif
