#include <iostream>
#include <vector>
#include <cstdlib>
#include "ClaseTiempo.cpp"

using namespace std;

bool esSeguro(vector<int>& solucion, int fila, int columna) {
    for (int i = 0; i < fila; ++i) {
        if (solucion[i] == columna || abs(solucion[i] - columna) == abs(i - fila)) {
            return false;
        }
    }
    return true;
}

void resolverNReinasBacktracking(int fila, int n, vector<int>& solucion, vector<vector<int>>& soluciones, int& intentos) {
    if (fila == n) {
        soluciones.push_back(solucion);
        ++intentos;
        return;
    }

    for (int columna = 0; columna < n; ++columna) {
        if (esSeguro(solucion, fila, columna)) {
            solucion[fila] = columna;
            resolverNReinasBacktracking(fila + 1, n, solucion, soluciones, intentos);
        }
    }
}

void nReinasBacktracking(int n) {
    vector<int> solucion(n, -1);
    vector<vector<int>> soluciones;
    Clock reloj;
    reloj.start();

    int intentos = 0;
    resolverNReinasBacktracking(0, n, solucion, soluciones, intentos);

    reloj.stop();

    // Mostrar todas las soluciones encontradas
    cout << "Todas las soluciones del problema para n=" << n << ":\n";
    for (const auto& solucion : soluciones) {
        for (int col : solucion) {
            cout << col << " ";
        }
        cout << "\n";
    }

    // Mostrar el número de intentos y el tiempo transcurrido
    cout << "Número total de soluciones encontradas: " << soluciones.size() << "\n";
    cout << "Número de intentos: " << intentos << "\n";
    cout << "Tiempo transcurrido: " << reloj.elapsed() << " microsegundos\n";
}

void resolverNReinasBacktrackingUnica(int fila, int n, vector<int>& solucion, int& intentos) {
    if (fila == n) {
        ++intentos;
        return;
    }

    for (int columna = 0; columna < n; ++columna) {
        if (esSeguro(solucion, fila, columna)) {
            solucion[fila] = columna;
            resolverNReinasBacktrackingUnica(fila + 1, n, solucion, intentos);
            if (intentos > 0) {
                return;
            }
        }
    }
}

void nReinasBacktrackingUnica(int n) {
    vector<int> solucion(n, -1);
    Clock reloj;
    reloj.start();

    int intentos = 0;
    resolverNReinasBacktrackingUnica(0, n, solucion, intentos);

    reloj.stop();

    // Mostrar la primera solución encontrada
    cout << "La primera solución encontrada para n=" << n << ":\n";
    for (int col : solucion) {
        cout << col << " ";
    }
    cout << "\n";

    // Mostrar el número de intentos y el tiempo transcurrido
    cout << "Número de intentos: " << intentos << "\n";
    cout << "Tiempo transcurrido: " << reloj.elapsed() << " microsegundos\n";
}

int main() {
    int n;
    cout << "Introduce el valor de n: ";
    cin >> n;

    nReinasBacktracking(n);
    nReinasBacktrackingUnica(n);

    return 0;
}
