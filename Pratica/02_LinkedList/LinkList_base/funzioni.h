#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct Node {
    int value;           // dato contenuto nel nodo
    struct Node* next;   // puntatore al prossimo nodo

} Node;
/*Prototipi delle funzioni*/
void InitNode(Node* node, int val);



#endif
