#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiCasoTest(Strada Mappa[MAX],int dim_e){
    for (int i = 0; i < dim_e; i++){
        scanf("%d %d",&Mappa[i].f,&Mappa[i].t);
    }
}
/*Variabili Globali*/
int PosizionaGuardia[MAX];
int StatoIncrocio[MAX];
int min;
int trovato_valido;
void Risolvi(int incrocio_attuale,Strada Mappa[MAX],int num_strade,int num_incroci){
    // Caso base: abbiamo deciso per tutti gli incroci
    if(incrocio_attuale==num_incroci){
        if(CeckCopertura(Mappa,num_strade)){
            int conteggio=0;
            //conto il numero di guardie pizzate
            for (int i = 0; i < num_incroci; i++){
                 if(PosizionaGuardia[i]==1)conteggio++;
            }
            if(conteggio<min){
                min=conteggio;
                trovato_valido=1;
            }
        }
        return;
    }
    //Ricorrenza:Devo posizione le guardie
    //Tentativo 1: Metto la guardia
    if(ControllaIncrocio(incrocio_attuale,Mappa,num_strade)){
        PosizionaGuardia[incrocio_attuale]=1;//posiziono la guardia
        Risolvi(incrocio_attuale+1,Mappa,num_strade,num_incroci);//passo all'incrocio successivo
        PosizionaGuardia[incrocio_attuale]=0;//backtrking
    }
    //Tentativo 2: non Metto la guardia
    PosizionaGuardia[incrocio_attuale]=0;
    Risolvi(incrocio_attuale+1,Mappa,num_strade,num_incroci);
}


// Verifica se TUTTE le strade sono sorvegliate da almeno una guardia
int CeckCopertura(Strada Mappa[], int num_strade){
    for (int i = 0; i < num_strade; i++){
        if(PosizionaGuardia[Mappa[i].f]==0 && PosizionaGuardia[Mappa[i].t]==0) return 0; //strada scoperta
    }
    return 1;  
}
// Funzione di controllo: verifica che non ci siano liti tra guardie
int ControllaIncrocio(int incrocio_attuale, Strada Mappa[], int num_strade) {
    for (int i = 0; i < num_strade; i++){
        int vicino=-1;
        //Vediamo quale estremo prendere
        if(Mappa[i].t==incrocio_attuale)vicino=Mappa[i].f;
        else if(Mappa[i].f==incrocio_attuale)vicino=Mappa[i].t;
        
        // Se l'incrocio collegato ha già una guardia, qui non posso metterla
        if(vicino!=-1 &&PosizionaGuardia[vicino]==1)return 0;// Conflitto: due guardie sulla stessa strada    
    }
    return 1;
}