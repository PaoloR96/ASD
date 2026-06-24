#ifndef FUNZIONI_H
#define FUNZIONI_H

#define SIZE 50  // Dimensione massima degli array

// Prototipi delle funzioni
void RiempiVettore(int A[], int size);
void CalcolaSwap(int A[][SIZE], int n[], int dim);
int MergeSort(int A[], int left, int right);
int Merge(int A[], int left, int mid, int right);

#endif

