#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
typedef struct funzioni{
    /* data */
    int x;
    int y;
}Coordinate;
/*Metodi*/
void RiempiMatrice(char M[MAX][MAX],int dimR,int dimC);
void StampaSequenza(Coordinate C[MAX],int dim);
int TrovaParola(Coordinate C[MAX], char Parola[MAX], char M[MAX][MAX], int posR, int posC, int dimR, int dimC, int lenParola, int index);
#endif
