#include <iostream>
#include <vector>
#include "contadorIntentos.h"

int intentos_globales = 0; // Variable global para contar intentos

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
    
    std::vector<int> ok (n);
    for(int i = 0; i < n; i++){
        int index = -1;
        for(int j = 0; j < n; j++){   
            solucion[i] = j;
            if (Lugar(i,solucion)){
                index++;
                ok[index] = j;
            }
        }
        if (index == -1){
            intentos_globales++;
            return false;
        }
        if (index != 0)
            solucion[i] = ok[rand()%index];
        else
            solucion[i] = ok[0];
    }
    return (ok.size() != 0);
}

void escribirSolucionVegas(const std::vector<int>& solucion) {
    std::cout << "[";
        for(auto valor: solucion)
            std::cout << " " << valor;
        std::cout << " ]" << std::endl;
}