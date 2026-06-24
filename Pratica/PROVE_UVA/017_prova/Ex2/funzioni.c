#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void InizializzaMatrice(int M[N][N],int dim){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
             M[i][j]=0;
        }    
    }
}


  
int GeneraPercorso(int M[N][N], int dim, Posizione pos_partenza, Posizione pos_attuale, int conta_mosse) {
    
    //1.CASO BASE: Verifica completamento del tour
    if (conta_mosse == dim * dim) {
        // Calcoliamo la distanza tra l'ultima posizione e quella iniziale
        int dx_final = abs(pos_attuale.r_x - pos_partenza.r_x);
        int dy_final = abs(pos_attuale.c_y - pos_partenza.c_y);
        
        // Un "Knight's Circuit" richiede che il cavaliere possa tornare alla casella iniziale con una mossa legale
        if ((dx_final == 2 && dy_final == 1) || (dx_final == 1 && dy_final == 2)) {
            StampaMatrice(M, dim);
            return 1; // Circuito trovato: interrompe la ricorsione
        }
        return 0; // Se non può tornare alla partenza, non è un circuito valido           
    }

    //2. CASO RICORSIVO: Esplorazione delle mosse
    // Definiamo gli 8 possibili spostamenti a "L" del cavaliere
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    // --- Ottimizzazione: Regola di Warnsdorff ---
    // Invece di provare le mosse casualmente, le ordiniamo per "grado" (mosse future disponibili)
    int indici[8], gradi[8], n_mosse = 0;
    
    // Identifichiamo quali delle 8 mosse sono legali (dentro i bordi e su caselle libere)
    for (int i = 0; i < 8; i++) {
        int nx = pos_attuale.r_x + dx[i];
        int ny = pos_attuale.c_y + dy[i];
        
        // Verifica che la coordinata (nx, ny) sia inclusa nella scacchiera e non ancora visitata
        if (nx >= 0 && nx < dim && ny >= 0 && ny < dim && M[nx][ny] == 0) {
            indici[n_mosse] = i; // Memorizza l'indice della direzione
            gradi[n_mosse] = ContaMosseDisponibili(M, dim, nx, ny); // Calcola l'accessibilità futura
            n_mosse++;
        }
    }

    // Bubble sort: ordiniamo le mosse in modo da processare prima quelle verso caselle con MENO uscite libere.
    // Questa euristica riduce drasticamente il tempo di calcolo evitando vicoli ciechi.
    for (int i = 0; i < n_mosse - 1; i++) {
        for (int j = i + 1; j < n_mosse; j++) {
            if (gradi[i] > gradi[j]) {
                int tempG = gradi[i]; gradi[i] = gradi[j]; gradi[j] = tempG;
                int tempI = indici[i]; indici[i] = indici[j]; indici[j] = tempI;
            }
        }
    }

    //3.BACKTRACKING: Tentativi di movimento
    for (int i = 0; i < n_mosse; i++) {
        int idx = indici[i];
        int nx = pos_attuale.r_x + dx[idx];
        int ny = pos_attuale.c_y + dy[idx];

        // Segnamo il passo sulla scacchiera con il numero d'ordine corrente
        M[nx][ny] = conta_mosse + 1;
        Posizione prossima = {nx, ny};
        
        // Chiamata ricorsiva: se questa strada porta a una soluzione, risaliamo la catena con 1
        if (GeneraPercorso(M, dim, pos_partenza, prossima, conta_mosse + 1)) return 1;
        
        // Se la strada è un vicolo cieco, annulliamo la mossa (BACKTRACKING) e proviamo la prossima
        M[nx][ny] = 0; 
    }
    return 0; // Nessuna mossa da questa posizione porta a una soluzione
}    
       
void StampaMatrice(int M[N][N], int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            // %5d stampa il numero giustificato a destra in un campo di 5 spazi
            printf("%5d", M[i][j]);
        }
        printf("\n"); 
    }
}



//Controlla se la scacchiera può teoricamente ospitare un circuito
int EsisteCircuitoPossibile(int dim) {
    // Un Knight's Circuit è impossibile se N è dispari
    if (dim % 2 != 0) return 0;
    return 1;
}

//Conta quanti salti legali sono possibili da una cella
int ContaMosseDisponibili(int M[N][N], int dim, int r, int c) {
    int count = 0;
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
    for (int i = 0; i < 8; i++) {
        int nx = r + dx[i];
        int ny = c + dy[i];
        if (nx >= 0 && nx < dim && ny >= 0 && ny < dim && M[nx][ny] == 0)count++;
    }
    return count;
}