#include <iostream>
#include "ordenacionSeleccion.hpp"

using namespace std;

int main(){

    Clock time;
    int opt=-1;
    srand(time=0);

    while(opt!=0){
        cout<<"Introduzca el algoritmo a comprobar"<<endl;
        cout<<"1.- Algoritmo de ordenación por selección"<<endl;
        cout<<"2.- Algoritmo de producto de matrices"<<endl;
        cout<<"3.- Algoritmo de sucesión de Fibonacci"<<endl;
        cout<<"0.- Salir"<<endl;
        cin>>opt;
    }

    switch(opt){
        case 1:
            ordenacionSeleccion();
            
            
        case 2:

        case 3:

        case 0:
    }

}