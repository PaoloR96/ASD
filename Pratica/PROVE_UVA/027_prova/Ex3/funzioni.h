#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX  20001
typedef struct{
    /* data */
    int n; //numero banconote
    int Monete[MAX]; //banconote

}CasoTest;

typedef struct{
    /* data */
    int importoTot; //importo totale
    int n; //numeoro banconote

}Risultato;
/*VAR GLOBALE*/
extern int DP[MAX];
/*metodi*/
Risultato CalcolaDP(int DP[MAX],int Monete[MAX],int numM,int prezzoOggetto);
void InitDp(int DP[MAX]);
int min2(int a,int b);
#endif
 