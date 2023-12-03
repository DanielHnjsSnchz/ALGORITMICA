#include "cambio.hpp"


using namespace std;

// Algoritmo del cambio
void cambio(int cantidad, vector<Moneda> &sistemaMonetario, vector<vector<int>> &matrizEstados) {
    int numMonedas = sistemaMonetario.size();

    for (int i = 0; i < numMonedas; ++i) {
        for (int j = 0; j <= cantidad; ++j) {
            if (j == 0) {
                matrizEstados[i][j] = 0;
            } else {
                if (i == 0) {
                    matrizEstados[i][j] = 1 + matrizEstados[i][j - sistemaMonetario[0].getValor()];
                } else {
                    if (j < sistemaMonetario[i].getValor()) {
                        matrizEstados[i][j] = matrizEstados[i - 1][j];
                    } else {
                        matrizEstados[i][j] = min(matrizEstados[i - 1][j], 1 + matrizEstados[i][j - sistemaMonetario[i].getValor()]);
                    }
                }
            }
        }
    }
}
