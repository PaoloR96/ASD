#ifndef FUNZIONI_H
#define FUNZIONI_H
/*costanti*/
#define MAX_TEST 10 // per questioni di spazio di memoria metto 10
#define MAX_N 1000
#define MAX_P 100
#define MAX_W 30
#define MAX_G 100
#define MAX_MW 30

/*Struttura dati*/
typedef struct{
        int prezzo;
        int peso;
}Oggetto;

typedef struct {
    int n;//numero oggetti
    Oggetto oggetti[MAX_N];
    int g;//numero di persone
    int maxPeso[MAX_G];// capacità di ciascuna persona (MW)
    
}CasoTest;
/*Metodi*/
void initDP(int DP[MAX_MW],int dim);
void CalcolaDP(int DP[MAX_MW],CasoTest test);
int max(int a, int b);

#endif
