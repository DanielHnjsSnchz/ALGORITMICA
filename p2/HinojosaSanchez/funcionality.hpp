#ifndef FUNCIONALITY_HPP
#define FUNCIONALITY_HPP

#include "ClaseTiempo.cpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <ctime>
#include "math.h"

using namespace std;

void comparacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo);

void ficheroTiemposReales(vector <double> &numeroElementos, vector <double> &tiemposRealesQSHOARE, const vector <double> &tiemposRealesQSMEDIANA);

void rellenarVector(vector<int> &v);

#endif