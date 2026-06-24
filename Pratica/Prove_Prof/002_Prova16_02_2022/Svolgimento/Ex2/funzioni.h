#ifndef FUNZIONI_H
#define FUNZIONI_H
#define DIM_N 100
#define DIM_M 100
/*Var Globale*/
extern int DP[DIM_N][DIM_M];
/*Metodi*/
void InitDP(int DP[DIM_N][DIM_M],int N,int M);
int CalcolaDP(int DP[DIM_N][DIM_M],int Matrice[DIM_N][DIM_M],int N, int M);
int CalcolaMassimaArea(int I[DIM_N],int N);
#endif
