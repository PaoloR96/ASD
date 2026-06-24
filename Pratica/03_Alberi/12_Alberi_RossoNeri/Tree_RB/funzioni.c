#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

Node *CreateNode(Tree *tree,int key){
     //istanziamento nodo
     Node*node=malloc(sizeof(Node));
     node->right=node->left=node->p=tree->NIL;
     node->color=RED;
     node->key=key;
     return node;
}
Tree* CreateTree(void){
    Tree *T = malloc(sizeof(Tree));
    // Creazione del nodo sentinella NIL
    Node *nilNode = malloc(sizeof(Node));
    nilNode->key = 0;               // opzionale, non usato
    nilNode->color = BLACK;         // NIL deve essere nero
    nilNode->left = nilNode->right = nilNode->p = nilNode;

    T->NIL = nilNode;               // assegno la sentinella all'albero
    T->tree = T->NIL;               // l'albero inizialmente vuoto punta a NIL
    return T;
}

 /* assumendo che P sia x */
    /* situazione iniziale:
              P
             / \
            A   Q
               / \
              B   C
    */

void LeftRotate(Tree *T, Node *x) {

    /* 1) Identifico y come il figlio destro di x (cioè Q nell'esempio).
          y sarà il nuovo "capo" del sottoalbero. */
    Node *y = x->right;

    /* 2) Devo far "salire" B, che è il figlio sinistro di Q.
          Quindi, collego B (y->left) come nuovo figlio destro di P (x). */
    x->right = y->left;

    /* 3) Aggiorno il padre di B: ora deve puntare a P (x),
          perché B è diventato figlio destro di P. */
    if (y->left != T->NIL)
        y->left->p = x;

    /* 4) Ora collego Q (y) al padre di P (x),
          perché Q sta salendo al posto di P nel sottoalbero. */
    y->p = x->p;

    /* 5) Devo aggiornare il puntatore dal padre di P,
          per fargli puntare a Q, che lo sostituisce. */
    if (x->p == T->NIL)
        T->tree = y;               /* a) Se P era radice, ora Q diventa la nuova radice */
    else if (x == x->p->left)
        x->p->left = y;            /* b) Se P era figlio sinistro, collega Q a sinistra */
    else
        x->p->right = y;           /* c) Se P era figlio destro, collega Q a destra */

    /* 6) Ora P diventa il figlio sinistro di Q. */
    y->left = x;

    /* 7) Aggiorno il padre di P: ora il suo padre è Q. */
    x->p = y;
}
/*Stato finale, dopo leftRotate:

        Q
       / \
      P   C
     / \
    A   B

*/



 /* assumendo che P sia x */
    /* situazione iniziale:
                 Q
                / \
               P   C
              / \
             A   B

    */
void RightRotate(Tree *T, Node *x) {

    /* 1) Identifico y come il figlio sinistro di x (cioè P nell'esempio).
          y sarà il nuovo "capo" del sottoalbero. */
    Node *y = x->left;

    /* 2) Devo far "salire" B, che è il figlio destro di P (y).
          Quindi collego B come nuovo figlio sinistro di Q (x). */
    x->left = y->right;

    /* 3) Aggiorno il padre di B: ora deve puntare a Q (x),
          perché B è diventato figlio sinistro di Q. */
    if (y->right != T->NIL)
        y->right->p = x;

    /* 4) Ora collego P (y) al padre di Q (x),
          perché P salirà al posto di Q nel sottoalbero. */
    y->p = x->p;

    /* 5) Devo aggiornare il puntatore dal padre di Q,
          per fargli puntare a P, che lo sostituisce. */
    if (x->p == T->NIL)
        T->tree = y;                /* a) Se Q era radice, ora P diventa la nuova radice */
    else if (x == x->p->right)
        x->p->right = y;            /* b) Se Q era figlio destro, collega P a destra */
    else
        x->p->left = y;             /* c) Se Q era figlio sinistro, collega P a sinistra */

    /* 6) Ora Q (x) diventa il figlio destro di P (y). */
    y->right = x;

    /* 7) Aggiorno il padre di Q: ora il suo padre è P. */
    x->p = y;
}


