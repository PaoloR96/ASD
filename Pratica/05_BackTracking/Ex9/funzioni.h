#ifndef FUNZIONI_H
#define FUNZIONI_H
#define N   4
// Prototipi delle funzioni

void StampaMatrice(int M[N][N]);
int IsValido(int M[N][N],int riga,int colonna,int val);
int RiempiMatrice(int M[N][N], int riga, int colonna);
void Sudoku(int M[N][N]);


#endif
