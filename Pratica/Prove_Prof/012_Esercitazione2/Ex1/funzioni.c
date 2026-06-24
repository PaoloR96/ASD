#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

int TrovaPosizionePallina(int NodoCorrente,int I,int D,int index){
    //1.Condizione di uscita:Ho raggiunto la profondità D
    if (index==D)return NodoCorrente;
    //2.Attraverso l'albero
    //A.Verifico lo stato della pallina in base a se è pari o dispari
    //B.Devo calcolare il figlio del nodoCorrente
    if (I%2==0){//Se è pari devo andare a destra
        int NuovoNodo=2*NodoCorrente+1;//Calcolo il nodo di destra
        int NuovaPallina=I/2;
        //Passo al livello successivo
        return TrovaPosizionePallina(NuovoNodo,NuovaPallina,D,index+1);
    
    }else{//Se è dispari vado a sinistra
        int NuovoNodo=2*NodoCorrente;//Calcolo il nodo di sinistra
        int NuovaPallina=(I+1)/2;
        //Passo al livello successivo
        return TrovaPosizionePallina(NuovoNodo,NuovaPallina,D,index+1);    
    }
    
}