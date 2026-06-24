#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX_DP 100000    
#define MAX_MONETE 100   
#define MAX_TESTS 1000

/*VAR GLOBALE*/
extern int DP[MAX_DP];
/*Metodi*/
void InitDP(int DP[MAX_DP],int limite);
int CalcolaDP(int DP[MAX_DP],int V,int limiteMax,int n,int Monete[MAX_MONETE]);
int min2(int a,int b);
int ValoreMax(int n,int Monete[MAX_MONETE]);
#endif
