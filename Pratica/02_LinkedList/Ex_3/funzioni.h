#ifndef FUNZIONI_H
#define FUNZIONI_H
/*definizione nodo*/
typedef struct Node {
    int value;           // dato contenuto nel nodo
    struct Node* next;   // puntatore al prossimo nodo

} Node;
/*prototipi lista */
Node * InitNode(int value);
void InsertNode(Node ** LinkedList,int value);
void PrintList(Node * LinkedList);
/* Metodi MergeSort */
Node* GetMiddle(Node *LinkedList);
Node* Merge(Node *left, Node *right);
Node* MergeSort(Node *LinkedList);






#endif
