#include <stdio.h>
#include <math.h>
#include "funzioni.h"

// Funzione ricorsiva per calcolare la larghezza della strada
double CalcolaValore(double x, double y, double z, double wLow, double wHigh) {
    
    // Condizione di uscita della ricorsione
    if(wHigh - wLow < tolleranza)
        return (wLow + wHigh) / 2.0;

    // Calcolo del punto medio
    double mid = (wLow + wHigh) / 2.0;

    // Calcolo delle altezze delle due scale alla posizione mid
    double h1 = sqrt(fmax(0.0, x*x - mid*mid));
    double h2 = sqrt(fmax(0.0, y*y - mid*mid));

    // Altezza del punto d'incrocio corrispondente a mid
    double c_calc = (h1 * h2) / (h1 + h2);

    // Ricerca binaria
    if(c_calc > z)
        return CalcolaValore(x, y, z, mid, wHigh); // aumentiamo w
    else
        return CalcolaValore(x, y, z, wLow, mid);   // diminuiamo w
}

// Funzione per processare tutte le sequenze e stampare i risultati
void TrovaSequenze(double Valori[SIZE][3], int index){
    for (int i = 0; i < index; i++){
        double w = CalcolaValore(Valori[i][0], Valori[i][1], Valori[i][2], 
                                 0.0, fmin(Valori[i][0], Valori[i][1]));
        printf("%.3f\n", w);
    }
}
