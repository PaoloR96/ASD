#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_N 20000
#define MAX_T 20

// Struct per rappresentare uno scenario di test
typedef struct {
    int n;                  // numero di articoli
    int prezzi[MAX_N];      // array dei prezzi
} Scenario;
/*Metodi*/
void stampaScenario(Scenario s);
int ComparaValori(const void *a,const void *b);
void CalcolaSConto(Scenario s);

#endif
