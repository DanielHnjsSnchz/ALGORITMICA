#include <vector>
#include <iostream>

#include "ClaseTiempo.cpp"

using namespace std;

bool esSeguro(vector<int>& solucion, int fila, int columna) {
    // Verifica si es seguro colocar una reina en esta posición
    for (int i = 0; i < fila; ++i) {
        if (solucion[i] == columna || abs(solucion[i] - columna) == abs(i - fila)) {
            return false;
        }
    }
    return true;
}

void resolverNReinasBacktracking(int fila, int n, vector<int>& solucion, vector<vector<int>>& soluciones) {
    if (fila == n) {
        // Se ha encontrado una solución completa
        soluciones.push_back(solucion);
        return;
    }

    for (int columna = 0; columna < n; ++columna) {
        if (esSeguro(solucion, fila, columna)) {
            solucion[fila] = columna;
            resolverNReinasBacktracking(fila + 1, n, solucion, soluciones);
        }
    }
}

void nReinasBacktracking(int n, vector<vector<int>>& soluciones) {
    vector<int> solucion(n, -1);
    resolverNReinasBacktracking(0, n, solucion, soluciones);
}

void escribirSoluciones(vector<vector<int>>& soluciones) {
    for (const auto& solucion : soluciones) {
        for (int col : solucion) {
            cout << col << " ";
        }
        cout << "\n";
    }
}

void nReinasBacktracking(int n, vector<int>& solucion) {
    Clock reloj;
    reloj.start();

    resolverNReinasBacktracking(0, n, solucion, {});

    reloj.stop();
    cout << "Tiempo transcurrido: " << reloj.elapsed() << " microsegundos\n";
}

void escribirSolucion(vector<int>& solucion) {
    for (size_t i = 0; i < solucion.size(); ++i) {
        cout << "\t" << solucion[i] <<endl;
    }
    cout << "\n";
}