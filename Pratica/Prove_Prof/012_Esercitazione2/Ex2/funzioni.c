#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
bool IsSafe(int Labirinto[MAX][MAX],int N,int M,int x,int y){
        if(x>=0 && x<N && y>=0 && y<M && Labirinto[x][y]==1)return true;//Posizione(x,y)non valida
        return false; //Posizione(x,y)non valida
}
bool TrovaPercorso(int Labirinto[MAX][MAX],int Percorso[MAX][MAX],int N,int M,int x,int y){
    //1.Condizione di uscita:Sono arrivato alla fine del labirinto
    if (x==N-1 & y==M-1 && Labirinto[x][y]==1){
        Percorso[x][y] = 1; //Piazzo l'1 sulla destinazione
        StampaPercorso(Percorso,N,M);//Stampo il percorso
        return true;
    }
    //2.Andiamo a riempire la matrice Percorso[N][N]
    if(IsSafe(Labirinto,N,M,x,y)){//Se rientro nelle matrice e c'è 1
        Percorso[x][y]=1;//Piazzo 1
        //Ora mi devo spostare per trovare il prossimo 1
        //Ho due possibilità:Andare a destra oppure andare giù
        
        //A.Vado a destra
        if (TrovaPercorso(Labirinto,Percorso,N,M,x+1,y))return 1;
        //B.Vado giù
        if (TrovaPercorso(Labirinto,Percorso,N,M,x,y+1))return 1;
        
        //C.Questo punto è fondamentale:Nel caso in cui le due chiamate ricorsive
        //non hanno seguito attuo il backtackig,ossia resetto a 0 Percorso[x][y]
        //in quanto non mi porta da nessuna parte(PRUNING)
        Percorso[x][y]=0;//Piazzo 0
        return false;
    }
    return false;
}


void InitMatrice(int Labirinto[MAX][MAX],int Percorso[MAX][MAX],int N,int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            Percorso[i][j]=0;
            Labirinto[i][j]=0;
        }  
    }
}


void StampaPercorso(int Percorso[MAX][MAX],int N,int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d \t",Percorso[i][j]);
        }
        printf("\n");
    }
}

void RiempiMatice(int Labirinto[MAX][MAX],int N,int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d",&Labirinto[i][j]);
        }
    }
}

