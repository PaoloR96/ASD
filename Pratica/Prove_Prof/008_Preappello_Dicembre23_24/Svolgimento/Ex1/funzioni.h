#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
/*Metodi*/
void InserisciMatrice(int Matrice[MAX][MAX], int N, int M);
int ComparaElemRiga(const void *a, const void *b);
void OrdinaPerRiga(int Matrice[MAX][MAX], int N, int M);
int CalcolaDiff(int Matrice[MAX][MAX], int N, int M);
int CalcolaSequenza(int RigaX[MAX], int RigaY[MAX], int N, int M);
int RicercaBinaria(int RigaX[MAX], int M, int target);

#endif
