#ifndef CAMBIO_H
#define CAMBIO_H

#include <vector>
#include "moneda.hpp"

using namespace std;

void cambio(int cantidad, vector<Moneda> &sistemaMonetario, vector<vector<int>> &matrizEstados);

#endif