#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct Node{
        int key;
        struct Node * right;
        struct Node * left;
        struct Node * p;
}Node;
// Prototipi delle funzioni
Node * CreateNode(int key);
void InsertNode(Node **tree,int key);
void DeleteNode(Node **tree,int key);
void PrintTree(Node *tree);
Node * MaxNode(Node *tree);
Node * MinNode(Node *tree);
Node * TreeSuccessor(Node *tree);

#endif
