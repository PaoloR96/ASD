#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header


int Risolvi(Problema p, int spazi_rimasti, int lastValDx, int usato[MAX_TESSERE]){
            //condizione di uscita
            if(spazi_rimasti==0){//se ho riempito tutti gli spazi
                if(lastValDx==p.R.sinistra)return 1; //se l'ultimo valore a dx== con il valore sx dell'ultima tessera riempimento CORRETTO
                return 0;
            }
            //ricorsione
            for (int i = 0; i <p.m; i++){//per ogni tessera i del mazzo m
                if (!usato[i]){//se la tessera i non è stata 
                    // Caso A: La tessera entra così com'è (sinistra == lastValDx)
                    if(p.tessere[i].sinistra==lastValDx){
                        usato[i]=1;//USATA
                        if(Risolvi(p,spazi_rimasti-1,p.tessere[i].destra,usato)==1)return 1;
                        usato[i]=0; //BACKTRACK:libera
                    // Caso B: La tessera entra in modo invertito (destra == lastValDx) 
                    }else if (p.tessere[i].destra==lastValDx){
                        usato[i]=1;//USATA
                        if(Risolvi(p,spazi_rimasti-1,p.tessere[i].sinistra,usato)==1)return 1;
                        usato[i]=0;//BACKTRACK:libera
                        
                    }
                } 
            }
}