#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP


#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>
#include "funcionality.hpp"
#include "ClaseTiempo.cpp"


using namespace std;

void fibonacci();
int fibonacci(int &n);
void ajusteExponencial(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a);
void calcularTiemposEstimadosExponencial(const vector <double> &n, const vector <double> &tiempoReales,const vector <double> &a, vector <double> &  tiemposEstimados);
double calcularTiempoEstimadoExponencial(const double &n, const vector <double> &a); 
void tiemposFibonacci(int &nMin, int &nMax,int &incremento,vector <double> &tiemposReales, vector <double> &numeroElementos);



#endif