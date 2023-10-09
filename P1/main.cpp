#include <iostream>
#include "ordenacionSeleccion.hpp"
#include "matrizCuadrada.hpp"

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
            
        case 2:
            matrizCuadrada();
        case 3:

        case 0:
            salir=true;
    };
    }
}