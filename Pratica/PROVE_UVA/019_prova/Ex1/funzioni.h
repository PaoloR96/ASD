#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100

typedef struct {
    int id;
    int valore;
    int freq;
    int start;
    int end;
} Blocco;

typedef struct {
    int start;
    int end;
} Query;

/*Metodi*/
int CreazioneMappa(Blocco *B, int Input[MAX], int dim);
void buildSegmentTree(Blocco *B, int nodo, int inizio, int fine);
int querySegmentTree(int nodo, int inizio, int fine, int l, int r);
int CalcolaQuery(Blocco *B, int Sequenza[MAX], int start, int end, int ultimo_id);

#endif
