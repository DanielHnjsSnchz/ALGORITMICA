#ifndef ORDENACION_HPP
#define ORDENACION_HPP

#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>
#include "funcionality.hpp"
#include "ClaseTiempo.cpp"
#include "ordenacionSeleccion.cpp"

using namespace std;

void ordenacionSeleccion();
void ordenacionSeleccion(vector <int> &v);
void rellenarVector(vector<int> &v);
bool estaOrdenado(const vector<int> &v);
void tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int repeticiones, vector <double> &tiemposReales, vector <double> &numeroElementos);


/*
void ordSelec{

pedir nmin,nmax,inc y rep

declarar vectores de numelementos, treales y testimados sin tamaño

calculartiemposOrdSeleccion

doble for

for(i=nMin;i<=nMax;i+incremento){
                for(unsigned int i=0;i<=repeticiones;i++){

                    
                }
            }

//declarar vecotr i elementos
                    //rellenar vector
                    //medir tiempos
                    //medir
                    //guardar tiempos en treales
                    //guardar n en  nelementos

}

*/

#endif