/*Stato finale, dopo leftRotate:

          P
         / \
        A   Q
           / \
          B   C

*/




    /* situazione iniziale:
                  B(30,B)
                  /     \
            P(20,R)      U
              / 
           z(25,R)

    */

void RBInsertFix(Tree *T, Node *z){
    Node *y; // Zio di z

    // Finché il padre di z è rosso → violazione delle proprietà Red-Black
    while(z->p->color == RED){
        // Determino il nonno e lo zio di z

        // Caso 1: Padre di z è figlio sinistro del nonno
        if(z->p == z->p->p->left){
            y = z->p->p->right; // Zio destro

            if(y->color == RED){
                // Caso 1a: Zio rosso → riassegno colori
                z->p->color = BLACK;        //padre diventa rosso
                y->color = BLACK;           //zio diventa nero
                z->p->p->color = RED;       //nonno diventa rosso
                z = z->p->p;                // Salgo al nonno
            } else {
                // Caso 1b: Zio nero
                // Se z è figlio destro del padre → rotazione a sinistra sul padre
                if(z == z->p->right){
                    z = z->p;
                    LeftRotate(T, z);     
                }
                // Aggiorno colori di padre e nonno e faccio rotazione a destra sul nonno
                z->p->color = BLACK;      
                z->p->p->color = RED;    
                RightRotate(T, z->p->p); 
            }

        // Caso 2: Padre di z è figlio destro del nonno
        } else {
            y = z->p->p->left; // Zio sinistro

            if(y->color == RED){
                // Caso 2a: Zio rosso → riassegno colori
                z->p->color = BLACK;  
                y->color = BLACK;     
                z->p->p->color = RED; 
                z = z->p->p;          // Salgo al nonno
            } else {
                // Caso 2b: Zio nero
                // Se z è figlio sinistro del padre → rotazione a destra sul padre
                if(z == z->p->left){
                    z = z->p;
                    RightRotate(T, z);     
                }
                // Aggiorno colori di padre e nonno e faccio rotazione a sinistra sul nonno
                z->p->color = BLACK;      
                z->p->p->color = RED;    
                LeftRotate(T, z->p->p);  
            }
        }
    }

    // Assicuro che la radice sia sempre nera
    T->tree->color = BLACK;
}

void RbInsert(Tree *T, Node *z){
    /* 1) Partiamo dalla radice per trovare la posizione di inserimento */
    Node *x = T->tree;

    /* Nodo temporaneo per tenere traccia del padre di z */
    Node *y = T->NIL;

    /* 2) Scorriamo l'albero per trovare la posizione corretta di z */
    while (x != T->NIL){
        y = x;                   // y sarà il genitore di z
        if(z->key < x->key)
            x = x->left;         // Scendiamo a sinistra se z è minore di x
        else
            x = x->right;        // Scendiamo a destra se z è maggiore o uguale a x
    }

    /* 3) Colleghiamo z al suo genitore */
    z->p = y;                   // Impostiamo il padre di z
    if (y == T->NIL)             // Se l'albero era vuoto
        T->tree = z;             // z diventa la radice
    else if (z->key < y->key)
        y->left = z;             // z diventa figlio sinistro di y
    else
        y->right = z;            // z diventa figlio destro di y

    /* 4) Inizializziamo i figli e il colore di z */
    z->left = T->NIL;           // Figlio sinistro = NIL
    z->right = T->NIL;          // Figlio destro = NIL
    z->color = RED;             // Nuovo nodo rosso

    /* 5) Ripristiniamo le proprietà del Red-Black Tree se necessario */
    RBInsertFix(T, z);        // Funzione che corregge eventuali violazioni dei colori
}
// Stampa l'albero in-order con indicazione del colore dei nodi
void PrintTree(Tree *T, Node *tree) {
    if (tree != T->NIL) {  // controlla la sentinella
        PrintTree(T, tree->left);   // visita il sottoalbero sinistro

        // stampa il nodo corrente con colore
        printf("%d(%s) ", tree->key, tree->color == RED ? "R" : "B");

        PrintTree(T, tree->right);  // visita il sottoalbero destro
    }
}