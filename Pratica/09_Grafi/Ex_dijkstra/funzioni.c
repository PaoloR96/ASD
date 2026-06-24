#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
//Metodi per Gestire la Coda a Priorità
void Push(Elemento coda[], int *size,int id,int costo){
        //inserimento elemento(id,costo)
        coda[*size].id=id;
        coda[*size].costo=costo;
        (*size)++; //aggiorno la coda per inserire il prossimo elemento
}
Elemento MinPop(Elemento coda[], int *size){
        int minId=0;
        //devo trovare l'elemento con il costo minimo da estrarre
        //all'interno del vettore
        for (int i = 1; i < *size; i++){
            if(coda[i].costo<coda[minId].costo)minId=i;
        }
        //selezione l'elemento con il costo minore
        Elemento minEl=coda[minId];
        coda[minId]=coda[*size-1];//decremento la coda
        (*size)--; //decremento la size
        return minEl;
        
}

int dijkstra(int start, int target, int n, int grafo[MAX_NODI][MAX_NODI]){
        //dichiaro le variabili
        static int dist[MAX_NODI];
        static Elemento coda[MAX_NODI * MAX_NODI];
        int size = 0;
        //1.Inizilizzo a INF le n distanze di dist[MAX_NODI] che non sono la sorgente
        for (int i = 0; i < n; i++)dist[i]=INT_MAX;
        //2.Setto a 0 la distanza dell'elemento/nodo di partenza
        dist[start]=0;
        //3.Essendo l'elemento di partenza lo inserisco in coda
        Push(coda,&size,start,0);
        //4.Vado a valutare gli altri elementi del grafo
        while (size>0){
                //4.a estraggo l'elemento a distanza minima dalla coda
                Elemento elemAtt=MinPop(coda,&size);
                //se non trovo di meglio vado avanti
                if(elemAtt.costo>dist[elemAtt.id])continue;
                //se sono arrivato a destinazione
                if(elemAtt.id==target)return elemAtt.costo;
                //5.b Arrivato a questo punto devo esploare tutti i nodi v vicini ad elemAtt
                for (int v = 0; v < n; v++){
                    //se esiste già un arco tra elemAtt ED v
                    if (grafo[elemAtt.id][v]!=INT_MAX &&grafo[elemAtt.id][v]>0){
                        int pesoArco=grafo[elemAtt.id][v];
                        //Rilassamento:se passando per v ho un miglioramento
                        if(dist[elemAtt.id]+pesoArco<dist[v]){
                            dist[v]=dist[elemAtt.id]+pesoArco; //aggiorno la distanza attuale
                            Push(coda,&size,v,dist[v]); //aggiorno la coda
                        }
                    }   
                }   
        }
        return -1;
}
