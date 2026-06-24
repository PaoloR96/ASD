#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
extern int DP[MAX][MAX];
void InitDP(int DP[MAX][MAX],int lunghezza);
int CalcolaDP(int DP[MAX][MAX],int lunghezza,int PuntiTaglio[MAX]);
int min2(int a,int b);
#endif
