#ifndef FUNZIONI_H
#define FUNZIONI_H
#include<stdbool.h>
// Prototipi delle funzioni
void StampaArray(int A[], int size);
void InsNumeri(int A[], int size);
int BinarySearch(int A[], int left, int right, int val);
void ControllaCoppie(int A[], int startA, int endA, int startB, int endB, int N);
void TrovaProdotto(int A[], int start, int end, int N);

#endif
