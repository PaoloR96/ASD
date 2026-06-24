#ifndef FUNZIONI_H
#define FUNZIONI_H
#define VERTICI 512
#define MAX 512
typedef struct {
        int x;
        int y;
}Punto;

typedef struct {
        int numeroVer;
        Punto punto[VERTICI];
}Involucro;


/*Metodi*/
void RiempiCasodiTest(Involucro *t);
void ElaboraCasodiTest(Involucro t);
int Compara(const void *a,const void *b);
Involucro merge(Involucro L, Involucro R);
int prodotto_vettoriale(Punto a, Punto b, Punto c);
Involucro CalcolaConvexHull(Punto pts[], int n);



#endif
