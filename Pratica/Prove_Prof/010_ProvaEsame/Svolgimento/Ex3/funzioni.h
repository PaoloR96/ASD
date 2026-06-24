#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
/*VAR GLOBALE*/
extern int DP[MAX][MAX];
/*metodi*/
void InitDP(int DP[MAX][MAX],int dim);
int CalcolaDP(int DP[MAX][MAX],int X[MAX],int Y[MAX],int dim);
void CalcolaIesimoCasoTest(int X[MAX],int Y[MAX][MAX],int dim);
int max2(int a,int b);
#endif
