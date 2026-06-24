#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct {
    int x;
    int y;
    int dist;
}Passo;
// Metodi di conversione
int charToCol(char c);
int charToRow(char r);
//Metodo per controllare confine scacchiera
int isInside(int x, int y);
/*Metodi per gestire coda STATICA di array*/
void Enqueue(Passo coda[],int *tail,int x,int y,int d,int visPasso[8][8]);
Passo Dequeue(Passo coda[],int *head);
/*Metodo per controllare tutte le possibili mosse*/
void CheckMosse(Passo attuale, Passo coda[], int *tail, int targetX, int targetY, int vis[8][8]);
/*BFS*/
int bfs(char start[],char end[]);


#endif
