#ifndef FUNZIONI_H
#define FUNZIONI_H
#define N 5


// Prototipi delle funzioni
void StampaLabirinto(int M[N][N]);
void CalcolaPercorsoMin(int M[N][N]);
void TrovaPercorso(int M[N][N], int visitato[N][N], int percorso[N], int riga, int colonna, int pos);
int CellaVietata(int M[N][N], int r, int c);



#endif
