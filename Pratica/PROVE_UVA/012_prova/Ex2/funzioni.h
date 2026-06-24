#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 10
#define RC 8

typedef struct {
    /* data */
    int n;
    char Scacchiera[RC][RC];
}CasoTest;

void RiempiCasoTest(char Scacchiera[RC][RC],int n);
void PosizionaRegina(char Scacchiera[RC][RC],int n,int riga);
int CheckDiagonaleSX(char Scacchiera[RC][RC], int riga, int col, int n);
int CheckDiagonaleDX(char Scacchiera[RC][RC], int riga, int col, int n);
int CheckVerticale(char Scacchiera[RC][RC], int riga, int col, int n);



#endif
