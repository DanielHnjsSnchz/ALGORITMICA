#ifndef FUNCIONESMEDIONIVEL_H
#define FUNCIONESMEDIONIVEL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "funciones.hpp"
#include "material.hpp"
#include "materialUsado.hpp"
#include "moneda.hpp"

using namespace std;

void cambio(int cantidad, vector<Moneda> &sistemaMonetario, vector<int> &solucion);
void mochila(float volumenMochila, vector<Material> &materiales, vector<MaterialUsado> &solucion);


#endif