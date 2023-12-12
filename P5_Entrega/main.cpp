#include <iostream>
#include <time.h>
#include "funcionesMedioNivel.hpp"
#include "contadorIntentos.h"

int main(){
    srand(time(NULL));
    int opt = -1;
    int opcion;
    while (opt != 0){
        std::cout<<"\n<--------------------------------------------------------------------------------->\n";
        std::cout << "\nIndique que método quiere utilizar" << std::endl;
        std::cout << "\t[1] Todas las soluciones de las N-Reinas (Backtracking)" << std::endl;
        std::cout << "\t[2] Una solución de las N-Reinas (Backtracking)" << std::endl;
        std::cout << "\t[3] Una solución de las N-Reinas (Las Vegas)" << std::endl;
        std::cout << "\t[0] Salir" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            nReinasTodasBT();
            
            break;

        case 2:
            nReinasUnaBT();
            
            break;

        case 3:
            nReinasVegas();
            
            break;

        case 0:
            opt=0;
            
            break;

        default:
            std::cout << "\nOpción no válida.\n" << std::endl;
            
            break;
        }
    }

    return 0;
}