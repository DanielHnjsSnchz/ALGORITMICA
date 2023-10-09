#include "funcionality.hpp"

#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>

using namespace std;




void crearMatrizA(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector < vector<long double> > &matrizA){   

    matrizA.push_back((long double)numeroElementos.size());

    for(int i = 0; i < numeroElementos.size();i++){

        for(int j = 0; j < tiemposReales.size();j++){

            matrizA.push_back(sumatorio(numeroElementos,tiemposReales,i+j,0));

        }

    }

}

void crearMatrizB(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector < vector<long double> > &matrizB){

//int ordenMatriz = numeroElementos.size()+tiemposReales.size();    

    for(int i = 0; i < numeroElementos.size();i++){

        for(int j = 0; j < tiemposReales.size();j++){

            matrizB.push_back(sumatorio(numeroElementos,tiemposReales,i,1));

        }

    }

}

void ajusteCuadratico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a){

    vector < vector<long double> > matrizA (3,vector <long double>(3));
    vector < vector<long double> > matrizB (3,vector <long double>(1));
    vector < vector<long double> > matrizR (3,vector <long double>(1));

    crearMatrizA(numeroElementos, tiemposReales, matrizA);
    crearMatrizB(numeroElementos, tiemposReales, matrizB);

}


long double sumatorio(const vector<double> &n,const vector <double> &t, int expN, int expT){

    long double sum = 0;

    for(int i=0; i<n.size(); i++){
        
        sum+=(pow(n[i], expN)*pow(t[i], expT));

    }
    return sum;

}
void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados);
long double calcularCoeficienteDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados);
long double calcularTiempoEstimadoPolinomico(const double &n,vector<double> &a);
long double calcularVarianza();
