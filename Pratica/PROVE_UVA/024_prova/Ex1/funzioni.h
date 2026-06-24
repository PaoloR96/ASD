#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct{
    /* data */
    int num;
    int den;

}Nodo;
/* Variabili globali condivise */
extern char Risultato[2000];
extern int idx;
/*Meotodi*/
void CalcolaSequenza(int m,int n, Nodo R, Nodo L);
void StampaSequenza();

#endif
