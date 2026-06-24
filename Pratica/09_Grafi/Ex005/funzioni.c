#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void InserimentoCasiTest(char T[M][N],int visitato[M][N],int r,int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
             scanf(" %c",&T[i][j]);
             visitato[i][j]=0; //setto a 0 la casella(i,j)
        }
    }
}

void ElaboraCasiTest(CasoTest T[],int dim){
    for (int i = 0; i < dim; i++){ //per ogni caso di test i
        //1.Analizzo ogni caso di test i
        int giagimento=AnalizzaDepositoX(T[i].T,T[i].visitato,T[i].n,T[i].m);
        printf("%d ",giagimento);
    }
    
}

int AnalizzaDepositoX(char T[M][N],int visitato[M][N],int R,int C){
        int giacimenti=0;
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if (T[i][j]=='o' && !visitato[i][j]){
                    giacimenti++;
                    //chiamo il dfs
                    Dfs(T,visitato,R,C,i,j);
                    
                }
            }
        }
        return giacimenti;
}

void Dfs(char T[M][N],int visitato[M][N],int R,int C,int rx,int cx){
        //1. Setto visitato a 1
        visitato[rx][cx]=1;
        // 2. Controllo gli 8 vicini (Orizzontali, Verticali, Diagonali)
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < 8; i++){
            //calcolo le coordiante
            int nr=rx+dr[i];
            int nc=cx+dc[i];
            if(isSafe(nr,nc,R,C)&&T[nr][nc]=='o' && !visitato[nr][nc]){
                //esploro i vicini
                Dfs(T,visitato,R,C,nr,nc);
            }

        }
}


int isSafe(int r, int c, int R, int C) {
    // Ritorna 1 (vero) se siamo dentro i limiti della matrice, 0 (falso) altrimenti
    return (r >= 0 && r < R && c >= 0 && c < C);
}

