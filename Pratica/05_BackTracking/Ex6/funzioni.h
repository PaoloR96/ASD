#ifndef FUNZIONI_H
#define FUNZIONI_H
#define N 4   // definisce la dimensione della matrice

// Prototipi delle funzioni

void InitMatrice(int M[N][N]);
void StampaMatrice(int M[N][N]);
int posizioneValida(int M[N][N],int riga,int colonna);
int posizionaRegina(int M[N][N], int riga);
void risolviNRegine(int M[N][N]);


#endif
