#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_M 200 //quantità di denaro disponibil
#define MAX_C 20 //numero di indumenti che devi acquistare
#define MAX_K 20 //indica il numero di diversi modelli per quell'indumento

typedef struct {
    int budget;              // denaro disponibile
    int num_indumenti;           
    int num_modelli[MAX_C];  //K per ogni indumento
    int prezzi[MAX_C][MAX_K];      // prezzi dei modelli
} CasiTest;




/*Metodi*/
void stampaCasiTest(CasiTest t);
void inizializzaDp(int dp[MAX_C+1][MAX_M+1],int c,int m);
int calcolaDp(int dp[MAX_C+1][MAX_M+1],CasiTest t);
#endif
