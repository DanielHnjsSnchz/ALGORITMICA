#ifndef ORDENACION_HPP
#define ORDENACION_HPP

#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "funcionality.hpp"
#include "ClaseTiempo.cpp"
#include "sistemaEcuaciones.hpp"


//#include "ordenacionSeleccion.cpp"

using namespace std;

void ordenacionSeleccion();
void ordenacionSeleccion(vector <int> &v);
void rellenarVector(vector<int> &v);
bool estaOrdenado(const vector<int> &v);
void tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int repeticiones, vector <double> &tiemposReales, vector <double> &numeroElementos);
void ficheroTiemposReales(vector <double> &tiemposReales, vector <double> &numeroElementos);
void ficheroDatosFinales(vector <double> &numeroElementos, vector <double> &tiemposReales, vector <double> &tiemposEstimados);

//
//AJUSTES Y ESTIMACIONES
//

void crearMatrizA(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizA);
void crearMatrizB(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizB);
void ajusteCuadratico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a);
long double sumatorio(const vector<double> &n,const vector <double> &t, int expN, int expT);
void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados);
long double calcularCoeficienteDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados);
long double calcularTiempoEstimadoPolinomico(const double &n,vector<double> &a);
long double calcularVarianza(const vector <double> &x);
long double calcularMedia(const vector <double> &v);


#endif