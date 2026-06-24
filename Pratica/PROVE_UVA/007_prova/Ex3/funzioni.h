#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_N 10000   // lunghezza massima della sequenza
//Prototipi funzioni
void initDp(int dp[MAX_N],int N);
int max(int a, int b);
int CalcolaDp(int dp[MAX_N],int seq[MAX_N],int N);
#endif
