#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
/*Definizione VarGlobale*/
extern int DP[MAX];
/*Definizione prototipi*/
void InitDP(int DP[MAX],int n);
int CalcolaDP(int DP[MAX],int arr[MAX],int n);
int max2(int a,int b);
#endif
