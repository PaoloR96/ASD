#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
#define LEN 100

typedef struct {
    /* data */
    int r;
    int c;
}Posizione;


typedef struct {
    /* data */
    int r;
    int c;
    char Mappa[MAX][LEN];
}CasoTest;




/*VAR GLOBALI*/
extern char Indicazioni[MAX][LEN];
extern char target[];
extern int idx;
/*Metodi*/
void RiempiMappa(char Mappa[MAX][LEN], int r, int c);
void TrovaSequenza(char Mappa[MAX][LEN],int n,int m,Posizione pos_partenza,Posizione pos_arrivo);
Posizione TrovaCoordinate(char Mappa[MAX][LEN],int n,int m,char stringa);
Posizione TrovaProssimaPosizione(char Mappa[MAX][LEN],int n,int m,Posizione posizione_attuale);
void StampaIndicazioni();



#endif
