#ifndef FUNZIONI_H
#define FUNZIONI_H
#define N 4


// Prototipi delle funzioni
void StampaMatrice(int M[N][N]);
void StampaPercorso(int percorso[N*N][2], int k);
void TrovaPercorso(int M[N][N], int visitato[N][N], int percorso[N*N][2], int riga, int colonna, int pos);
void TrovaNSoluzioni(int M[N][N]);



#endif
