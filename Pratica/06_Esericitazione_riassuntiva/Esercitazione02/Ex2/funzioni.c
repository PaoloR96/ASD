#include <stdio.h>
#include "funzioni.h"
/*variabile globale*/
int config=0;
void StampaMatrice(int N, int A[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}


bool CheckColonna(int N, int A[][N], int colonna) {
    for (int i = 0; i < N; i++) {
        if (A[i][colonna] == 1) return true;
    }
    return false;
}

bool CheckDiagonale(int N, int A[][N], int riga, int colonna) {
    int i, j;

    // ↖ (su-sinistra)
    for (i = riga - 1, j = colonna - 1; i >= 0 && j >= 0; i--, j--)
        if (A[i][j] == 1) return true;

    // ↗ (su-destra)
    for (i = riga - 1, j = colonna + 1; i >= 0 && j < N; i--, j++)
        if (A[i][j] == 1) return true;

    return false;
}

void CheckNRegine(int N, int A[][N], int riga) {
    // caso base: tutte le righe completate
    if (riga == N) {
        config++;
        return;
    }
    // Caso ricorsivo:provo ogni colonna nella riga corrente
    for (int colonna = 0; colonna < N; colonna++) {
        
        if (!CheckColonna(N, A, colonna) &&!CheckDiagonale(N, A, riga, colonna)){
            // posiziono la regina
            A[riga][colonna] = 1;
            // passo alla prossima riga
            CheckNRegine(N, A, riga + 1);
            // backtracking
            A[riga][colonna] = 0;
        }
    }
}

void TrovaSoluzioni(int i,int N){
    int A[N][N];
    config=0;

    // Inizializzo la matrice a 0
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            A[i][j] = 0;
        }
    }

    printf("%d)Per la Matrice %dx%d:\n",i+1 , N, N);  
    //StampaMatrice(N, A);
    CheckNRegine(N, A, 0);
    printf("Numero di configurazioni = %d\n", config);
    printf("\n");
}
