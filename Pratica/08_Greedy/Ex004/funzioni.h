#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_CAMERE 5
#define MAX_CAMPIONI 10  // max 2 * MAX_CAMERE

// Definizione della struttura per un set di dati
typedef struct {
    int camere;               // Numero di camere nella centrifuga
    int campioni;             // Numero di campioni
    int masse[MAX_CAMPIONI];  // Array delle masse dei campioni
} SetCentrifuga;
/*Metodi*/
void stampaSet(SetCentrifuga set);
int ComparaValori(const void *a,const void *b);//necessaria per il qsort
int SommaCampioni(SetCentrifuga set);
SetCentrifuga RiempiSequenza(SetCentrifuga set_iniziale,int split);
void CalcolaSbilanciamento(SetCentrifuga s,double target);

#endif
