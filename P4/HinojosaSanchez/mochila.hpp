#ifndef MOCHILA_H
#define MOCHILA_H

#include "material.hpp"
#include "materialUsado.hpp"
#include <vector>

using namespace std;

void mochila(float volumenMochila, vector<Material> &materiales, vector<vector<double>> &matrizEstados);

#endif