#include <iostream>
#include <vector>
#include "funcionesBacktracking.hpp"

using namespace std;

void nReinasTodasBT(){
    int n;
    cout << "Introduce el valor de n: ";
    cin >> n;

    // Parte Obligatoria - Punto 1
    vector<vector<int>> soluciones;
    nReinasBacktracking(n, soluciones);
    cout << "Todas las soluciones del problema para n=" << n << ":\n";
    escribirSoluciones(soluciones);
}


void nReinasUnaBT(){
    int n;
    cout << "Introduce el valor de n: ";
    cin >> n;
    
    // Parte Obligatoria - Punto 2
    vector<int> solucion(n, -1);
    nReinasBacktracking(n, solucion);
    cout << "La primera solución encontrada para n=" << n << ":\n";
    escribirSolucion(solucion);
}