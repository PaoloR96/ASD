#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
//Metodo creazione Nodi
Nodo * CreateNodo(int n1){
        Nodo *NuovoNodo1=(Nodo*)malloc(sizeof(Nodo));//istanzio il nuovo nodo
        if(NuovoNodo1!=NULL){
            NuovoNodo1->next=NULL;
            NuovoNodo1->v_indice=n1;
        }
        return NuovoNodo1;
}
//Metodo per creare e collegare due nodi
void CollegaNodi(Arco arco[],int n1,int n2){
    //creo il nodo n1
    Nodo *Nodox=CreateNodo(n1);
     // Aggiungo n2 alla lista di n1
    Nodox->next=arco[n2].testa;// Collego il nuovo nodo alla lista esistente
    arco[n2].testa=Nodox;// Aggiorno la testa della lista di n2:Nodox diventa il primo elemento in  testa

    //creo il nodo n2
    Nodo *Nodoy=CreateNodo(n2);
     // Aggiungo n1 alla lista di n2
    Nodoy->next=arco[n1].testa;// Collego il nuovo nodo alla lista esistente
    arco[n1].testa=Nodoy;// Aggiorno la testa della lista di n1:Nodox diventa il primo elemento in  testa
}








/*Metodi per gestire la coda Q*/
// Inserisce il numero del nodo nella coda
void Enqueue(int coda[], int *tail, int nodo){
        coda[*tail] = nodo; 
        (*tail)++; 
}

// Estrae il numero del nodo dalla coda
int Dequeue(int coda[], int *head){
    int nodo = coda[*head];
    (*head)++;
    return nodo;
}



void RiempiCasoTest(CasoDiTest *test, int dim){
    int n1, n2;
    // Inizializziamo tutti i nodi possibili (200)
    for(int i = 0; i < NODI; i++) {
        test->arco[i].testa = NULL;
        test->colore[i] = -1;
    }
    for (int j = 0; j < dim; j++){
        if(scanf("%d %d", &n1, &n2) == 2) {
            CollegaNodi(test->arco, n1, n2);
        }
    }
}

void ElaboraCasi(CasoDiTest test[], int numCasi) {
    for (int i = 0; i < numCasi; i++) {
        // Chiamo la BFS passando l'intero array di archi e di colori del caso i-esimo
        BfsCasoTestx(test[i].arco, test[i].colore, test[i].l, test[i].n);
    }
}

void BfsCasoTestx(Arco arco[],int colore[],int l,int n){
        //inizializzo la coda per il caso di test x
        int coda[NODI];
        int head = 0, tail = 0;
        // Inizia dal nodo 0
        colore[0] = 0;
        Enqueue(coda, &tail, 0);
        while (head<tail){
                //estraggo l'elemnento dalla coda
                int u = Dequeue(coda, &head);
                Nodo*nodoAtt=arco[u].testa;
                while (nodoAtt!=NULL){//vado a scorrere la lista di adiacenza del nodo u e quindi prendo tutti i suoi vicini
                    int v=nodoAtt->v_indice; //prendo il vicino v
                    
                    if(colore[v]==-1){//se non è colorato
                        colore[v]=1-colore[u];//lo coloro e lo metto in coda
                        Enqueue(coda,&tail,v);
                    }else if(colore[v]==colore[u]){//hanno lo stesso colore
                            printf("NOT BICOLORABLE.\n");
                            return; // Esco subito dalla funzione
                    }
                    nodoAtt=nodoAtt->next; //passo al vicino successivo

                }
        }
        // Se arrivo qui, il ciclo è finito senza conflitti
        printf("BICOLORABLE.\n");
}
