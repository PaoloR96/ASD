#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*VAR GLOBALI*/
int DP[MAX][MAX];
void RiempiClasse(CasoTest *ct, int index) {
    // 1. Leggiamo quanti prodotti la classe index (M)

    int num_modelli;
    scanf("%d", &num_modelli); 
    ct->numProdotti[index] = num_modelli;

    // 2. Leggiamo i prezzi dei modelli per questa classe
    for (int i = 0; i < num_modelli; i++) scanf("%d", &ct->Prodotti[index][i]);
}


void InitDP(int DP[MAX][MAX],int numeroClassi,int budget){
    for (int i = 0; i <= numeroClassi; i++){
       for (int b = 0; b <= budget; b++)DP[i][b]=-1;//inizializzo a - 1 ogni elemento in modo tale da settare non raggiungibile
    }
}
    

int CalcolaDP(int DP[MAX][MAX],CasoTest T){
    //1.Caso Base:DP[MAX][MAX]
    DP[0][0]=0;
    //2.Ricorrenza:Calcolo la DP
    for (int i = 1; i <= T.numeroClassi; i++){//per ogni classe i
        int numeroProd=T.numProdotti[i-1];
        for (int b = 0; b <= T.budget; b++){//per ogni possible budget b
            for (int k = 0; k <numeroProd; k++){//per ogni prodotto k della classe i
                int prezzoX=T.Prodotti[i-1][k];
                //Se il prezzoX non supero il budget b && la locazione (i-1)(b-prezzoX) è inizializzata -1
                if (b>=prezzoX && DP[i-1][b-prezzoX]!=-1){
                    DP[i][b]=max2(DP[i][b],DP[i-1][b-prezzoX]+prezzoX);//Prendo il massimo tra: Prendere l'elemento della classe i con un certo prezzoX o non prenerlo
                }
            }    
        }
        
    }
    //3.Trovo il prezzo <=Budget tra tutte le classi X
    int SpesaAtt=-1;
    int X=T.numeroClassi;
    for (int b = 0; b <= T.budget; b++){//per ogni classe i
        if (SpesaAtt<DP[X][b])SpesaAtt=DP[X][b];
    }
    return SpesaAtt;
}
int max2(int a,int b){return(a>b)?a:b;}