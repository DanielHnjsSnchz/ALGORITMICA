#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "material.hpp"
#include "materialUsado.hpp"
#include "moneda.hpp"

#include <vector>

using namespace std;

void cargarSistemaMonetario(vector<Moneda> &sistemaMonetario, const char *nombreFichero);
void cargarMateriales(vector<Material> &materiales, const char *nombreFichero);

void escribirSolucion(vector<int> &solucion, vector<Moneda> &sistemaMonetario);
void escribirSolucion(vector<MaterialUsado> &solucion);

void obtenerSolucion(vector<vector<int>> &matrizEstados, vector<int> &solucion, vector<Moneda> &sistemaMonetario);
void obtenerSolucion(vector<vector<double>> &matrizEstados, vector<MaterialUsado> &solucion, vector<Material> &materiales);

#endif