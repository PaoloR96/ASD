#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct Node {
    int value;           // dato contenuto nel nodo
    struct Node* next;   // puntatore al prossimo nodo
   

} Node;
/*prototipi funzione*/
Node* InitNode(int val);
void InsertNode(Node** LinkedList, int val);
void PrintList(Node* LinkedList);
void SwapNode(Node** LinkedList);



#endif
