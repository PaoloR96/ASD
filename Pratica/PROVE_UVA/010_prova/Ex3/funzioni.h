#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX_SEQ 10
#define MAX_K 30
#define MAX_N 10

// --- GLOBAL ---
extern int current_n; 

typedef struct {
    int id;             
    int dims[MAX_N];
} Box;

typedef struct {
    int index;           
    int k;               // numero scatole 
    int n;               // dimensione 
    Box boxes[MAX_K];    
} Sequence;

typedef struct {
    int num_sequences;
    Sequence sequences[MAX_SEQ];
} Dataset;

/* Metodi */
void printDataset(Dataset data);
//Metodi per ordinare le scatole
void ordinaBoxes(Sequence *seq);
void ordinaDimensioni(Box *b, int n);
int ComparaValori(const void *a, const void *b);
//Metodi per applicare la logica di DP
void initDP(int DP[MAX_K], int PARENT[MAX_K], int dim);
int NestingScatole(int Scatola1[MAX_N], int Scatola2[MAX_N], int dim);
void CalcolaDP(int DP[MAX_K], int PARENT[MAX_K], Sequence s);
void stampaPercorso(int idx, int PARENT[MAX_K], Box boxes[]);

#endif