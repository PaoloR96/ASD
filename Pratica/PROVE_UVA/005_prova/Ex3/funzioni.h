#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_L 1000
#define N_MAX 50

typedef struct {
    int l; // lunghezza asta
    int n; //numero di tagli da effettuare
    int ci[MAX_L]; //rappresentano i punti in cui devono essere eseguiti i tagli, forniti in ordine strettamente crescente
    int result[MAX_L + 2]; // vettore con 0 e l agli estremi
}CasoTest;
/*Metodi*/
void InitDp(int dp[N_MAX][N_MAX] ,int n);
CasoTest buildCutsStruct(CasoTest test);
int CalcolaDp(int dp[N_MAX][N_MAX] ,CasoTest T);
int minimo(int a, int b);



#endif
