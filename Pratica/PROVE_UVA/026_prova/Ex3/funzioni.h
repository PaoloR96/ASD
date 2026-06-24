#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
typedef struct {
    /* data */
    //Definisco le coordinate(x,y,z)
    int h;
    int lunghezza;
    int larghezza;
    //Calcolo la base
    int base;
}Blocco;


/*VAR GLOBALI*/
extern int DP_H[MAX];
/*METODI*/
void RiempiBlocchi(Blocco B[MAX], int n_tipi);
void InitDP(int DP_H[MAX],Blocco B[MAX],int dim);
int CalcolaDP(int DP_H[MAX],Blocco B[MAX],int numB);
int ComparaBlocchi(const void *a,const void *b);
int max2(int a,int b);
#endif
