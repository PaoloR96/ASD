#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void GeneraCombinazione(char Stringa[MAX],int idx_lett,char Insieme[MAX],int idx_scr){
        //1.Condizione di uscita:Ho terminato la iesima sequenza
        if (Stringa[idx_lett]=='\0'){//Ho letto tutta la stringa
            Insieme[idx_scr]='\0';//chiudo la stringa
            StampaSequenza(Insieme,idx_scr);
            return;
        }
        //2.Costruisco la ricorrenza
        Insieme[idx_scr]=Stringa[idx_lett];//Provo ad inserire un carattere *
        //Aggiorno indx_lett:Se sono arrivato alla fine faccio scattare la condizione di uscita
        //poichè non devo aggiungere altri spazi
        if (Stringa[idx_lett+1]=='\0'){
            GeneraCombinazione(Stringa,idx_lett+1,Insieme,idx_scr+1);
        //Non sono arrivato alla fine
        }else{
            //2.A:Genero il Ramo 1:Passo alla prossima lettera
            GeneraCombinazione(Stringa,idx_lett+1,Insieme,idx_scr+1);
            //2.B:Genero il Ramo 2:Passo all'inserimento dello spazio nella riga successiva
            //NOTA:idx_scr+2 perchè in un colpo solo inserisco due caratteri(all'inizio della funzione * e lo spazio)
           Insieme[idx_scr+1]=' ';
            GeneraCombinazione(Stringa,idx_lett+1,Insieme,idx_scr+2);
        }
        
}
void StampaSequenza(char Insieme[MAX],int dim){
    int i=0;
    while (Insieme[i]!='\0'){
        printf("%c",Insieme[i]);
        i++;
    }
    printf("\n");
}