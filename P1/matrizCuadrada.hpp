#ifndef MATRIZCUADRADA_HPP
#define MATRIZCUADRADA_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "ClaseTiempo.cpp"
#include "sistemaEcuaciones.hpp"
#include "misc.hpp"

void matrizCuadrada();
void matrizCuadrada(vector <vector<double>> &matrizA,vector <vector<double>> &matrizR);
void rellenarMatriz(vector <vector<double>> &m);
void tiemposCuadrado(int nMin, int nMax, int incremento, vector <double> &tiemposReales, vector <double> &numeroElementos);
void ficheroTiemposRealesMatriz(vector <double> &tiemposReales, vector <double> &numeroElementos);
void ficheroDatosFinalesMatriz(vector <double> &numeroElementos, vector <double> &tiemposReales, vector <double> &tiemposEstimados);

//
//AJUSTES Y ESTIMACIONES
//

void crearMatrizA2(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizA);
void crearMatrizB2(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizB);
void ajusteCubico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a);
double sum2(const vector<double> &n,const vector <double> &t, int expN, int expT);
void calcularTiemposEstimadosPolinomico2(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados);
double calcularTEstimadoPolinomico2(const double &n, vector<double> &a);

double calcularCoeficienteDeDeterminacion2(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados);
double calcularV2(const vector <double> &v);
double calcularM2(const vector <double> &v);

#endif