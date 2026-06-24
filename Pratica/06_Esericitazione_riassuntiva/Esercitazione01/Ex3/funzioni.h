#ifndef FUNZIONI_H
#define FUNZIONI_H

#define N 6

// -------------------------
// FUNZIONI PRINCIPALI
// -------------------------
void stampaMatrice(int matrix[N][N]);
void TrovaSottoMatrice(int M[N][N]);

// -------------------------
// FUNZIONI AUSILIARIE
// -------------------------
int EspandiRiga(int M[N][N], int riga, int colonna);
int EspandiColonna(int M[N][N], int riga, int colonna);
int isFreeRectangle(int M[N][N], int r0, int c0, int h, int w);

// -------------------------
// BACKTRACKING
// -------------------------
void GeneraSottoMatrice(int M[N][N], int r0, int c0);
void BacktrackRettangolo(int M[N][N], int r0, int c0,int h, int w, int maxH, int maxW);

#endif
