#include <iostream>
#include "ordenacionSeleccion.hpp"
#include "matrizCuadrada.hpp"
//#include "fibonacci.hpp"

#include "ClaseTiempo.cpp"

using namespace std;

int main(){

    bool salir = false;

    int opt=-1;
     std::srand(std::time(0));

    while(salir==false){
        cout<<"Introduzca el algoritmo a comprobar"<<endl;
        cout<<"1.- Algoritmo de ordenación por selección"<<endl;
        cout<<"2.- Algoritmo de producto de matrices"<<endl;
        cout<<"3.- Algoritmo de sucesión de Fibonacci"<<endl;
        cout<<"0.- Salir"<<endl;
        cin>>opt;
    

    switch(opt){
        case 1:
        
            ordenacionSeleccion();
            break;
        case 2:
            matrizCuadrada();
            break;
        case 3:
        //fibonacci();
            break;
        case 0:
            salir=true;
            break;
        default:
            break;
    };
    }
}