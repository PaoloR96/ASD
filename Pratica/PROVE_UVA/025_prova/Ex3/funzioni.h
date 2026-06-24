#ifndef FUNZIONI_H
#define FUNZIONI_H
#define N 8
/*var globale*/
extern int DP_H[N][N];
/*Metodi*/
void RiempiMatrice(int M[N][N], int n_effettivo);
void InizializzaDP(int DP_H[N][N]);
int CalcolaDp(int DP_H[N][N],int M[N][N]);
#endif
