#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*Metodi di conversione e controllo confini*/
int charToCol(char c) { 
        return c - 'a'; 
}
int charToRow(char r) { 
    return r - '1'; 
}
int isInside(int x, int y) { 
    return (x >= 0 && x < 8 && y >= 0 && y < 8); 
}



/*Metodi per gestire la coda definendo i metodi Enqueue ed Dequeue*/
void Enqueue(Passo coda[],int *tail,int x,int y,int d,int visPasso[8][8]){
    //l'inserimento avvine dalla coda
    coda[*tail].x=x;//aggiorno la coordinata x
    coda[*tail].y=y;//aggiorno la coordinata y
    coda[*tail].dist=d;//aggiorno la distanza d
    visPasso[x][y]=1; // quella coordianta è stata visitata
    (*tail)++;//aggiorno la coda per il prossimo inserimento
}
// Estrae il prossimo passo da analizzare
Passo Dequeue(Passo coda[],int *head){
    return coda[(*head)++];
}



/*Metodi per gestire il DFS*/
int bfs(char start[],char end[]){
        //Converto i caratteri di partenza ed arrivo
        int sX = charToCol(start[0]), sY = charToRow(start[1]);
        int tX = charToCol(end[0]), tY = charToRow(end[1]);
        if (sX == tX && sY == tY) return 0;
        //inizializzo i parametri della Coda Statica
        Passo coda[64];
        int visitato[8][8]={0};
        int head=0,tail=0;
        //Inizio:Inserico nella coda i parametri di partenza sX ed sY
        Enqueue(coda,&tail,sX,sY,0,visitato);
        //devo riempire la coda
        while (head<tail){
            //estraggo il primo elemento dalla coda
            Passo attuale=Dequeue(coda,&head);
            if (attuale.x == tX && attuale.y == tY) return attuale.dist;
            // Delega il controllo delle mosse successive
            CheckMosse(attuale,coda,&tail,tX,tY,visitato);
        }
        return -1;
}



// Esplora le 8 mosse possibili a partire dalla posizione attuale
void CheckMosse(Passo attuale, Passo coda[], int *tail, int targetX, int targetY, int vis[8][8]) {
    //coordinate che verranno combinate con quelle attuali per verificare tutte 
    //le possibli mosse
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        int nx = attuale.x + dx[i];
        int ny = attuale.y + dy[i];
        //se la mia coordinata è sicura e non è stata visitata allora aggiungo in coda e aggiorno la distanza
        if (isInside(nx, ny) && !vis[nx][ny]) {
            Enqueue(coda, tail, nx, ny, attuale.dist + 1, vis);
        }
    }
}
