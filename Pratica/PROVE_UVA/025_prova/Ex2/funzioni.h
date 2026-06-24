#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_NODI 8
typedef struct{
    /* data */
    char Nodo[MAX_NODI];
    //lista di adiacenza
    int Matrice[MAX_NODI][MAX_NODI];
    int numNodi;
}Grafo;
// Variabili globali per tenere traccia del record
extern int minimoGlob;
extern char soluzioneOttima[MAX_NODI + 1];
extern int usato[MAX_NODI];
/*Metodi*/
void CalcolaSequenza(char attuale[MAX_NODI], int pos, Grafo G,int maxDistanzaCorrente);
int CalcolaDistanzaNodo(int indiceNuovoNodo, int posAttuale, Grafo G, char attuale[]);
int SonoConnessi(Grafo G, char nodoX, char nodoAtt);
#endif
