#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct Node {
    int value;           // dato contenuto nel nodo
    struct Node* next;   // puntatore al prossimo nodo
    struct Node* prev;   // puntatore al precedemte nodo

} Node;
/*Prototipi delle funzioni*/
Node *CreateNode(int val);
void InsertNode(Node **LinkedList,int val);
void PrintListForward(Node* LinkedList);
void PrintListBack(Node* LinkedList);
void DeleteNode(Node** LinkedList,int val);





#endif
