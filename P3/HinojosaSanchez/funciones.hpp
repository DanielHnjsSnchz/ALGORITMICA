#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <fstream>
#include "material.hpp"
#include "materialUsado.hpp"
#include "moneda.hpp"

using namespace std;

void cargarSistemaMonetario(vector<Moneda> &sistemaMonetario, const char *nombreFichero);
void cargarMateriales(vector<Material> &materiales, const char *nombreFichero);

void escribirSolucion(vector<int> &solucion, vector<Moneda> &sistemaMonetario);
void escribirSolucion(vector<MaterialUsado> &solucion);

#endif