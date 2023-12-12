#include <iostream>
#include <vector>

using namespace std;

bool esSeguro(const vector<int>& solucion, int fila) {
    for (int i = 0; i < fila; ++i) {
        if(solucion[i] == solucion[fila] || std::abs(solucion[i]-solucion[fila]) == std::abs(i-fila)){
            return false;
        }
    }
     if ((fila-2) >= 0){
        if (solucion[fila-2] == solucion[fila]-1 || solucion[fila-2] == solucion[fila]+1)
            return false;
    }
    if ((fila-1) >= 0){
        if (solucion[fila-1] == solucion[fila]-2 || solucion[fila-1] == solucion[fila]+2)
             return false;
    }
    return true;
}

void escribirSoluciones(const vector<vector<int>> &soluciones) {
    cout << "Todas las soluciones:\n";
    
     for (auto solucion: soluciones){
        std::cout << "[" ;
        for (auto valor: solucion)
            std::cout << " " << valor;
        std::cout << " ]" << std::endl;
    }
    cout << "\n";
}

void escribirSolucion(const vector<int> &solucion) {
    
    std::cout << std::endl;
    std::cout << "[";
    for(auto valor: solucion)
        std::cout << " " << valor;
    std::cout << " ]" << std::endl;
    cout << "\n";
}


void nReinasBacktracking(int n, vector<vector<int>>& soluciones) {
    
    vector<int> solucion (n);
    solucion[0] = -1;
    int fila = 0;

    while(fila > -1){
        solucion[fila] = solucion[fila] + 1;
        while(solucion[fila] < n && !esSeguro(solucion, fila))
            solucion[fila] = solucion[fila] + 1;
        if (solucion[fila] < n){
            if (fila == n - 1){
                soluciones.push_back(solucion);
            }else {
                fila = fila + 1;
                solucion[fila] = -1;
            }
        } else
            fila = fila - 1; 
    }
}

void nReinasBacktracking(int n, vector<int>& solucion) {
    
    solucion[0] = -1;
    int fila = 0;

    while(fila > -1){
        solucion[fila] = solucion[fila] + 1;
        while(solucion[fila] < n && !esSeguro(solucion, fila))
            solucion[fila] = solucion[fila] + 1;
        if (solucion[fila] < n){
            if (fila == n - 1)
                return; 
            else {
                fila = fila + 1;
                solucion[fila] = -1;
            }
        }
        else
            fila = fila - 1; 
    }

}