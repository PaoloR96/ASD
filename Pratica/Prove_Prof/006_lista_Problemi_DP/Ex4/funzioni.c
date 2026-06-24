#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int DPMin[MAX][MAX];
int DPMax[MAX][MAX];


void InitDP(int DPMax[MAX][MAX],int DPMin[MAX][MAX],int numeri[MAX],int dim){
    //Inizializzo le diagonali DPMax[i][i] ed DPMax[j][j] a numeri[i]
    for (int i = 0; i < dim; i++){
        DPMax[i][i]=numeri[i];
        DPMin[i][i]=numeri[i];
    }
    
}


Risultato CalcolaDP(int DPMax[MAX][MAX],int DPMin[MAX][MAX], char operatori[MAX], int dim){
    Risultato r={0,0};
    //Ricorrenza:Vado a costruire la mia sequenza partendo dalla lunghezza minima pari a 2
    for (int len = 2; len <= dim; len++){
        //Definisco il mio intervallo di osservazione(i,j)
        for (int i = 0; i <=dim-len; i++){
            int j=i+len-1;
            //Definisco il cuore di questo approccio: vado a valutare i k £(i,j)
            // Inizializziamo la struttura in posizione [i][j]
            DPMax[i][j] = 0;
            DPMin[i][j] = INT_MAX;
            for (int k = i; k< j; k++){
                int succ_max=0;
                int succ_min=0;
                if (operatori[k]=='+'){//se ho un addizione
                    succ_max=DPMax[i][k]+DPMax[k+1][j];
                    succ_min=DPMin[i][k]+DPMin[k+1][j];
                }else if(operatori[k]=='*'){//se ho una moltiplicazione
                    succ_max=DPMax[i][k]*DPMax[k+1][j];
                    succ_min=DPMin[i][k]*DPMin[k+1][j];
                }
                //Aggiorno il massimo ed il minimo della struttura  DPMax ed DPMin
                if (succ_max> DPMax[i][j]) DPMax[i][j]=succ_max;
                if (succ_min< DPMin[i][j]) DPMin[i][j]=succ_min;
            }
        }
    }
    //Salvo i risultati 
    r.massimo= DPMax[0][dim-1];
    r.minimo= DPMin[0][dim-1];
    return r;

}
    
        