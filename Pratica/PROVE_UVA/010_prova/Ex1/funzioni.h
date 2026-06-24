#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_SEQ 100
typedef struct  {
    long maxVal;
    long minVal;
}Risultato;




/*Metodi*/
Risultato DividiSequenza(long long A[MAX_SEQ], int p, int r);
Risultato CalcolaCrossProduction(long long A[MAX_SEQ], int p, int q, int r);
long maxVal(long a, long b);
long minVal(long a, long b);

#endif
