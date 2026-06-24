#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
typedef struct {
    /* data */
    int dim;
    int Seq[MAX];
}CasoTest;

void Merge(int A[MAX],int p, int r);
void MergeSort(int A[MAX],int p,int q,int r);
void StampaSeq(int A[MAX],int dim);
#endif
