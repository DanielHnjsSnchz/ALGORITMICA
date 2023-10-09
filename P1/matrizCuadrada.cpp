#include "matrizCuadrada.hpp"

using namespace std;


//
//FICHEROS
//

void ficheroTiemposReales(vector <double> &tiemposReales, vector <double> &numeroElementos){

    ofstream f("tiemposReales.txt");

    f << "Numero de elementos    Tiempos Reales" << endl;


    for(auto i = 0; i <= tiemposReales.size(); i++){

        f << numeroElementos[i]<<"                      " <<tiemposReales[i] << "\n";

    }

    f.close();
}



void ficheroDatosFinales(vector <double> &numeroElementos, vector <double> &tiemposReales, vector <double> &tiemposEstimados){

    ofstream f("datosFinales.txt");

    f << "Tamaño Ejemplar    Tiempo Real     Tiempos Estimados" << endl;

    for(auto i=0; i <= numeroElementos.size(); i++){

        f << numeroElementos[i] << "                      " << tiemposReales[i] << "                      " << tiemposEstimados[i] << endl;
    }

    f.close();


}

//
//RELLENAR VECTOR
//

void rellenarMatriz(vector <vector<double>> &m){

    string opt;
    double item;

    cout<<"¿Quiere rellenar la matriz manualmente?"<<endl;
    cin>>opt;

    if(opt=="S" || opt=="s"){
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.size(); j++) {
                cout<<"Introduzca la posicion "<<i<<","<<j<<"de la matriz:"<<endl;
                cin>>item;
                m[i][j] = item;
            }
        }
    }else if(opt=="N" || opt=="n"){
        // Recorrer la matriz y llenar con números aleatorios en el rango [0.95, 1.05]
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.size(); j++) {
                double numeroAleatorio = 0.95 + (std::rand() / (RAND_MAX / (1.05 - 0.95)));
                m[i][j] = numeroAleatorio;
            }
        }
    }else{
        cout<<"Opcion invalida"<<endl;
        exit(0);
    }

}

void tiemposCuadrado(int nMin, int nMax, int incremento, vector <double> &tiemposReales, vector <double> &numeroElementos){
    Clock time;
    double tiempoAcumulado=0;
    vector <int> v;

    for(int a=nMin;a<=nMax;a=a+incremento){
        

                v.clear();
                v.resize(a);

                rellenarMatriz(v);

                time.restart();

                void ordenacionSeleccion(vector <int> &v);

                if(time.isStarted()){
		            time.stop();
	            }
                tiempoAcumulado+=time.elapsed();
                
            }  
            tiempoAcumulado=tiempoAcumulado/repeticiones;
            tiemposReales.push_back(tiempoAcumulado);
            numeroElementos.push_back(a);  
              
    }

}

void matrizCuadrada(vector <vector<double>> &matrizA,vector <vector<double>> &matrizR){
    int n = matrizA.size();

    // Realizar la multiplicación de matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                matrizR[i][j] += matrizA[i][k] * matrizA[k][j];
            }
        }
    }
}



void matrizCuadrada(){
    int n,repeticiones;

    cout << "Ingrese el orden de la matriz: ";
    cin >> n;
    cout<<"Introduzca el valor de repeticiones"<<endl;
    cin>>repeticiones;

    vector<vector<double>> matriz(n, vector<double>(n));

    rellenarMatriz(matriz);

}