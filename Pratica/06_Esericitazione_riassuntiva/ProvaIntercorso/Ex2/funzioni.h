#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <stdbool.h>
// Prototipi delle funzioni
  /*  (somma = S, lunghezza sequenza = N, numeri della sequenza maggiori di P) */
void CalcolaSequenza(int s,int n,int p);
void GeneraSequenza(int Seq[],int s,int n,int p,int index,int somma,int prossimoNum);
bool isPrime(int n);
void StampaSequenza(int Seq[],int n);

#endif
