#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiMatrice(char M[MAX][MAX], int dimR, int dimC){
    for(int i = 0; i < dimR; i++){
        for(int j = 0; j < dimC; j++){
            scanf(" %c", &M[i][j]); 
        }
    }
}

void StampaSequenza(Coordinate C[MAX], int dim){
    for(int i = 0; i < dim; i++)printf("%d %d\n", C[i].x+1, C[i].y+1);
}


int TrovaParola(Coordinate C[MAX],char Parola[MAX],char M[MAX][MAX],int posR,int posC,int dimR,int dimC,int lenParola,int index){
        // A. Condizione di uscita: Ho trovato la parola intera
        if (index==lenParola){
            StampaSequenza(C,index);
            return 1;
        }

        //B.Bisogna creare la sequenza
        //B.1:Dobbiamo capire da che parola poter partire
        if (index==0){
            for (int i = 0; i < dimR; i++){
                for (int j = 0; j < dimC; j++){
                    if (Parola[index]==M[i][j]){
                        //1.Salvo la parola
                        char Tmp=M[i][j];
                        //2.Segno di averla letta
                        M[i][j]='*';
                        //3.Salvo le coordinate
                        C[index].x=i;
                        C[index].y=j;
                        //4.Passo alla parola successiva
                        if (TrovaParola(C,Parola,M,i,j,dimR,dimC,lenParola,index+1))return 1;
                        M[i][j]=Tmp;//BACKTRACKING
                        //NOTA: SE TrovaParola non ha riscontro allora torno indientro reinserendo la parola
                    }
                    
                }   
            }
        return 0;// La parola non è stata trovata 
        
        //C.Ora bisogna trovare i caratteri successivi (index>0)
        //Come suggerisce la traccia mi devo spostare tra le 8 direzioni
        }else{
            int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Variazioni riga
            int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // Variazioni colonna
            //Mi sposto a partire (posR,posC) nelle 8 direzioni adiacenti
            for (int i = 0; i < 8; i++){
                int nx=dx[i]+posR;
                int ny=dy[i]+posC;
                //Se la posizione calcolata rientra nella matrice
                if(nx>=0 && nx<dimR &&  ny>=0 && ny<dimC){
                    if (Parola[index]==M[nx][ny]){
                            //1.Salvo la parola
                            char Tmp=M[nx][ny];
                            //2.Segno di averla letta
                            M[nx][ny]='*';
                            //3.Salvo le coordinate
                            C[index].x=nx;
                            C[index].y=ny;
                            //4.Passo alla parola successiva
                            if (TrovaParola(C,Parola,M,nx,ny,dimR,dimC,lenParola,index+1))return 1;
                            M[nx][ny]=Tmp;//BACKTRACKING
                            //NOTA: SE TrovaParola non ha riscontro allora torno indientro reinserendo la parola
                    }
                }
            }    
        }
        return 0; // Nessun percorso valido da questa cella
}