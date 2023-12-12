#ifndef FUNCIONESBACKTRACKING_H
#define FUNCIONESBACKTRACKING_H

#include <vector>

using namespace std;

void nReinasBacktracking(const int n, vector<vector<int>> &soluciones);
void nReinasBacktracking(const int n, vector<int> &soluciones);

void escribirSoluciones(const vector<vector<int>> &soluciones);
void escribirSolucion(const vector<int> &soluciones);

bool esSeguro(const vector<int>& solucion, int fila);


#endif