#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_MONETE 101
#define MAX_DP 25001 // (100 monete * 500 centesimi) / 2 + 1
/*Prototipi funzione*/
int Somma(int s[MAX_MONETE],int dim);
void InitDP(int dp[MAX_DP],int target);
int CalcolaDP(int dp[MAX_DP],int s[MAX_MONETE],int target,int m);


#endif
