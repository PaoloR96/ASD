#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int TrovaElementoX(int Vett[MAX],int dim,int offset){
    //1.Inizializzo gli indici
    int low=0;
    int high=dim-1;
    //2.Applico la ricerca binaria
    while (low<=high){
        //2.A:Calcolo il punto medio
        int mid=low+(high-low)/2;//in questo modo evito possibili overflow
        //Devo sempre considerare il valore in funzione della prima posizione
        int valore=Vett[0]+(mid*offset);
        if (Vett[mid]>valore){
            high=mid-1;//Sposto la ricerca a sinistra
        }else{
            low=mid+1;//Sposto la ricerca a destra
        }  
    }
    //3.Una volta definito la posizione low applico la formula
    int elementoX=Vett[0]+(low*offset);
    return elementoX;
}
