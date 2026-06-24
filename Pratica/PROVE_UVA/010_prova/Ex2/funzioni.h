#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX 100
#define MAX_MOSSE 64

typedef struct {
    int index;
    char start_col;
    int start_row;
    char end_col;
    int end_row;
} Posizione;


typedef struct {
    int x;
    int y;
} Coppia;


typedef struct {
    int index;
    char start;
    int end;
} Percorso;
extern int recordMin;
/*Metodi*/
//Stampa Mosse
void stampaMosse(Posizione mosse[], int n);
//Funzioni di conversione numero <-->lettere
int LetteraInNumero(char lettera);
char NumeroInLettera(int numero);
//metodo principale per attuare il backtrakking
void TrovaPercorso(Posizione mossax, Coppia mossaAtt, Percorso ListaMosse[], int cont);
//verifico se per ogni mossa soddisfa i requisiti:
//1)Calcolo tutte le possibili mosse
Coppia calcolaMossa(int x, int y, int indice);
//2)Verifico se la mossa per (x,y) è effettuata all'interno della scacchiera
int MossaValida(Coppia mossa);
//3)In quella casella sono già passato, devo scartarla 
int GiaVisitata(Coppia mossa, Percorso ListaMosse[], int n);


#endif
