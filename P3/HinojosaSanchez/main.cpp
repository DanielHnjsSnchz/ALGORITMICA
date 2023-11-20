#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "funcionesMedioNivel.hpp"

using namespace std;

int main() {
    // Definir vectores para el sistema monetario y la solución del problema del cambio
    vector<Moneda> sistemaMonetario;
    vector<int> solucionCambio;

    // Cargar el sistema monetario desde el archivo
    cargarSistemaMonetario(sistemaMonetario, "sistemamonetario.txt");

    // Definir vectores para los materiales y la solución del problema de la mochila
    vector<Material> materiales;
    vector<MaterialUsado> solucionMochila;

    // Cargar los materiales desde el archivo
    cargarMateriales(materiales, "materialesmochila.txt");

    // Menú para elegir entre el problema del cambio y el problema de la mochila
    int opcion;
    cout << "Seleccione el problema a resolver:" << endl;
    cout << "1. Problema del cambio" << endl;
    cout << "2. Problema de la mochila" << endl;
    cout << "Ingrese 1 o 2: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        // Pedir al usuario la cantidad para el problema del cambio
        int cantidadCambio;
        cout << "Introduce la cantidad en centimos para el problema del cambio: ";
        cin >> cantidadCambio;

        // Obtener el cambio con el menor número de monedas
        cambio(cantidadCambio, sistemaMonetario, solucionCambio);

        // Mostrar la solución del problema del cambio
        escribirSolucion(solucionCambio, sistemaMonetario);
        break;

    case 2:
        // Pedir al usuario el volumen de la mochila para el problema de la mochila
        float volumenMochila;
        cout << "Introduce el volumen de la mochila para el problema de la mochila: ";
        cin >> volumenMochila;

        // Resolver el problema de la mochila
        mochila(volumenMochila, materiales, solucionMochila);

        // Mostrar la solución del problema de la mochila
        escribirSolucion(solucionMochila);
        break;

    default:
        cout << "Opción no válida." << endl;
        break;
    }

    return 0;
}