#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.h"  // Include il file header
int MaxPercorsoGlobale=0;
void TrovaLunghezzaPercorso(int Matrice[MAX][MAX],int N,int M,int x,int y,int lunghezza){
        //A.Caso base:Sono arrivato alla fine della sequenza,sono arrivato in discesa
        if(ControllaStato(Matrice,N,M,x,y)){
            if(lunghezza>MaxPercorsoGlobale)MaxPercorsoGlobale=lunghezza;
            return;
        }
        //B.Vado alla ricerca del percorso:
        //1.Definisco le direzioni
            int dx[] = {-1, 1, 0, 0};
            int dy[] = { 0, 0, 1,-1};
        //2.Per ogni direzione(sinistra,destra,su,giù) vadoa a capire dove muovermi
        for (int i = 0; i < 4; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                //le nuove coordinate sono incluse nella matrice  && Se l'elemento nella casella (nx,ny) è contenuto (<) nell'elemento nella casella(x,y)
                //allora aggiorono lunghezza e passo al livello successivo
                if(IsSafe(Matrice,N,M,nx,ny) && Matrice[nx][ny]<Matrice[x][y])TrovaLunghezzaPercorso(Matrice,N,M,nx,ny,lunghezza+1);
                //NOTA:BACKTACKING:avviene in modo automatico se il programma chiamante non ha seguito
                //passo al livello successivo, effettuando il pruning di quel ramo e considerando un altro
                //percorso
        }
}
bool IsSafe(int Matrice[MAX][MAX],int N,int M,int x,int y){
    if(x>=0 && x<N && y>=0 && y<M)return true;//Elemento in posizione(x,y)contenuto nella matrice
    return false;

}

bool ControllaStato(int Matrice[MAX][MAX],int N,int M,int x,int y){
     int dx[] = {-1, 1, 0, 0};
     int dy[] = { 0, 0, 1,-1};
            for (int i = 0; i < 4; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                //Se rientro nella matrice e se l'elemento(nx,ny)  è contenuto nell'elemento (x,y) allora mi fermo
                if(IsSafe(Matrice,N,M,nx,ny) && Matrice[nx][ny]<Matrice[x][y])return false;
            }
            return true; //il mio elemento è il più piccolo di tutti 
}

void InizializzaMatrice(int Matrice[MAX][MAX],int N,int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            Matrice[i][j]=0;
        }
    }
}

void RiempiMatrice(int Matrice[MAX][MAX],int N,int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d",&Matrice[i][j]);
        }
    }

}