#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void RiempiVettore(int V[MAX],int dim){
    for (int i = 0; i < dim; i++)scanf("%d",&V[i]);
}

bool IsJolly(int V[MAX],bool trovato[MAX],int dim) {
    for (int i = 1; i < dim; i++) {
        int diff = abs(V[i] - V[i-1]);
        //1.deve essere tra 1 e dim-1
        if (diff < 1 || diff >= dim)return false;//No jolly
        //2.differenza già presente
        if (trovato[diff])return false;//No jolly
        //3.Aggiorno la ricerca
        trovato[diff] = true;
    }
    return true;//It's jolly
}