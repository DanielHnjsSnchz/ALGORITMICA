#include <iostream>
#include "funcionesMedioNivel.hpp"

using namespace std;

int main() {

    int opt=-1;

    while(opt!=0){

        cout<<"\n<--------------------------------------------------------------------------------->\n";

        // Menú para elegir entre el problema del cambio y el problema de la mochila
        int opcion;
        cout << "\nSeleccione el problema a resolver:" << endl;
        cout << "   1. Problema del cambio" << endl;
        cout << "   2. Problema de la mochila" << endl;
        cout << "   0. SALIR" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            problemaCambio();
            
            break;

        case 2:
            problemaMochila();
            
            break;

        case 0:
            opt=0;
            
            break;

        default:
            cout << "\nOpción no válida.\n" << endl;
            
            break;
        }
    }
    return 0;
}