#ifndef FUNZIONI_H
#define FUNZIONI_H
#define DIM_N 100
#define DIM_M 100
/*Var Globale*/
extern int DP[DIM_N][DIM_M];
/*Metodi*/
void InitDP(int DP[DIM_N][DIM_M],int N,int M);
int CalcolaDP(int DP[DIM_N][DIM_M],int Matrice[DIM_N][DIM_M],int N, int M);
int CalcolaMassimaArea(int H[DIM_M],int M);
int max2(int a,int b);
#endif
