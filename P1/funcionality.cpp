#include "funcionality.hpp"

#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>

using namespace std;




void crearMatrizA(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizA){   

    for(int i = 0; i < numeroElementos.size();i++){

        for(int j = 0; j < tiemposReales.size();j++){
            if((i&&j)==0){
                matrizA[i][j] = numeroElementos.size();
            }
            else{
                matrizA[i][j] = sumatorio(numeroElementos, tiemposReales, i+j, 0);
            }
        }

    }

}

void crearMatrizB(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizB){

//int ordenMatriz = numeroElementos.size()+tiemposReales.size();    

    for(int i = 0; i < numeroElementos.size();i++){

        for(int j = 0; j < tiemposReales.size();j++){

            matrizB[i][0] = sumatorio(numeroElementos,tiemposReales,i,1);

        }

    }

}

void ajusteCuadratico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a){

    vector <vector<double>> matrizA (3,vector <double>(3));
    vector <vector<double>> matrizB (3,vector <double>(1));
    vector <vector<double>> matrizR (3,vector <double>(1));

    crearMatrizA(numeroElementos, tiemposReales, matrizA);
    crearMatrizB(numeroElementos, tiemposReales, matrizB);

    resolverSistemaEcuaciones(matrizA,matrizB,matrizA.size(),matrizR);

    for(int i = 0; i<matrizR.size(); i++){
        a[i] = matrizR[i][0];
    }

    resolverSistemaEcuaciones(matrizA, matrizB, 3, matrizR);

    for(int i=0; i<3; i++){
        a.push_back(matrizR[i][0]);
    }


}


long double sumatorio(const vector<double> &n,const vector <double> &t, int expN, int expT){

    long double sum = 0;

    for(int i=0; i<n.size(); i++){
        
        sum+=(pow(n[i], expN)*pow(t[i], expT));

    }
    return sum;

}



void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados){

    for(int i=0; i<numeroElementos.size(); i++){
        double t = a[0] + a[1] * numeroElementos[i] + a[2] * pow(numeroElementos[i],2);
        tiemposEstimados.push_back(t);
    }

}


long double calcularTiempoEstimadoPolinomico(const vector<double> &n, vector<double> &a){

    double t = 0.0;

    for(int i=0; i < n.size(); i++){
        // t(n) = a0+a1*n1 +a2*n2^2
        t += a[0] + a[1] * n[i] + a[2] * pow(n[i],2);
    }
    return t;

}



long double calcularCoeficienteDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados){

    double var1 = 0;
    double var2 = 0;

    var1 = calcularVarianza(tiemposReales);
    var2 = calcularVarianza(tiemposEstimados);

    double coeficienteDeterminacion = 0;

    coeficienteDeterminacion = var2/var1;

    return coeficienteDeterminacion;

}

long double calcularVarianza(const vector<double> &v){

    double mean = 0;
    mean = calcularMedia(v);

    double aux = 0;
    double cont = v.size();
    //Calcular varianza
    for(int i=0; i<cont; i++){
        aux += pow((v[i] - mean), 2);
    }

    return (aux/cont);
}


long double calcularMedia(const vector <double> &v){
    
    double aux = 0;
    double cont = v.size();

    for(int i = 0; i<cont; i++){
        aux += v[i];
    }

    return (aux/cont);

}

/*void rellenarArchivoTiemposReales(string nombre, vector <double> &numeroElementos, vector <double> &tiemposReales){

    ofstream file(nombre);

    //Columnas del fichero
    file << "Numero de elementos    Tiempos Reales" << endl;

    //Rellenamos    
    for(unsigned int i=0; i<=tiemposReales.size(); i++){
        file << numeroElementos[i]<< "                  " <<tiemposReales[i] << endl;
    }

    //Cerramos
    file.close();
}

void rellenarDatosFinales(string nombre, vector <double> &numeroElementos, vector <double> &tiemposReales, const vector <double> &tiemposEstimados){

    ofstream file(nombre);
    
    file << "Tamaño Ejemplar    Tiempo Real     Tiempos Estimados" << endl;

    for(int i=0; i<=numeroElementos.size(); i++){

        file << numeroElementos[i] << "\t" << tiemposReales[i] << "\t" << tiemposEstimados[i] << endl;
    }

    file.close();
}*/
