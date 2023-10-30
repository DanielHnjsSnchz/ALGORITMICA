#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <ctime>
#include "math.h"

using namespace std;

void quicksortHoare(int izq, int der, vector<int> &v);

void quicksortMediana(int izq, int der, int nMediana, int nElementosMinimo, vector<int> &v);

void ordenarSeleccion(vector <int> &v);

void tiemposOrdenacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo, vector <double> &tiemposRealesQS1, vector <double> &tiemposRealesQS2, vector <double> &numeroElementos);

#endif