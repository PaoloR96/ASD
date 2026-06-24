#ifndef FUNZIONI_H
#define FUNZIONI_H
/*Costanti*/
#define N 1000
////////////////
#define P 100
#define W 30
////////////////
#define G 100
#define MW 30
typedef struct {
    int prezzo;
    int peso;
}Oggetto;
// Prototipi delle funzioni
int CalcolaDP(int dp[W],Oggetto oggetto[N],int dim,int mw[MW],int g);
void InitDP(int dp[W]);
int max(int a, int b);

#endif
