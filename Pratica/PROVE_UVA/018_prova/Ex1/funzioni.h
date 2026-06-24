#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 10001 // N fino a 10000 
#define LIMIT 10000.0 // Soglia per INFINITY
typedef struct{
    /* data */
    double x;
    double y;
}Punto;
void RiempiCasoTest(Punto *Coordinate, int dim);
int ComparaCoordinateXY(const void *a,const void*b);
int ComparaCoordinataY(const void *a,const void*b);
double min2(double a, double b);
double dist(Punto p1, Punto p2);

double CalcolaStriscia(Punto *Coordinata, double delta, Punto puntoMedio, int N);
double CalcolaSequenza(Punto *Coordinata,int N);


#endif
