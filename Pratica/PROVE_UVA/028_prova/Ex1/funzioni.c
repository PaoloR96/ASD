#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int TallestShorter(int S[MAX_CHIMPS],int N,int H){
    int low=0;
    int high=N-1;
    int answ=-1;
    while (low<=high){
        //1.Calcolo il punto medio
        int mid=low+(high-low)/2;
        if (S[mid]<H){
            answ=S[mid];//Soluzione parziale trovata
            low=mid+1; // Cerco se ce n'è uno ancora più alto a destra
        }else{
            high=mid-1; // Troppo alto o uguale, vado a sinistra
        } 
    }
    return answ;
}

int ShortestTaller(int S[MAX_CHIMPS],int N,int H){
    int low=0;
    int high=N-1;
    int answ=-1;
    while (low<=high){
        //1.Calcolo il punto medio
        int mid=low+(high-low)/2;
        if (S[mid]>H){
            answ=S[mid];//Soluzione parziale trovata
            high=mid-1; // Cerco se ce n'è uno ancora più basso a sinistra
        }else{
            low=mid+1;  // Troppo basso o uguale, vado a destra
            
        } 
    }
    return answ;
}