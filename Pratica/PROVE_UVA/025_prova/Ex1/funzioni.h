#ifndef FUNZIONI_H
#define FUNZIONI_H
#define M 500
#define N 500
typedef struct{
    /* data */
    int x;
    int y;
}Query;

int RicercaLowerBound(int Colonna[],int m,int L);
int CalcolaArea(int Matrice[N][M],int m,int n,int L,int U);
void RiempiMatrice(int Matrice[N][M],int n,int m);
void  CalcolaCasoTestX(int Matrice[N][M],int m,int n, Query q[1000],int dim,int index);
#endif
