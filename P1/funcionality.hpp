#ifndef FUNCIONALITY_HPP
#define FUNCIONALITY_HPP


#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>

using namespace std;

void ajusteCuadratico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a);
long double sumatorio(vector<double> &n, vector <double> &t, int expN, int expT);
void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados);
long double calcularCoeficienteDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados);
long double calcularTiempoEstimadoPolinomico(const double &n,vector<double> &a);
//long double calcularVarianza();



#endif