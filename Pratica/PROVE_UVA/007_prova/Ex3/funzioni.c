#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void initDp(int dp[MAX_N],int N){
    for (int i = 0; i < N; i++)dp[i]=0;
}
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int CalcolaDp(int dp[MAX_N],int seq[MAX_N],int N){
    //caso base
    dp[0]=seq[0];
    for (int i = 1; i < N; i++)dp[i]=max(seq[i],dp[i-1]+seq[i]);

    //trovo il max
    int max=0;
    for (int i = 0; i <N; i++){
        if(dp[i]>max)max=dp[i];
    }
    return max;
}
