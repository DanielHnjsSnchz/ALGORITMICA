#include <iostream>
#include <vector>
#include "funcionesBacktracking.hpp"
#include "funcionesVegas.hpp"
#include "ClaseTiempo.cpp"
#include "contadorIntentos.h"

using namespace std;

void nReinasTodasBT(){

    int n;
    cout << "\nIntroduce el valor de n: ";
    cin >> n;
    cout<<"\n";

    vector<vector<int>> soluciones(n);

    soluciones.clear();

    nReinasBacktracking(n, soluciones);

    escribirSoluciones(soluciones);
    cout << "\nNúmero de soluciones: " << soluciones.size() << endl;

}


void nReinasUnaBT(){
    
    Clock reloj;

    int n;
    cout << "Introduce el valor de n: ";
    cin >> n;

    vector<int> solucion(n);

    reloj.start();

    nReinasBacktracking(n, solucion);

    reloj.stop();

    escribirSolucion(solucion);

    cout << "Tiempo transcurrido: " << reloj.elapsed() << " microsegundos\n";   

}

void nReinasVegas(){
    Clock reloj;

    int n;
    cout << "Introduce el valor de n: ";
    cin >> n;

    vector<int> solucion(n);

    reloj.start();

    nReinasLasVegas(n, solucion);

    reloj.stop();

    escribirSolucionVegas(solucion);

    cout << "Número de intentos: " << intentos_globales << "\n";
    cout << "Tiempo transcurrido: " << reloj.elapsed() << " microsegundos\n"; 

    intentos_globales=0;

}