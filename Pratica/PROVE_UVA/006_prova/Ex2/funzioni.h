#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_TESSERE 100

// Rappresenta una singola tessera (tipo domino)
typedef struct {
    int sinistra;
    int destra;
} Tessera;

// Rappresenta un intero problema
typedef struct {
    int n; // numero di spazi da riempire
    int m; // numero di tessere disponibili

    Tessera L; // estremo sinistro
    Tessera R; // estremo destro

    Tessera tessere[MAX_TESSERE]; // elenco tessere disponibili
} Problema;

/*metodi*/
int Risolvi(Problema p, int spazi_rimasti, int lastValDx, int usato[MAX_TESSERE]);


#endif
