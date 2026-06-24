#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void InizializzaDP(int DP[MAX],int dim){
    for (int i = 0; i < dim+1; i++)DP[i]=1;
}
int CalcolaDP(int DP[MAX],int S[MAX],int dim){
       
        //1.Ricorsione
        for (int i = 0; i < dim; i++){//per ogni missile "i"
            int altezzaAtt=S[i];
            // Controllo tutti i missili arrivati PRIMA di quello attuale
            for (int j = 0; j <i; j++){ 
                // Il CATCHER può intercettare 'i' dopo 'j' solo se S[i] <= S[j]
                if(S[j]>=altezzaAtt){
                    // Aggiorno il massimo per il missile attuale i
                    DP[i]=max2(DP[i],DP[j]+1);
                }
            }
        }
        //3.Trovo il massimo all'intenro della DP
        int MassimoVal=INT_MIN;
        for (int i = 0; i < dim; i++){
            if(DP[i]>MassimoVal)MassimoVal=DP[i];
        }
        return MassimoVal;
}

int max2(int a,int b){
    return (a>b)? a:b;
}