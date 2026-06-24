#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaMatrice(int M[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}
/*controllo se val è presente sulle righe o sulle colonne*/
int IsValido(int M[N][N],int riga,int colonna,int val){
    /*controllo riga*/
    for (int i = 0; i < N; i++){
            if(M[riga][i]==val)return 0;
    }
    /*controllo colonna*/
    for (int j = 0; j < N; j++){
            if(M[j][colonna]==val)return 0;
    }
    return 1;
}

int RiempiMatrice(int M[N][N], int riga, int colonna){

    /* Caso base:La matrice è completa → stampiamo la soluzione. */
    if (riga == N){
        StampaMatrice(M);
        printf("\n");
        return 1;
    }

    /* Calcolo della prossima cella da riempire:
       - Passo alla colonna successiva
       - Se arrivo a fine riga, passo alla riga seguente e colonna ritorna 0 */
    int next_r = riga;
    int next_c = colonna + 1;
    if(next_c == N){
        next_c = 0;
        next_r++;
    }

    /* Se la cella contiene già un valore (dato iniziale),
       non posso modificarlo → continuo direttamente alla prossima cella */
    if(M[riga][colonna] != 0)
        return RiempiMatrice(M, next_r, next_c);

    /* Provo tutti i possibili valori da 1 a 4 per questa cella */
    for(int num = 1; num <= 4; num++){
        /* Verifico se num è valido:
           - non deve essere già presente nella stessa riga
           - non deve essere già presente nella stessa colonna */
        if(IsValido(M, riga, colonna, num)){

            /* Se è valido, lo inserisco temporaneamente */
            M[riga][colonna] = num;

            /* Procedo ricorsivamente:
               se la ricorsione trova una soluzione → termino */
            if(RiempiMatrice(M, next_r, next_c))return 1;

            /* Se non porta a soluzione → backtracking:
               rimuovo il numero e riprovo con il successivo */
            M[riga][colonna] = 0;
        }
    }

    /* Nessun numero valido trovato → questa strada è sbagliata */
    return 0;
}


void Sudoku(int M[N][N]){
     RiempiMatrice(M,0,0);
}