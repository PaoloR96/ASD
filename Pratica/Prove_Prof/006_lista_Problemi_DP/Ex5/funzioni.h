#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
extern int DP[MAX][MAX];
void InitDP(int DP[MAX][MAX],int N);
int CalcolaDP(int DP[MAX][MAX],int N,int Pivot[MAX]);
int min2(int a,int b);
#endif
