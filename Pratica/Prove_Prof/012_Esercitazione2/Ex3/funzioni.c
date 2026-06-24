#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "funzioni.h"  // Include il file header

bool IsSafe(int Matrice[MAX][MAX],int x,int y,int N,int M){
    if(x>=0 && x<N && y>=0 && y<M && Matrice[x][y]!=INT_MAX)return true; //Rientro nella matrice:STRADA VALIDA
    return false; //NON Rientro nella matrice:STRADA NON VALIDA
}

void TrovaPercorsi(int Matrice[MAX][MAX],int Percorso[MAX],int x,int y,int N,int M,int index){
    //A.Condizione di uscita:Ho trovato il percorso iesimo
    if (x==N-1 && y==M-1){
        Percorso[index]=Matrice[x][y];//Salvo l'ultimo elemento:Cella di destinazione(x,y)
        StampaPercorso(Percorso,index+1);
        printf("\n");
        return; //Termino
    }
    //B.Provo a costruire la sequenza
    //Prima di piazzare devo valutare se la posizione(x,y)sia sicura
    if (IsSafe(Matrice,x,y,N,M)){
            //1.Provo a piazzare un valore
            int tmp=Matrice[x][y];
            Percorso[index]=tmp;
            //2.Segno come letto quel valore
            Matrice[x][y]=INT_MAX;
        
            //Definisco le coordinate(x,y)dove posso spostarmi:destra,giù
            int dx[]={1,0};
            int dy[]={0,1};
        
            for (int i = 0; i < 2; i++){
           
            //3.Passo alla cella successiva
            //Calcolo la direzione in funzione di (x,y)
            int nx=x+dx[i];
            int ny=y+dy[i];
            //Caso:Provo a spostarmi a destra e giù
            TrovaPercorsi(Matrice,Percorso,nx,ny,N,M,index+1);
        }
        //4.Backtracking:Se il programma chiamante non ha seguito torno indietro
        Matrice[x][y]=tmp;
        Percorso[index]=0;
        
    }
}

void InizializzaMatrice(int Matrice[MAX][MAX],int Percorso[MAX],int N,int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            Matrice[i][j]=0;
        }
    for (int i = 0; i < MAX; i++)Percorso[i]=0;
    }
}

void RiempiMatrice(int Matrice[MAX][MAX],int N,int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d",&Matrice[i][j]);
        }
    }

}

void  StampaPercorso(int Percorso[MAX],int dim){
    for (int i = 0; i < dim; i++)printf("%d",Percorso[i]);
}