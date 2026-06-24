#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header


void CreazioneAlbero(int V[],int dim){
    //1.Costruzione dell'albero binario di ricerca
    Nodo *root = NULL;
    for (int i = 0; i < dim; i++) {
        Nodo *nuovoNodo = CreateNodo(V[i]);
        if (nuovoNodo != NULL) {
            root = InsertNodo(root, nuovoNodo);
        } else {
            printf("Errore: Impossibile allocare memoria per il valore %d\n", V[i]);
        }
    }
    //2.Stampa
    InorderTreeWalk(root);
    printf("\n\n");
}
/*Stampa caso di test*/
void StampaVettore(int V[], int dim) {
    for (int i = 0; i < dim; i++)printf("%d ", V[i]);
    printf("\n");
}





/*Creazione del Nodo corrente*/
Nodo *CreateNodo(int value){
    //1.Istanzio il nodo
    Nodo * newNode=malloc(sizeof(*newNode));
    //2.Inizializzo il nodo
    if (newNode==NULL) return NULL;
    newNode->key=value;
    newNode->left=NULL;
    newNode->right=NULL;
    //3.Ritorna il nodo creato
    return newNode;
}
/*Inserimento nodo z all'interno dell'albero T*/
Nodo* InsertNodo(Nodo *T, Nodo *z){
        //Passo1:Definisco un nodo d'appoggio 
        Nodo * y=NULL;
        Nodo *x=T;
        //Passo2:Inizio la ricerca della posizione spostandomi all'interno dell'albero
        while (x!=NULL){
            //salvo la poszione corrente di x,tenendo traccia dell'ultimo nodo visitato
            y=x;
            if (z->key<x->key)x=x->left;//Vado a sx
            else x=x->right;//vado a dx
        }
        //Passo3:Posiziono il nodo z
        if(y==NULL)
            T=z;//z è la radice
        else if(z->key<y->key)
            y->left=z; //z è figlio sx
        else
            y->right=z;//z è figlio dx

        //Passo4:Ritorna l'albero aggiornato
        return T;
}
/*Attraverso questo metodo andrò ad effettuare la stampa degli n nodi in modo crescente
Poichè vado a visitare ogni nodo una volta avrò una complessità Theta(n)
*/
void InorderTreeWalk(Nodo *x){
    if (x!=NULL){
        InorderTreeWalk(x->left);//scendo a sx 
        printf("%d ",x->key);
        InorderTreeWalk(x->right);//scendo a dx 
    }
}