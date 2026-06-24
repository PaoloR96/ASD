#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
typedef struct{
    /* data */
    int numeroViaggi;
    int TempoStimato;
}Risultato;
/*Metodi*/
/*
n=capienza traghetto
t=tempo tragitto
m=numero di auto al terminal
Tempi[]=tempi arrivi auto
*/
Risultato CalcolaViaggio(int n,int t,int m, int Tempi[MAX]);

#endif
