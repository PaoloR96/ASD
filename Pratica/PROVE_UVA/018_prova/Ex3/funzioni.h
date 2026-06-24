#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
int CalcolaSequenza(char S1[MAX],char S2[MAX]);
void InitDP(int DP[MAX][MAX],int n,int m);
int max2(int a,int b);
int TrovaSequenza(int DP[MAX][MAX],char S1[MAX],char S2[MAX],int n,int m);

#endif
