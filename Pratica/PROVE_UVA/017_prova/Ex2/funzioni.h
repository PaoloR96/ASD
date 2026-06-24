#ifndef FUNZIONI_H
#define FUNZIONI_H
#define N 50
typedef struct {
    /* data */
    int r_x;
    int c_y;
}Posizione;

void InizializzaMatrice(int M[N][N],int dim);
int GeneraPercorso(int M[N][N],int dim,Posizione pos_partenza,Posizione pos_attuale,int conta_mosse);
void StampaMatrice(int M[N][N], int dim);

int EsisteCircuitoPossibile(int dim);
int ContaMosseDisponibili(int M[N][N], int dim, int r, int c);
#endif
