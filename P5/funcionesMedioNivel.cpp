#include <iostream>
#include <vector>
#include "funcionesBacktracking.hpp"
#include "ClaseTiempo.cpp"
#include "contadorIntentos.h"

using namespace std;

void nReinasTodasBT(){

    Clock reloj;

    int n;
    cout << "Introduce el valor de n: ";
    cin >> n;

    //vector<int> solucion(n, -1);
    vector<vector<int>> soluciones;

    reloj.start();

    soluciones.clear(); // Limpiamos el vector de soluciones antes de empezar
    vector<int> primera_solucion; // Creamos una primera solución vacía
    vector<vector<int>> soluciones_temp; // Usamos un vector temporal para almacenar las soluciones

    nReinasBacktracking(n, soluciones_temp);

    // Copiamos la primera solución al vector de soluciones
    for (int i = 0; i < soluciones_temp.size(); ++i) {
        primera_solucion.push_back(soluciones_temp[i][0]);
    }
    soluciones.push_back(primera_solucion);

    // Copiamos las soluciones temporales al vector de soluciones
    for (int i = 0; i < soluciones_temp.size(); ++i) {
        soluciones.push_back(soluciones_temp[i]);
    }

    reloj.stop();

    // Llama a la función para escribir todas las soluciones
    escribirSoluciones(soluciones);

    // Mostrar el número de intentos y el tiempo transcurrido
    cout << "Número de intentos: " << intentos_globales << "\n";
    cout << "Tiempo transcurrido: " << reloj.elapsed() << " microsegundos\n";

    /*int n;
    cout << "Introduce el valor de n: ";
    cin >> n;

    // Parte Obligatoria - Punto 1
    vector<vector<int>> soluciones;
    nReinasBacktracking(n, soluciones);
    cout << "Todas las soluciones del problema para n=" << n << ":\n";
    escribirSoluciones(soluciones);*/
}


void nReinasUnaBT(){
    
    Clock reloj;

    int n;
    cout << "Introduce el valor de n: ";
    cin >> n;

    //vector<int> solucion(n, -1);
    vector<int> solucion;

    reloj.start();

    //nReinasBacktracking(0, solucion);
    nReinasBacktracking(n, solucion);

    reloj.stop();

    // Llama a la función para escribir la primera solución
    escribirSolucion(solucion);

    // Mostrar el número de intentos y el tiempo transcurrido
    cout << "Número de intentos: " << intentos_globales << "\n";
    cout << "Tiempo transcurrido: " << reloj.elapsed() << " microsegundos\n";

    /*int n;
    cout << "Introduce el valor de n: ";
    cin >> n;
    
    // Parte Obligatoria - Punto 2
    vector<int> solucion(n, -1);
    nReinasBacktracking(n, solucion);
    cout << "La primera solución encontrada para n=" << n << ":\n";
    escribirSolucion(solucion);*/
}