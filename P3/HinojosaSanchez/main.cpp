#include <iostream>
#include <vector>
#include "funcionesMedioNivel.hpp"

using namespace std;

int main() {

    // Definir vector para el sistema monetario.
    vector<Moneda> sistemaMonetario;

    // Cargar el sistema monetario desde el archivo
    cargarSistemaMonetario(sistemaMonetario, "../sistemamonetario.txt");
    
    //Vector solucion
    vector<int> solucionCambio(sistemaMonetario.size(),0);

    // Definir vector para los materiales
    vector<Material> materiales;

    // Cargar los materiales desde el archivo
    cargarMateriales(materiales, "../materialesmochila.txt");

    //Vector solucion
    vector<MaterialUsado> solucionMochila;
    for(int i = 0; i<materiales.size(); i++){
        solucionMochila.push_back(MaterialUsado(materiales[i],0));
    }
    /*for(int i = 0; i<materiales.size(); i++){
        vector<MaterialUsado> solucionMochila(materiales.size(),MaterialUsado(materiales[i],0));
    }*/

    
    // Menú para elegir entre el problema del cambio y el problema de la mochila
    int opcion;
    cout << "\nSeleccione el problema a resolver:" << endl;
    cout << "   1. Problema del cambio" << endl;
    cout << "   2. Problema de la mochila" << endl;
    cout << "\nIngrese 1 o 2: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        // Pedir al usuario la cantidad para el problema del cambio
        int cantidadCambio;
        cout << "\nIntroduce la cantidad en centimos para el problema del cambio: ";
        cin >> cantidadCambio;

        // Obtener el cambio con el menor número de monedas
        cambio(cantidadCambio, sistemaMonetario, solucionCambio);

        // Mostrar la solución del problema del cambio
        escribirSolucion(solucionCambio, sistemaMonetario);
        break;

    case 2:
        // Pedir al usuario el volumen de la mochila para el problema de la mochila
        float volumenMochila;
        cout << "\nIntroduce el volumen de la mochila para el problema de la mochila: ";
        cin >> volumenMochila;

        // Resolver el problema de la mochila
        mochila(volumenMochila, materiales, solucionMochila);

        // Mostrar la solución del problema de la mochila
        escribirSolucion(solucionMochila);
        break;

    default:
        cout << "\nOpción no válida.\n" << endl;
        break;
    }

    return 0;
}