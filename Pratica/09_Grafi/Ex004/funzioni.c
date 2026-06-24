#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

int isSafe(int r, int c, int R, int C, int vis[MAX_GRID][MAX_GRID]) {
    // Controllo bordi E controllo se la casella è libera (vis[r][c] == 0)
    // Se vis[r][c] è 1, significa o che ci siamo già passati o che c'è una bomba
    return (r >= 0 && r < R && c >= 0 && c < C && vis[r][c] == 0);
}

/*Metodi per la gestione della coda*/
void Enqueue(Passo coda[], int *tail, int r, int c, int d, int vis[MAX_GRID][MAX_GRID]){
        //inserimento in coda della tripla(r,c,d)
        coda[(*tail)].r=r;
        coda[(*tail)].c=c;
        coda[(*tail)].dist=d;
        vis[r][c]=1;//aggiorno lo stato
        (*tail)++;//aggiorno la coda
}
Passo Denqueue(Passo coda[], int *head){
        //estraggo elemento dalla testa
        return  coda[(*head)++];
}
/*Logica BFS*/
int bfs_bombs(int startR, int startC, int targetR, int targetC, int R, int C,int vis[MAX_GRID][MAX_GRID]){
    //inizializzo la mia codaStatica
    static Passo coda[(MAX_GRID*MAX_GRID)+1];
    int head=0,tail=0;
    // Se siamo già arrivati
    if (startR == targetR && startC == targetC) return 0;
    //inserisco il primo elemento nella coda
    Enqueue(coda,&tail,startR,startC,0,vis);
    //devo visitare tutti gli elementi all'interno della coda
    while (head<tail){
            //estraggo l'elemnento dalla coda
            Passo PassoAtt=Denqueue(coda,&head);
            if (PassoAtt.r == targetR && PassoAtt.c == targetC) return PassoAtt.dist;
            // Esploro i vicini
            CheckMosse(PassoAtt,coda,&tail,R,C, vis);
    }
    return -1;
    
}





void CheckMosse(Passo attuale, Passo coda[], int *tail, int R, int C, int vis[MAX_GRID][MAX_GRID]) {
    // 4 Direzioni: Su, Giù, Destra, Sinistra
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int nr = attuale.r + dr[i];
        int nc = attuale.c + dc[i];

        if (isSafe(nr, nc, R, C, vis)) {
            // Se la casella è sicura, aggiungiamo in coda
            Enqueue(coda, tail, nr, nc, attuale.dist + 1, vis);
        }
    }
}