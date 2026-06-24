#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100005
typedef struct{
    /* data */
    int L;
    int R;
}Segmento;

/*Metodi*/
int InserisciSegmento(Segmento S[MAX]);
int ComparaValori(void const*a,void const*b);
void CalcolaSequenza(Segmento S[MAX],int M,int n);
void StampaSequenza();

#endif
