#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
#define MAX_STINGA 1000
/*VAR GLOBALE*/
extern int DP[MAX][MAX];
void InitDP(int DP[MAX][MAX],int dim);
int CalcolaDP(int DP[MAX][MAX],char Stringa[MAX_STINGA],int dim);
int max2(int a,int b);
#endif
