#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*var globale*/
int DP[MAX][MAX];
void CalcolaIesimoCasoTest(int X[MAX],int Y[MAX][MAX],int dim){
        for (int i = 0; i < dim-1; i++){//Per ogni caso di test iesimo
            //Fase1:Inizializzo la DP[MAX][MAX]
            InitDP(DP,dim+1);
            //Fase2:Calolo la dp
            int lunghezzaLCS=CalcolaDP(DP,X,Y[i],dim);
            printf("%d\n",lunghezzaLCS);    
            //Fase3:Passo al prossimo cofronto i+1
        }
}
void InitDP(int DP[MAX][MAX],int dim){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim+1; j++)DP[i][j]=0;
    }
}

int CalcolaDP(int DP[MAX][MAX],int X[MAX],int Y[MAX],int dim){
    for (int i = 1; i <= dim; i++){//Per ogni carattere i
        int valX=X[i-1];
        for (int j = 0; j <= dim; j++){//Per ogni carattere j
            if (valX==Y[j-1]){//Se i caratteri sono uguali
                DP[i][j]=DP[i-1][j-1]+1;//Aggiono lo stato attuale sommando 1+ DP[i-1][j-1] (escudo entrambi i caratteri)
            }else{
                DP[i][j]=max2(DP[i][j-1],DP[i-1][j]);//Prendo il massimo tra i due caratteri(escludo solo il massimo)
            }
        }
    }
    return DP[dim][dim];
}
int max2(int a,int b){return (a>b)?a:b;}