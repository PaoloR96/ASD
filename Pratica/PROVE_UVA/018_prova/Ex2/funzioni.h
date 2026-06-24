#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
#define LEN 100
/*metodi*/
void InserimentoDati(char ListaParole[][LEN], int dim);
int  ComparaLettere(const void* a,const void* b);
void OrdinaParole(char ListaParole[][LEN], int dim);
void ElaboraParole(char ListaParole[][LEN], int numParole);
#endif
