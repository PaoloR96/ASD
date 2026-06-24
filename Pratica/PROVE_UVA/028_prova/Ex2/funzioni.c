#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"  // Include il file header
void RiempiMappa(char Mappa[MAX][LEN], int r, int c) {
    int i, j;

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf(" %c", &Mappa[i][j]);
        }
    }
}
Posizione TrovaCoordinate(char Mappa[MAX][LEN],int n,int m,char stringa){
    Posizione pos;
    for (int r = 0; r < n; r++){
        for (int c = 0; c < m; c++){
            //Se ho trovato stringa (@'oppure'#')definisco rispettivamente punto di partenza o arrivo 
            if(Mappa[r][c]==stringa){
                pos.r=r;
                pos.c=c;
                return pos;
            }
        }
    }
    return pos;
}
char Indicazioni[MAX][LEN];
int idx;
void TrovaSequenza(char Mappa[MAX][LEN],int n,int m,Posizione pos_attuale,Posizione pos_arrivo){
        //1.Condizione di uscita:Sono arrivato ad #
        if(pos_attuale.r==pos_arrivo.r &&  pos_attuale.c==pos_arrivo.c){
            //Stampo la sequenza
            StampaIndicazioni();
            return;
        }
        //2.Mi muovo all'interno della mappa
        //NOTA:poichè è un backtracking deteministico, non ho for
        Posizione posX=TrovaProssimaPosizione(Mappa,n,m,pos_attuale);
        if (posX.r!=-1 && posX.c!=-1){
            //aggiorno la nuova posizione
            pos_attuale=posX;
            //Passo al livello successivo a partire dalla nuova posizione
            TrovaSequenza(Mappa,n,m,pos_attuale,pos_arrivo);
            //NOTA:Il backtracking avvinee il modo automatico
        }
        
}
char target[] = "IEHOVA#";
Posizione TrovaProssimaPosizione(char Mappa[MAX][LEN],int n, int m,Posizione posizione_attuale){
        Posizione pos={-1,-1};
        int r=posizione_attuale.r;
        int c=posizione_attuale.c;
        //Considero 4 casi:
        //1.Prova FORTH (r-1, c)
        if(r-1>=0 && Mappa[r-1][c]==target[idx]){
                strcpy(Indicazioni[idx],"forth");
                idx++;
                //aggiorno la posizione;
                pos.r=r-1;
                pos.c=c;
                return pos;
        }
        //2.Prova LEFT (r, c-1)
        if(c-1>=0 && Mappa[r][c-1]==target[idx]){
                strcpy(Indicazioni[idx],"left");
                idx++;
                //aggiorno la posizione;
                pos.r=r;
                pos.c=c-1;
                return pos;
        }
        //3.Prova RIGHT (r, c)
         if(c+1<m  && Mappa[r][c+1]==target[idx]){
                strcpy(Indicazioni[idx],"right");
                idx++;
                //aggiorno la posizione;
                pos.r=r;
                pos.c=c+1;
                return pos;
        }
        return pos;
}

void StampaIndicazioni() {
    for (int i = 0; i < idx; i++) {
        printf("%s%s", Indicazioni[i], (i == idx - 1 ? "" : " "));
    }
    printf("\n");
}