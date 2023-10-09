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

    for(int a=nMin;a<=nMax;a=a+incremento){
        vector<vector<double>> m(a, vector<double>(a));
        vector<vector<double>> matrizR(a, vector<double>(a));

                m.clear();
                //m.resize(a);

                rellenarMatriz(m);

                time.restart();

                void matrizCuadrada(vector <vector<double>> &m,vector <vector<double>> &matrizR);

                if(time.isStarted()){
		            time.stop();
	            }
                tiempoAcumulado+=time.elapsed();
                
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

    int nMin, nMax, incremento;
    vector <double> tiemposReales;
    vector <double> tiemposEstimados;
    vector <double> nElementos;
    vector <double> a(3);

    cout << "Ingrese el orden de la matriz minimo: ";
    cin >> nMin;
    cout << "Ingrese el orden de la matriz maximo: ";
    cin >> nMax;
    cout<<"Introduzca el valor de incremento"<<endl;
    cin>>incremento;

    //vector<vector<double>> matriz(n, vector<double>(n));

    tiemposCuadrado(nMin,  nMax,  incremento, tiemposReales, nElementos);

    ficheroTiemposReales(tiemposReales, nElementos); 

    ajusteCubico(nElementos, tiemposReales,a);

    calcularTiemposEstimadosPolinomico(nElementos, a, tiemposEstimados);

    ficheroDatosFinales(nElementos, tiemposReales, tiemposEstimados);

    cout<<"\nCOEFICIENTE DE DETERMINACION: "<<calcularCoeficienteDeDeterminacion(tiemposReales, tiemposEstimados)<<endl;

}



//
//AJUSTES Y ESTIMACIONES
//

void crearMatrizA(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizA){   

    for(auto i = 0; i < matrizA.size();i++){

        for(auto j = 0; j < matrizA.size();j++){

            if(i==0 && j==0){
                matrizA[i][j] = numeroElementos.size();
            }
            else{
                matrizA[i][j] = sum(numeroElementos, tiemposReales, i+j, 0);
            }
        }

    }

}

void crearMatrizB(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizB){

    for(int i = 0; i < matrizB.size();i++){

        matrizB[i][0] = sum(numeroElementos,tiemposReales,i,1);

    }

}

void ajusteCubico(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a){

    vector <vector<double>> matrizA (4,vector <double>(4));
    vector <vector<double>> matrizB (4,vector <double>(1));
    vector <vector<double>> matrizR (4,vector <double>(1));

    crearMatrizA(numeroElementos, tiemposReales, matrizA);
    crearMatrizB(numeroElementos, tiemposReales, matrizB);

    resolverSistemaEcuaciones(matrizA,matrizB,matrizA.size(),matrizR);

    for(int i = 0; i<matrizR.size(); i++){
        a[i] = matrizR[i][0];
    }

    resolverSistemaEcuaciones(matrizA, matrizB, 4, matrizR);

    for(int i=0; i<4; i++){
        a.push_back(matrizR[i][0]);
    }


}


double sum(const vector<double> &n,const vector <double> &t, int expN, int expT){

    double sum = 0;

    for(int i=0; i<n.size(); i++){
        
        sum+=(pow(n[i], expN)*pow(t[i], expT));

    }
    return sum;

}


void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados){

    for(int i=0; i<numeroElementos.size(); i++){
        double t = a[0] + a[1] * numeroElementos[i] + a[2] * pow(numeroElementos[i],2) + a[3] * pow(numeroElementos[i],3);
        tiemposEstimados.push_back(t);
    }
    
}    



double calcularTEstimadoPolinomico(const double &n, vector<double> &a){

    double t = 0.0;
        t = a[0] + a[1] * n + a[2] * pow(n,2) + a[3] * pow(n,3);
    return t;

}



double calcularCoeficienteDeDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados){

    double vartReal = 0;
    double vartEstimados = 0;

    vartReal = calcularV(tiemposReales);
    vartEstimados = calcularV(tiemposEstimados);

    double coeficienteDeterminacion = 0;

    coeficienteDeterminacion = vartEstimados/vartReal;

    return coeficienteDeterminacion;

}


double calcularV(const vector<double> &v){

    double med = 0;
    med = calcularM(v);

    double aux = 0;
    double cont = v.size();
    //Calcular varianza
    for(int i=0; i<cont; i++){
        aux += pow((v[i] - med), 2);
    }

    return (aux/cont);
}


double calcularM(const vector <double> &v){
    
    double aux = 0;
    double cont = v.size();

    for(int i = 0; i<cont; i++){
        aux += v[i];
    }

    return (aux/cont);

}