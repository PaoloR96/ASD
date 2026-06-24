#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header


void initDP(int DP[MAX_MW],int dim){
    for (int i = 0; i < dim; i++)DP[i]=0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void CalcolaDP(int DP[MAX_MW],CasoTest test){
    //1.Riempio la matrice DP    
    for (int i = 0; i < test.n; i++){//per ogni oggetto i
                int prezzoAtt=test.oggetti[i].prezzo;//prendo il prezzo attuale
                int pesoAtt=test.oggetti[i].peso;//prendo il peso attuale    
                //Ecco il cuore della logica, in questo caso poichè ogni oggetto lo prendo 1 SOLA VOLTA
                //Parto dalla capacità massimo fino al peso attuale per creare la mia DP(i)
                for (int j = MAX_MW; j >= pesoAtt; j--){
                    DP[j]=max(prezzoAtt+DP[j-pesoAtt],DP[j]);//prendo l'elemento considerando il prezzo e decrementanto il peso OPPURE non lo prendo
                }
    }
    //In base a Dp sommo i risultati ottimali per ogni membro della famiglia
    int MaxTot=0;
    for (int i = 0; i < test.g; i++){
        int forzaPersona=test.maxPeso[i];
        MaxTot+=DP[forzaPersona];//per ogni elemento della famiglia calcolo il massimo peso  
    }
    printf("%d \n",MaxTot);
    
}