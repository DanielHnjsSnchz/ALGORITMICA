#include <iostream>
#include <vector>
#include <cstdlib>
#include "ClaseTiempo.cpp" 
#include "contadorIntentos.h"

bool Lugar(int k, const std::vector<int>& x) {
    int n = x.size();
    for (int i = 0; i < k; ++i) {
        if (x[i] == x[k] || std::abs(x[i] - x[k]) == std::abs(i - k)) {
            return false;
        }
    }
    return true;
}

bool nReinasLasVegas(int n, std::vector<int>& solucion) {
    Clock tiempo;
    tiempo.start();

    solucion.resize(n, 0);  // Inicializar solución a 0

    for (int k = 0; k < n; ++k) {
        int contador = -1;
        std::vector<int> ok(n, 0);

        for (int j = 0; j < n; ++j) {
            solucion[k] = j;
            if (Lugar(k, solucion)) {
                contador++;
                ok[contador] = j;
            }
        }

        if (contador == -1) {
            tiempo.stop();
            return false;  // No hay solución
        }

        // Selecciona aleatoriamente una posición
        int columna = ok[rand() % (contador + 1)];
        solucion[k] = columna;
    }

    tiempo.stop();
    return true;  // Hay solución
}

void escribirSolucion(const std::vector<int>& solucion) {
    std::cout << "Solución encontrada: ";
    for (int i : solucion) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}