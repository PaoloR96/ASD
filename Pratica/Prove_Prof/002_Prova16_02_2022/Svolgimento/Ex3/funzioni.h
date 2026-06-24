#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX_B 201 // Budget + 1
#define MAX_C 21  // Classi + 1

typedef struct {
    int budget;
    int num_classi;
    int prezzi[MAX_C][21];      // prezzi[classe][prodotto]
    int num_prodotti[MAX_C];    // quanti prodotti per ogni classe
} CasoTest;
/*VAR GLOBALE*/
extern int DP[MAX_C][MAX_B];
/*Metodi*/
int CalcolaSequenza(CasoTest ct,int DP[MAX_C][MAX_B]);
void InitDP(int DP[MAX_C][MAX_B],int num_classi,int budget);
void RiempiClasse(CasoTest *ct, int index);
#endif