#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void CalcolaDistanzaHamming(int Sequnza[MAX],int SpazioDisp,int H, int index){
        //1.Condizione di Uscita:Ho creato la sequenza
        if (SpazioDisp==0){
            if (H==0){//Se ho usato gli H uno richiesti
                StampaSequenza(Sequnza,index);
            }
            return;    
        }
        //2.Ricorsione:Devo creare la sequenza
        //CASO A:Provo ad inserire 1 
        if (H>0){
            Sequnza[index]=1;
            CalcolaDistanzaHamming(Sequnza,SpazioDisp-1,H-1,index+1);
            Sequnza[index]=0;//BACKTRACKING:Nel caso in cui questa chiamata non porta ad una soluzione consona torno indietro
        }
        //CASO B:Provo ad inserire 0: 
        // Posso mettere 0 solo se lo spazio rimasto è maggiore degli 1 che devo ancora inserire,in modo tale da completare la sequenza
        if (SpazioDisp>H){
            Sequnza[index]=0;
            CalcolaDistanzaHamming(Sequnza,SpazioDisp-1,H,index+1);
        }
        
}


void StampaSequenza(int Sequnza[MAX],int dim){
    for (int i = 0; i < dim; i++)printf("%d ",Sequnza[i]);
    printf("\n");
}