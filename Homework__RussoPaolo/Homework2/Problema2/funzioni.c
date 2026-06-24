#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

/*Inizializzazione: Ogni singolo elemento dell'array, preso singolarmente,costituisce una sottosequenza di lunghezza 1.*/
void InitDP(int DP[MAX],int n){
    for (int i = 0; i <n ; i++)DP[i]=1;
}

/*Ricerca del massimo*/
int max2(int a,int b){return(a>b)?a:b;}


/*Risoluzione del problema:Calcolo la lunghezza della Longest Increasing Subsequence (LIS)*/
int CalcolaDP(int DP[MAX],int arr[MAX],int n){
    //Passo 0:Definisco la massima lunghezza trovata. Inizializzato a 1 in modo tale da gestire il caso base
    int MaXGlobale=1;
    //Passo 1:Inizio con la ricerca
    for (int i = 1; i < n; i++){//Per ogni elemento i-esimo di arr[n]
        int valX=arr[i];
        //Vado a valutare tutti gli elementi j precedenti ad i, considero la finestra j in [0, i)
        for (int j = 0; j < i; j++){
            //Passo 2: Valuto le condizioni di estensione
            if (arr[j]<valX){//Se il VALORE in j è minore del valore in i, allora posso allungare la sequenza in modo crescente
                //La nuova lunghezza in i è il massimo tra quella attuale e quella di j incrementata di 1  
                DP[i]=max2(DP[i],DP[j]+1);
            }
        }
        //Aggiorno il massimo globale se la sottosequenza ottimale 
        //terminante in i è la più lunga trovata finora
        MaXGlobale=max2(DP[i],MaXGlobale); 
    }
    //Passo 3:Ritorna la lunghezza della sottosequenza crescente più lunga
    return MaXGlobale;
}