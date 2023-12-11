#include <iostream>
#include <vector>
#include <cstdlib>
#include "ClaseTiempo.cpp"
#include "contadorIntentos.h"

using namespace std;

int intentos_globales = 0; // Variable global para contar intentos

bool esSeguro(const vector<int>& solucion, int fila, int columna) {
    for (int i = 0; i < fila; ++i) {
        if (solucion[i] == columna || abs(solucion[i] - columna) == abs(i - fila)) {
            return false;
        }
    }
    return true;
}

void escribirSoluciones(const vector<vector<int>> &soluciones) {
    cout << "Todas las soluciones:\n";
    for (const auto& solucion : soluciones) {
        for (int col : solucion) {
            cout << col << " ";
        }
        cout << "\n";
    }
}

void escribirSolucion(const vector<int> &solucion) {
    cout << "La primera solución:\n";
    for (int col : solucion) {
        cout << col << " ";
    }
    cout << "\n";
}


void nReinasBacktracking(int n, vector<vector<int>>& soluciones) {
    int fila = soluciones.size(); // Utilizamos el tamaño actual del vector soluciones como fila
    if (fila == n) {
        vector<int> solucion(soluciones.size());
        for (int i = 0; i < soluciones.size(); ++i) {
            if (soluciones[i].size() > fila) {
                solucion[i] = soluciones[i][fila];
            }
        }
        soluciones.push_back(solucion);
        ++intentos_globales;
        return;
    }

    for (int columna = 0; columna < n; ++columna) {
        if (esSeguro(soluciones[fila], fila, columna)) {
            soluciones[fila].push_back(columna);
            nReinasBacktracking(n, soluciones);
            soluciones[fila].pop_back();
        }
    }
}

void nReinasBacktracking(int n, vector<int>& solucion) {
    if (n == solucion.size()) {
        ++intentos_globales;
        return;
    }

    for (int columna = 0; columna < n; ++columna) {
        if (esSeguro(solucion, n, columna)) {
            solucion[n] = columna;
            nReinasBacktracking(n + 1, solucion);
            if (intentos_globales > 0) {
                return;
            }
        }
    }
}
/*void resolverNReinasBacktracking(int n, vector<vector<int>>& soluciones) {
    if (n == soluciones.size()) {
        soluciones.push_back(solucion);
        return;
    }

    for (int columna = 0; columna < n; ++columna) {
        if (esSeguro(solucion, n, columna)) {
            solucion[n] = columna;
            resolverNReinasBacktracking(n + 1, soluciones);
        }
    }
}*/

void nReinasBacktracking(int n, vector<vector<int>>& soluciones) {
    vector<int> solucion(n, -1);
    Clock reloj;
    reloj.start();

    resolverNReinasBacktracking(0, solucion, soluciones);

    reloj.stop();

    // Llama a la función para escribir todas las soluciones
    escribirSoluciones(soluciones);

    // Mostrar el número de intentos y el tiempo transcurrido
    cout << "Número total de soluciones encontradas: " << soluciones.size() << "\n";
    cout << "Tiempo transcurrido: " << reloj.elapsed() << " microsegundos\n";
}

void escribirSolucion(const vector<int> &solucion) {
    cout << "La primera solución:\n";
    for (int col : solucion) {
        cout << col << " ";
    }
    cout << "\n";
}

void nReinasBacktracking(int n, vector<int>& solucion) {
    if (n == solucion.size()) {
        ++intentos_globales;
        return;
    }

    for (int columna = 0; columna < n; ++columna) {
        if (esSeguro(solucion, n, columna)) {
            solucion[n] = columna;
            nReinasBacktracking(n + 1, solucion);
            if (intentos_globales > 0) {
                return;
            }
        }
    }
}


/*
void nReinasBacktracking(int n, vector<int>& solucion) {
    Clock reloj;
    reloj.start();

    resolverNReinasBacktrackingUnica(0, solucion);

    reloj.stop();

    // Llama a la función para escribir la primera solución
    escribirSolucion(solucion);

    // Mostrar el número de intentos y el tiempo transcurrido
    cout << "Número de intentos: " << intentos_globales << "\n";
    cout << "Tiempo transcurrido: " << reloj.elapsed() << " microsegundos\n";
}
*/

