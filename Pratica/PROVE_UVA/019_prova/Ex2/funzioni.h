#ifndef FUNZIONI_H
#define FUNZIONI_H
#include<stdbool.h>
#define DIM 8
extern int MaxSomma;
void SommaElementi(int Elementi[DIM],int dim);
void CalcolaSequenza(int M[DIM][DIM],int Elementi[DIM],int posizioni[DIM],int riga);
bool CheckPosizionamento(int posizioni[DIM],int riga,int colonna);
#endif
