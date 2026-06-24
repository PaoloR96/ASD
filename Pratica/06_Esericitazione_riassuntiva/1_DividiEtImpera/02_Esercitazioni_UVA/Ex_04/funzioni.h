#ifndef FUNZIONI_H
#define FUNZIONI_H

#define SIZE 50  // massimo numero di scimmie o query

// Prototipi delle funzioni
void RiempiVettore(int A[], int size);
void TrovaValori(int scimmie[], int N, int query[], int Q);
int UpperBound(int A[], int q, int low, int high);
int LowerBound(int A[], int q, int low, int high);

#endif
