#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header


long long CalcolaDp(long long DP[MAX],int target){
    int monete[]={1,5,10,25,50};
    int n=sizeof(monete)/sizeof(monete[0]);
    //inizilizzo il vettore DP 
    for(int i=0;i<=target;i++)DP[i]=0;
    
    // Caso base: 1 modo per fare 0 centesimi
    DP[0] = 1;
    //Ricorrenza:
    for (int i = 0; i < n; i++){ //per ogni moneta i
        int monetaX=monete[i];//prendo la moneta attuale
        for (int j =monetaX ; j <=target ; j++){
            DP[j]=DP[j-monetaX]+DP[j]; 
        }
        
    }
    return DP[target];   
}

