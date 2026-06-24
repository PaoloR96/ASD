#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int ComparaForza(const void * a,const void * b){
    const Tartaruga *t1=(const Tartaruga*)a;
    const Tartaruga *t2=(const Tartaruga*)b;
    return t1->Forza-t2->Forza; //ordino le tartarughe in base alla forza in ordine crescente
    
}

void initDP(int DP[MAX],int dim){
    for (int i = 0; i < dim; i++)DP[i]=INT_MAX;
}
int CalcolaDP(int DP[MAX],Tartaruga T[MAX],int dim){
    //1.caso base
    DP[0]=0;
    //Ricorrenza
    int maxAltezza=0;
    for (int i = 0; i < dim; i++){//per ogni tartaruga i
        int ForzaAtt=T[i].Forza;    
        int PesoAtt=T[i].Peso;
        for (int j = dim; j >=1; j--){ // Partiamo dall'altezza massima possibile verso il basso 
            // Verifichiamo se la tartaruga T[i] può reggere la pila di j-1 tartarughe
            // La condizione è: (Peso della pila sopra) + (Peso proprio) <= Forza propria
            if(DP[j-1]!=INT_MAX && DP[j-1]+PesoAtt<=ForzaAtt){
                // Aggiorniamo il peso minimo per la pila di altezza j
                // Se aggiungendo questa tartaruga otteniamo una pila più leggera, la salviamo
                DP[j]=min2(DP[j],DP[j-1]+PesoAtt);
                // Teniamo traccia della pila più alta trovata finora
                if (j > maxAltezza) maxAltezza = j;
            }
        }
    
    }
    return maxAltezza;
}



int min2(int a, int b) {
    return (a < b) ? a : b;
}