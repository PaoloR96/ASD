#ifndef FUNZIONI_H
#define FUNZIONI_H
/* Definizione enumerazione per il colore */
typedef enum {
    RED = 0,   /* esplicito: RED = 0 */
    BLACK = 1  /* esplicito: BLACK = 1 */
} Color;

/*definizione del nodo*/
typedef struct Node{
    int key;
    struct Node*right;
    struct Node*left;
    struct Node*p;
    Color color;
}Node;
/*definizione alberoRB*/
typedef struct Tree{
    Node *tree;
    Node*NIL;
}Tree;
/*prototipi dei meotodi RB*/
Tree* CreateTree(void);
Node *CreateNode(Tree *tree,int key);
void LeftRotate(Tree *tree,Node*x);
void RightRotate(Tree *tree,Node*x);
void RBInsertFix(Tree *tree,Node*x);
void RbInsert(Tree *T, Node *z);
void PrintTree(Tree *T, Node *tree);


#endif /* FUNZIONI_H */
