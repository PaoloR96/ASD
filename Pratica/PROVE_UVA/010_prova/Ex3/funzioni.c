#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int current_n;
//Stampo il dataset
void printDataset(Dataset data) {
    for (int i = 0; i < data.num_sequences; i++) {
        printf("%d %d\n", data.sequences[i].k, data.sequences[i].n);
        for (int j = 0; j < data.sequences[i].k; j++) {
            for (int d = 0; d < data.sequences[i].n; d++) {
                printf("%d ", data.sequences[i].boxes[j].dims[d]);
            }
            printf("\n");
        }
    }
}
//Metodi per ordianre le scatole tramite qsort
int ComparaValori(const void *a, const void *b) {
    Box *boxA = (Box*)a;
    Box *boxB = (Box*)b;
    for (int i = 0; i < current_n; i++) {
        if (boxA->dims[i] < boxB->dims[i]) return -1;
        if (boxA->dims[i] > boxB->dims[i]) return 1;
    }
    return 0;
}

void ordinaDimensioni(Box *b, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (b->dims[i] > b->dims[j]) {
                int tmp = b->dims[i];
                b->dims[i] = b->dims[j];
                b->dims[j] = tmp;
            }
        }
    }
}

void ordinaBoxes(Sequence *seq) {
    for (int i = 0; i < seq->k; i++)
        ordinaDimensioni(&seq->boxes[i], seq->n);

    current_n = seq->n;
    qsort(seq->boxes, seq->k, sizeof(Box), ComparaValori);
}
//Metodi per la logica DP
//1.Inizializzo DP,PARENT
void initDP(int DP[MAX_K], int PARENT[MAX_K], int dim) {
    for (int i = 0; i < dim; i++) {
        DP[i] = 1;
        PARENT[i] = -1;
    } 
}
//2.Verifico se una scatola è contenuta nell'altra
int NestingScatole(int Scatola1[MAX_N], int Scatola2[MAX_N], int dim) {
    for(int i = 0; i < dim; i++) {
        if(Scatola1[i] >= Scatola2[i]) return 0; //non entra
    }
    return 1; //entra
}
//3.Logica DP
void CalcolaDP(int DP[MAX_K], int PARENT[MAX_K], Sequence s) {
    for (int i = 1; i < s.k; i++) { //per ogni scatola i
        for (int j = 0; j < i; j++) { //per ogni scatola precendete j
            if (NestingScatole(s.boxes[j].dims, s.boxes[i].dims, s.n)) {
                if(DP[j] + 1 > DP[i]) {
                    DP[i] = DP[j] + 1;
                    PARENT[i] = j;
                }
            }
        }
    }
}

//4.Stampa ricorsiva per invertire l'ordine dei parent
void stampaPercorso(int idx, int PARENT[MAX_K], Box boxes[]) {
    if (idx == -1) return;
    stampaPercorso(PARENT[idx], PARENT, boxes);
    printf("%d ", boxes[idx].id); // Stampa l'ID 
}