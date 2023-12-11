#include <iostream>
#include <time.h>
#include "funcionesMedioNivel.hpp"

int main(){
    srand(time(NULL));
    int opt = -1;

    while (opt != 0){
        std::cout << "Indique que método quiere utilizar" << std::endl;
        std::cout << "\t[1] Todas las soluciones de las N-Reinas (Backtracking)" << std::endl;
        std::cout << "\t[2] Una solución de las N-Reinas (Backtracking)" << std::endl;
        std::cout << "\t[3] Una solución de las N-Reinas (Las Vegas)" << std::endl;
        std::cout << "\t[4] Solución de menor coste para N-Reinas (Backtracking con poda)" << std::endl;
        std::cout << "[5] Verificación del producto de matrices (Montecarlo)" << std::endl;
        std::cout << "[6] Verificar probabilidad (Montecarlo)" << std::endl;
        std::cout << "[7] Salir" << std::endl;
        std::cin >> opt;

        if (opt == 1){
            nReinasTodasBT();
        } else if (opt == 2){
            nReinasUnaBT();
        } else if (opt == 3){
            nReinasVegas();
        }
    }

    return 0;
}