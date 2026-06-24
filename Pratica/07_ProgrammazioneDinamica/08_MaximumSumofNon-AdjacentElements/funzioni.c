#include <stdio.h>
#include "funzioni.h"

void InitDp(int dp[N]){
    for (int i = 0; i < N; i++)dp[i]=INT_MAX;    
}
int max(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}
int DpCalculate(int dp[N],int A[N]){
    dp[0]=0;
    dp[1] = max(A[0], A[1]);
    for (int x = 2; x < N; x++) dp[x]=max(dp[x-1], A[x-1]+ dp[x-2]);
     return dp[N-1];    
}