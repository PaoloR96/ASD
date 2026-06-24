#ifndef FUNZIONI_H
#define FUNZIONI_H
/*Struttura dati*/
typedef struct{
        int x,y;
}Punto;
/*Metodi*/
void  TrovaSegmentoM(Punto p[], int n, int M);
int comparaPunti(const void *a, const void *b);

#endif
