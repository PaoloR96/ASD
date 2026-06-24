#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void CalcolaSequenza(int M[DIM][DIM],int Elementi[DIM],int posizioni[DIM],int riga){
    //Caso base:Ho costruito la sequenza, calcolo la somma che posso raggiungere
    if(riga==DIM){
        SommaElementi(Elementi,DIM);
        return;
    }
    //Ricorrenza:Provo a creare la mia sequenza
    for (int colonna = 0; colonna < DIM; colonna++){
        if(CheckPosizionamento(posizioni,riga,colonna)){
            //salvo la posizione per i prossimi controlli
            posizioni[riga] = colonna;
            //salvo l'elemento
            Elementi[riga]=M[riga][colonna];
            CalcolaSequenza(M,Elementi, posizioni,riga+1);
           // Il backtracking avviene naturalmente tornando al ciclo for
            // e sovrascrivendo Elementi[riga] al prossimo tentativo
        }        
    }
}

int MaxSomma=-1;
void SommaElementi(int Elementi[DIM],int dim){
    int SommaTmp=0;
    for (int i = 0; i < dim; i++)SommaTmp+=Elementi[i];
    if(SommaTmp>MaxSomma)MaxSomma=SommaTmp;
    
}

bool CheckPosizionamento(int posizioni[DIM],int riga,int colonna){
    for (int i = 0; i < riga; i++){
        //1.Controllo stessa colonna
        if(posizioni[i]==colonna)return false;
        //2.Controllo diagonali
        // Se la distanza tra le righe è uguale alla distanza tra le colonne,
        // le regine sono sulla stessa diagonale.
        if( (abs(posizioni[i]-colonna)) ==(abs(i-riga)))return false;
    } 
    return true;
}