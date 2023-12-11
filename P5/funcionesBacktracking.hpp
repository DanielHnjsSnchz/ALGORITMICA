#ifndef FUNCIONESBT_H
#define FUNCIONESBT_H

#include <vector>
//#include "ClaseTiempo.cpp"

using namespace std;

void nReinasBacktracking(const int n, vector<vector<int>> &soluciones);
void nReinasBacktracking(const int n, vector<int> &soluciones);

void escribirSoluciones(const vector<vector<int>> &soluciones);
void escribirSolucion(const vector<int> &soluciones);

#endif