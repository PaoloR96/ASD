#ifndef FUNZIONI_H
#define FUNZIONI_H

#define SIZE 50

// Prototipi delle funzioni
void RiempiVettore(int A[], int size);
void RiempiQuery(int A[], int size);
void CaolcolaElementi(int N[][SIZE],int n[SIZE],int query[][SIZE],int m[SIZE],int index);
void QuickSort(int A[], int start,int end);
int Partizion(int A[], int start,int end);
int GeneraSommeCoppie(int A[], int dim, int S[]);
void ConfrontaElementi(int S[], int sindex, int query[], int m);
int RicercaBinariaVicino(int S[], int low, int high, int x, int closest);
#endif
