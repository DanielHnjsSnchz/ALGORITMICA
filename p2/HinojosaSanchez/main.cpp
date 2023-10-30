#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <ctime>
#include "math.h"
#include "funcionality.hpp"
#include "quicksort.hpp"
#include "misc.hpp"

int main(int argc, char* argv[]){

    srand(time(NULL));
    
    if (argc < 6) {
        // No se proporcionaron suficientes argumentos
        std::cout << "Uso: " << argv[0] << " <nMin> <nMax> <incremento> <repeticiones> <nMediana> <nElementoMinimo>" << std::endl;
        return 1;
    }

    int nMin = std::stoi(argv[1]);
    int nMax = std::stoi(argv[2]);
    int incremento = std::stoi(argv[3]);
    int repeticiones = std::stoi(argv[4]);
    int nMediana = std::stoi(argv[5]);
    int nElementoMinimo = std::stoi(argv[6]);

    /*
    nMin = 1000000;
    nMax = 5000000;
    incremento = 100000;
    repeticiones = 3;
    */

    while(nMediana < 0 || nMediana % 2 == 0){
        cout << "El número de elementos del vector que se han de tomar aleatoriamente para obtener la mediana ha de ser impar" << endl;
        cout << "Introducelo de nuevo: ";
        cin >> nMediana;
    }
    while(nElementoMinimo < 0){
        cout << "El número de elementos del vector no puede ser 0 ni negativo." << endl;
        cout << "Introducelo de nuevo: ";
        cin >> nElementoMinimo;
    }

    cout << "A continuación se llamará a la función comparacionVariantesQuicksort() \n" << endl;
    comparacionVariantesQuicksort(nMin,nMax,incremento,repeticiones,nMediana,nElementoMinimo);

    return 0;

}