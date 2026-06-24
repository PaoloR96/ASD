#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX_GRID 1000

typedef struct {
    int r;    // riga
    int c;    // colonna
    int dist;
} Passo;

// Utility
int isSafe(int r, int c, int R, int C, int vis[MAX_GRID][MAX_GRID]);
// Gestione Coda
void Enqueue(Passo coda[], int *tail, int r, int c, int d, int vis[MAX_GRID][MAX_GRID]);
Passo Denqueue(Passo coda[], int *head);
// BFS con controllo Mosse
int bfs_bombs(int startR, int startC, int targetR, int targetC, int R, int C,int vis[MAX_GRID][MAX_GRID]);
void CheckMosse(Passo attuale, Passo coda[], int *tail, int R, int C, int vis[MAX_GRID][MAX_GRID]);

#endif