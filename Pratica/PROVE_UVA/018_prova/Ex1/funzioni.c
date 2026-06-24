#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funzioni.h"  // Include il file header

void RiempiCasoTest(Punto *Coordinata, int dim){
    for (int i = 0; i < dim; i++){
        scanf("%lf %lf", &Coordinata[i].x, &Coordinata[i].y);
    }
}

/*Metodi Ausiliari*/
int ComparaCoordinateXY(const void *a, const void *b) {
    Punto *p1 = (Punto*)a;
    Punto *p2 = (Punto*)b;

    // Confronto X
    if (p1->x < p2->x) return -1;
    if (p1->x > p2->x) return 1;
    // Se X è uguale, confronto Y
    if (p1->y < p2->y) return -1;
    if (p1->y > p2->y) return 1;
    return 0;
}

int ComparaCoordinataY(const void *a, const void *b) {
    Punto *p1 = (Punto*)a;
    Punto *p2 = (Punto*)b;
    if (p1->y < p2->y) return -1;
    if (p1->y > p2->y) return 1;
    return 0;
}

// Funzione ausiliaria per la distanza euclidea
double dist(Punto p1, Punto p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double min2(double a, double b){
    return (a<b)? a:b;
}
/*Metodi per calcolare il risultato finale*/
double CalcolaSequenza(Punto *Coordinata,int N){
        //Caso Base:Nel caso abbiamo al massimo 3 numeri evito calcolo la distanza minima direttamente
        if (N<=3){
            double min_dist = INT_MAX; // Valore molto alto iniziale
            for (int i = 0; i < N; i++){
                for (int j = i+1; j <N ; j++){
                    double d = dist(Coordinata[i], Coordinata[j]);
                    if(d<min_dist)min_dist=d;
                }
            }
            return min_dist;
        }
        //Ricorsione:Devo applicare la ricorsione in quanto ho N>3
        //1.Prendo il punto medio
        int q=N/2;
        Punto puntoMedio=Coordinata[q];
        //Divido i punti del mio insieme in punti di sinistra e punti di destra
        double dxMin_Sx=CalcolaSequenza(Coordinata,q); 
        double dxMin_Dx=CalcolaSequenza(Coordinata+q,N-q);
        double delta=min2(dxMin_Sx,dxMin_Dx);
        double dx_Striscia=CalcolaStriscia(Coordinata,delta,puntoMedio,N);
        return dx_Striscia;        
}


double CalcolaStriscia(Punto *Coordinata, double delta, Punto puntoMedio, int N){

    Punto strip[MAX];
    int dimStrip = 0;
    double min_strip=delta;
    //1.Devo contenere tutti i punti la cui coordinata X dista meno delta
    //definisco i punti vicini alla mediana
    for (int i = 0; i < N; i++) {
        //distanza su asse X da "start"
        if (fabs(Coordinata[i].x - puntoMedio.x) < delta) { //lo strip viene creato a partire dalla coordianta x
            strip[dimStrip] = Coordinata[i];
            dimStrip++;
        }
    }
    //2.Devo ordinare i punti dello strip in base alla coordianta Y
    qsort(strip,dimStrip,sizeof(Punto),ComparaCoordinataY);
    //3.Itero sui ogni punto di strip,confrontalo solo con i successivi, per vedere se se trovi una distanza inferiore a delta
    //Ne bastano 7 o 8 per trovare una distanza inferiore a delta
    for (int i = 0; i < dimStrip; i++){
        for (int j = i+1; j < dimStrip && (strip[j].y - strip[i].y) < min_strip; j++){
            double d=dist(strip[i],strip[j]); 
            if (d< min_strip) min_strip=d;
        }
    }
    return min_strip;
}



