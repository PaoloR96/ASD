#ifndef FUNZIONI_H
#define FUNZIONI_H

#define RIGHE 8
#define COLONNE 8

void stampaSoluzione(int A[], int *solNr);
void Solve(int rigaFissa, int colFissa);
void PosRegina(int A[], int colonna, int rigaFissa, int colFissa, int *solNr);
int attacco(int r1, int c1, int r2, int c2);



#endif
