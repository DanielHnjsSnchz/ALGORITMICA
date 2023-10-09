#ifndef MATRIZCUADRADA_HPP
#define MATRIZCUADRADA_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "ClaseTiempo.cpp"
#include "sistemaEcuaciones.hpp"

void matrizCuadrada();
void matrizCuadrada(vector <int> &v);
void rellenarMatriz(vector<int> &v);
void tiemposCuadrado(int nMin, int nMax, int incremento, int repeticiones, vector <double> &tiemposReales, vector <double> &numeroElementos);
void ficheroTiemposReales(vector <double> &tiemposReales, vector <double> &numeroElementos);
void ficheroDatosFinales(vector <double> &numeroElementos, vector <double> &tiemposReales, vector <double> &tiemposEstimados);

//
//AJUSTES Y ESTIMACIONES
//

void crearMatrizA(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizA);
void crearMatrizB(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizB);
void ajusteCubico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a);
long double sumatorio(const vector<double> &n,const vector <double> &t, int expN, int expT);
void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados);
double calcularTEstimadoPolinomico(const double &n, vector<double> &a);

double calcularCoeficienteDeDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados);
double calcularV(const vector <double> &v);
double calcularM(const vector <double> &v);

#endif