#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP


#include <fstream>
#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>
#include "funcionality.hpp"
#include "ClaseTiempo.hpp"
#include "misc.hpp"


using namespace std;

void fibonacci();
int fibonacci(int &n);
void ajusteExponencial(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a);
void calcularTiemposEstimadosExponencial(const vector <double> &n, const vector <double> &tiempoReales,const vector <double> &a, vector <double> &  tiemposEstimados);
double calcularTiempoEstimadoExponencial(const double &n, const vector <double> &a); 
void tiemposFibonacci(int &nMin, int &nMax,int &incremento,vector <double> &tiemposReales, vector <double> &numeroElementos);
void ficheroTiemposRealesFibonacci(vector <double> &tiemposReales, vector <double> &numeroElementos);
void ficheroDatosFinalesFibonacci(vector <double> &numeroElementos, vector <double> &tiemposReales, vector <double> &tiemposEstimados);


//
//AJUSTES Y ESTIMACIONES
//

void crearMatrizAFibonacci(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizA);
void crearMatrizBFibonacci(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizB);
void ajusteExponencial(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a);
double sumFibonacci(const vector<double> &n,const vector <double> &t, int expN, int expT);
void calcularTiemposEstimadosPolinomicoFibonacci(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados);
double calcularTEstimadoPolinomicoFibonacci(const double &n, vector<double> &a);
//long double calcularTiempoEstimadoPolinomico(const double &n,const vector<double> &a);

double calcularCoeficienteDeDeterminacionFibonacci(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados);
double calcularVFibonacci(const vector <double> &v);
double calcularMFibonacci(const vector <double> &v);


#endif