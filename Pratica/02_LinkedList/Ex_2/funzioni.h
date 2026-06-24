#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct Node {
    int value;           // dato contenuto nel nodo
    struct Node* next;   // puntatore al prossimo nodo

} Node;
/*Prototipi delle funzioni*/
Node * InitNode(int val);
void InsertNode(Node **LinkedList,int val);
void PrintList(Node *LinkedList);
/*InsertSort*/
void InsertSort(Node **LinkedList);




#endif
