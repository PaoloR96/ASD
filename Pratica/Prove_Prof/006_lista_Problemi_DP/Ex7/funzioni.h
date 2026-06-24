#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 1000
/*var globale*/
extern int DP[MAX][MAX];
/*Metodi*/
void InitDP(int DP[MAX][MAX],int n, int m);
int CalcolaDP(int DP[MAX][MAX],char Stringa1[MAX],int n,char Stringa2[MAX] ,int m);
int max2(int a,int b);
#endif
