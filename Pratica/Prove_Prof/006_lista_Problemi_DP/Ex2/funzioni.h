#ifndef FUNZIONI_H
#define FUNZIONI_H
#define  MAX_STRINGA 1000
#define  MAX 100
/*VAR GLOBALE*/
extern int DP[MAX][MAX];
/*Metodi*/
void InitDP(int DP[MAX][MAX],int dim);
int CalcolaDP(int DP[MAX][MAX],char Stringa[MAX_STRINGA],int dim);
int max2(int a,int b);
#endif
