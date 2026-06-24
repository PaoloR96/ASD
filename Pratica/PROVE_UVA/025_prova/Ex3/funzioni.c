#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiMatrice(int M[N][N], int n_effettivo) {
    char buffer[100]; // Buffer per la riga di caratteri
    for (int i = 0; i < n_effettivo; i++) {
        scanf("%s", buffer); // Legge la stringa di '0' e '1' 
        for (int j = 0; j < n_effettivo; j++) {
            M[i][j] = buffer[j] - '0'; // Converte il carattere in intero 
        }
    }
}


void InizializzaDP(int DP_H[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            DP_H[i][j]=0;
        }
    }
}
/*variabile globale*/
int DP_H[N][N];
//Devo calcolare la max area dell'istogramma
int CalcolaDp(int DP_H[N][N],int M[N][N]){
    int max_area = 0;
    
    //Per ogni elemento della mia matrice
    for (int i = 0; i < N; i++){
        //Passo1:Calcolo l'instrogramma considerando tutti 1 relativo alla mia riga i
        for (int j = 0; j < N; j++){
            if (M[i][j]==1){//se la cella è 1 
               DP_H[i][j] = (i == 0) ? 1 : DP_H[i-1][j] + 1; //l'altezza viene incrementato di 1+la riga di sopra
            }else{
                DP_H[i][j]=0;//azzero altezza
            }
        }
        
        //Passo2:Calcolo l'area massima dell'instrogramma relativo alla riga i
        for (int j = 0; j < N; j++){
            int h_min=DP_H[i][j];
            //valuto gli elementi precedenti a j presenti nella riga i che siamo analizzando
            for (int k = j; k >= 0; k--){
                // Se trovo una colonna di altezza 0, non posso formare un rettangolo contiguo
                if(DP_H[i][k]==0)break;
                // L'altezza del rettangolo è limitata dal pilastro più basso tra k e j
                if(DP_H[i][k]<h_min)h_min=DP_H[i][k];//aggiono h_min
                //Passo3:Calcolo area
                int area = h_min * (j - k + 1);
                if (area > max_area) max_area = area;
            }
        }
    }
    return max_area;
}