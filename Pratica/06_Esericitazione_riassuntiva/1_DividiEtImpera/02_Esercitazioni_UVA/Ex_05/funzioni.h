#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX_TESTS 1000

void CalcolaFunzione(double test_cases[MAX_TESTS][6], int dim);
double f(double x, double p, double q, double r, double s, double t, double u);
double Bisezione(double low, double high, double eps,
                 double p, double q, double r, double s, double t, double u);

#endif

