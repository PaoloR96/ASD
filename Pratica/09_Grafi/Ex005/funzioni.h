#ifndef FUNZIONI_H
#define FUNZIONI_H
#define M 100
#define N 100
#define MAX 4
typedef struct {
    int m; //numero colonne
    int n; //numero righe
    char T[M][N]; //terreno
    int visitato[M][N]; //terreno
}CasoTest;
/*Metodi*/
void InserimentoCasiTest(char T[M][N],int visitato[M][N],int r,int c);
void ElaboraCasiTest(CasoTest T[],int dim);
int AnalizzaDepositoX(char T[M][N],int visitato[M][N],int R,int C);
void Dfs(char T[M][N],int visitato[M][N],int R,int C,int rx,int cx);
int isSafe(int r, int c, int R, int C);


#endif
