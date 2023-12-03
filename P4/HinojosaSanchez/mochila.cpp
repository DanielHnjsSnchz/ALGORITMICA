#include "mochila.hpp"

using namespace std;

// Algoritmo de la mochila
void mochila(float volumenMochila, vector<Material> &materiales, vector<vector<double>> &matrizEstados) {
    int numMateriales = materiales.size();

    for (int i = 0; i < numMateriales; ++i){
        for (int j = 0; j <= volumenMochila; ++j){
            if(j == 0){
                matrizEstados[i][j] = 0;
            }else{
                if (i == 0){
                    matrizEstados[i][j] = (j < materiales[0].getVolumen()) ? 0 : materiales[0].getPrecio() * materiales[0].getVolumen();
                }else{
                    if(j < materiales[i].getVolumen()){
                        matrizEstados[i][j] = matrizEstados[i - 1][j];
                    }else{
                        matrizEstados[i][j] = max(matrizEstados[i - 1][j], materiales[i].getPrecio() * materiales[i].getVolumen() + matrizEstados[i - 1][j - materiales[i].getVolumen()]);
                    }
                }
            }
        }
    }
}




/*void mochila(float volumenMochila, vector<Material> &materiales, vector<vector<double>> &matrizEstados) {
    int numMateriales = materiales.size();

    for (int i = 0; i < numMateriales; ++i){
        for (int j = 0; j <= volumenMochila; ++j){
            if(j == 0){
                matrizEstados[i][j] = 0;
            }else{
                if (i == 0){
                    matrizEstados[i][j] = (j < materiales[0].getVolumen()) ? 0 : materiales[0].getPrecio() * materiales[0].getVolumen();
                }else{
                    if(j < materiales[i].getVolumen()){
                        matrizEstados[i][j] = matrizEstados[i - 1][j];
                    }else{
                        matrizEstados[i][j] = max(matrizEstados[i - 1][j], materiales[i].getPrecio() * materiales[i].getVolumen() + matrizEstados[i - 1][j - materiales[i].getVolumen()]);
                    }
                }
            }
        }
    }
}*/






/*void mochila(float volumenMochila, vector<Material> &materiales, vector<vector<double>> &matrizEstados) {
    cout<<"AYUDA";
    // Inicializar la matriz de estados
    matrizEstados.resize(n, vector<double>(volumenMochila + 1, 0));
    
    // Rellenar la primera columna (cuando el volumen es 0)
    for (int i = 0; i < materiales.size(); ++i) {
        matrizEstados[i][0] = 0;
    }

    // Rellenar el resto de la matriz
    for (int i = 0; i < materiales.size(); ++i) {
        for (int j = 1; j <= volumenMochila; ++j) {
            if (j < materiales[i].getVolumen()) {
                matrizEstados[i][j] = matrizEstados[i - 1][j];
            } else {
                matrizEstados[i][j] = max(matrizEstados[i - 1][j],
                                          materiales[i].getPrecio() * materiales[i].getVolumen() +
                                          matrizEstados[i - 1][j - materiales[i].getVolumen()]);
            }
        }
    }
}*/


/*void mochila(float volumenMochila, vector<Material> &materiales, vector<vector<double>> &matrizEstados) {
    int n = materiales.size();

    // Rellenar la primera columna (cuando el volumen es 0)
    for (int i = 0; i < n; ++i) {
        matrizEstados[i][0] = 0;
    }

    // Rellenar el resto de la matriz
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= volumenMochila; ++j) {
            if (j < materiales[i].getVolumen()) {
                matrizEstados[i][j] = matrizEstados[i - 1][j];
            } else {
                matrizEstados[i][j] = max(matrizEstados[i - 1][j],
                                          materiales[i].getPrecio() * materiales[i].getVolumen() +
                                          matrizEstados[i - 1][j - materiales[i].getVolumen()]);
            }
        }
    }
}*/

/*
void mochila(float volumenMochila, vector<Material> &materiales, vector<vector<double>> &matrizEstados) {
    int numMateriales = materiales.size();

    for (int i = 0; i < numMateriales; ++i){
        for (int j = 0; j <= volumenMochila; ++j){
            if(j == 0){
                matrizEstados[i][j] = 0;
            }else{
                if (i == 0){
                    matrizEstados[i][j] = (j < materiales[0].getVolumen()) ? 0 : materiales[0].getPrecio() * materiales[0].getVolumen();
                }else{
                    if(j < materiales[i].getVolumen()){
                        matrizEstados[i][j] = matrizEstados[i - 1][j];
                    }else{
                        matrizEstados[i][j] = max(matrizEstados[i - 1][j], materiales[i].getPrecio() * materiales[i].getVolumen() + matrizEstados[i - 1][j - materiales[i].getVolumen()]);
                    }
                }
            }
        }
    }
}*/