#include "funcionesMedioNivel.hpp"

using namespace std;

// Algoritmo del cambio
void cambio(int cantidad, vector<Moneda> &sistemaMonetario, vector<int> &solucion){
    
    int sumaParcial = 0;
    size_t i = 0;

    while(sumaParcial != cantidad && i < sistemaMonetario.size()){

        int x = sistemaMonetario[i].getValor();

        if(sumaParcial + x <= cantidad){

            solucion[i]++;
            sumaParcial += x;

        }else{

            i++;

        }

    }

    if(sumaParcial != cantidad){

        cout << "No se encontró solución.\n";

    }
}



// Algoritmo de la mochila
void mochila(float volumenMochila, vector<Material> &materiales, vector<MaterialUsado> &solucion){
    
    int n = materiales.size();
    float resto = volumenMochila;
    bool materialDisponible = false;

    // Marcar todos los materiales como no usados
    for(int i = 0; i < n; ++i){
        solucion[i].setVolumenUsado(0);
    }

    // Seleccionar materiales mientras la mochila no esté llena
    do {
        float precioMaximo = 0;
        int materialMaximo = -1;
        

        // Seleccionar el material de mayor precio por unidad de volumen
        for(int i = 0; i < n; ++i){
            if(solucion[i].getVolumenUsado() == 0){
                materialDisponible = true;
                if(materiales[i].getPrecio() > precioMaximo){
                    precioMaximo = materiales[i].getPrecio();
                    materialMaximo = i;
                }
            }
        }

        // Comprobar si el material de mayor precio cabe en la mochila
        if(materialDisponible){
            if(resto >= materiales[materialMaximo].getVolumen()){
                //solucion[materialMaximo].setVolumenUsado(materiales[materialMaximo].getVolumen());
                solucion.push_back(MaterialUsado(materiales[materialMaximo], materiales[materialMaximo].getVolumen()));
                resto -= materiales[materialMaximo].getVolumen();
            }else{
                //solucion[materialMaximo].setVolumenUsado(resto);
                solucion.push_back(MaterialUsado(materiales[materialMaximo], resto));
                resto = 0;
            }
        }

    } while (resto > 0 && materialDisponible);
}
