#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct Node {
    int key;
    struct Node * right;
    struct Node * left;
    struct Node * p;
}Node;
/*prototipi funzioni BST*/
Node * CreateNode(int key);
void   InsertNode(Node** tree,int key);
void   DeleteNode(Node** tree,int key);
void   PrintTree(Node* tree); //InorderTreeWalk
Node * MinTree(Node*tree);
Node * MaxTree(Node*tree);
Node * TreeSuccessor(Node *tree);
Node * SearchNode(Node **tree,int key);


#endif


