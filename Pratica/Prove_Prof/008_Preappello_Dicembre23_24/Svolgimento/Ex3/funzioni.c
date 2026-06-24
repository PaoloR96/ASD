#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

int DP[MAX][MAX];
//Inserisco i prodotti per ogni classe
void InserisciProdotti(int Prodotti[MAX],int dim){
    for (int i = 0; i < dim; i++)scanf("%d",&Prodotti[i]);
}

void InitDP(int DP[MAX][MAX],int numeroClassi,int budget){
    for (int i = 0; i <= numeroClassi; i++){
       for (int b = 0; b <= budget; b++)DP[i][b]=-1;//inizializzo a - 1 ogni elemento in modo tale da settare non raggiungibile
    }
}
  


int CalcolaDP(int DP[MAX][MAX], CasoTest ct){
    //1.Caso base
    DP[0][0]=0;
    //2.Ricorrenza
    for (int i = 0; i < ct.Numclassi; i++){//Per ogni classe i
         for (int b = 0; b <= ct.budget; b++){//per ogni budget b
            for (int k = 0; k < ct.NumProdotti[i]; k++){//per ogni prodotto k della classe i
                int PrezzoX=ct.Prodotti[i][k];//Prendo il prezzo del prodotto k associato alla classe i
                //Se il prezzo rientra nel budget b && la locazione è libera 
                if (PrezzoX<=b && DP[i][b-PrezzoX]!=-1){
                    int nuovaSpesa = DP[i][b - PrezzoX] + PrezzoX;
                    //Il nuovo stato dipede : Prendiamo il massimo tra il valore che c'era già in quella cella e la nuova spesa
                    DP[i+1][b]=max2(DP[i+1][b],nuovaSpesa);
                }
            }
            
         }
    }
   //3.Trovo il prezzo <=Budget tra tutte le classi X
   int SpesaAtt=-1;
   for (int b = 0; b <= ct.budget; b++){
     if (SpesaAtt<DP[ct.Numclassi][b])SpesaAtt=DP[ct.Numclassi][b];
    }
    return SpesaAtt;
}

int max2(int a,int b){return(a>b)?a:b;}
