#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int ListaAdj[NODI][NODI];
    int Visitato[NODI][NODI];//viene usato per tener traccia se un nodo è stato visitato
    int Risultato[NODI];
    int n;//numero nodi
    int m;//numero archi
    int index=0;
    while (index<NODI){
        //1.Definisco il numero di nodi e archi
        scanf("%d %d",&n,&m);
        if(n==0 && m==0)break;
        //2.Definisco la lista di adiacenza
        int nodo1=0,nodo2=0;
        //Azzero la matrice
        memset(ListaAdj, 0, sizeof(ListaAdj));
        for (int i = 0; i < m; i++){
            scanf("%d %d",&nodo1,&nodo2);
            //collego il nodo1 al nodo 2
            //NOTA:Essendo gli archi non orientati aggiorno in entrambe le direzioni
            ListaAdj[nodo1][nodo2]=1;
            ListaAdj[nodo2][nodo1]=1;
        }
        //3.Calcolo sequenza
        MaxAssoluto = 0;//resetto la variabile globale
        //Per ogni nodo i provo a far partire la strada da ogni nodo possibile
        for (int i = 0; i < n; i++) {
            memset(Visitato, 0, sizeof(Visitato));
            TrovaMaxPath(ListaAdj, Visitato, i, n, 0);
        }
        Risultato[index]=MaxAssoluto;   
        //4.Passo al caso di test successivo
        index++;
    
    }
     printf("SAMPLE OUTPUT:\n");
     for(int i=0;i<index;i++)printf("%d\n", Risultato[i]);
    
    
   

    system("pause");
    return 0;
}

/*
Complessità:o(n*2^m) con n numeri di nodi ed m numero di archi

*/