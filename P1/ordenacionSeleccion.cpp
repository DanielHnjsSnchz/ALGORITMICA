#include "ordenacionSeleccion.hpp"

using namespace std;


//
//FICHEROS
//

void ficheroTiemposReales(vector <double> &tiemposReales, vector <double> &numeroElementos){

    ofstream f("tiemposRealesSeleccion.txt");

    f << "Numero de elementos    Tiempos Reales" << endl;


    for(auto i = 0; i <= tiemposReales.size(); i++){

        f << numeroElementos[i]<<"                      " <<tiemposReales[i] << "\n";

    }

    f.close();
}



void ficheroDatosFinales(vector <double> &numeroElementos, vector <double> &tiemposReales, vector <double> &tiemposEstimados){

    ofstream f("datosFinalesSeleccion.txt");

    f << "Tamaño Ejemplar    Tiempo Real     Tiempos Estimados" << endl;

    for(auto i=0; i <= numeroElementos.size(); i++){

        f << numeroElementos[i] << "                      " << tiemposReales[i] << "                      " << tiemposEstimados[i] << endl;
    }

    f.close();


}

//
//RELLENAR VECTOR
//

void rellenarVector(vector<int> &v){

    for(unsigned int i = 0; i < v.size(); i++){
        //numero random
        v[i]=rand()%(10000000-1);
    }

}

//
//COMPROBACION DE ORDENACION
//

bool estaOrdenado(const vector<int> &v){
    /*for(size_t i=0; i <=v.size(); i++){
        if(v[i]>v[i+1])
             return false;
    }
    */
    for(size_t i=0; i < v.size()-1; i++){
        if(v[i]>v[i+1])
             return false;
    }
    return true;
}


//
//TIEMPO DE ORDENACION
//

void tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int repeticiones, vector <double> &tiemposReales, vector <double> &numeroElementos){
    Clock time;
    double tiempoAcumulado=0;
    vector <int> v;

    for(int a=nMin;a<=nMax;a=a+incremento){
        
            for(int b=0;b<repeticiones;b++){

                v.clear();
                v.resize(a);

                rellenarVector(v);

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

//
//ALGORITMO DE ORDENACION POR SELECCION
//

void ordenacionSeleccion(vector <int> &v){

    int posicionMenor;
    int aux;
    //ORDENACION
    for(unsigned int i=0; i<v.size()-1; i++){
        posicionMenor=v[i];
        for(unsigned int j=i+1; j<v.size();j++){
            if(v[j]<v[posicionMenor]){
                posicionMenor=v[j];
            }
        }
        aux=v[i];
        v[i]=v[posicionMenor];
        v[posicionMenor]=aux;
    }

}

//
//ORDENACION SELECCION
//

void ordenacionSeleccion(){

    //Clock time;
    int nMin, nMax, incremento, repeticiones;
    vector <double> tiemposReales;
    vector <double> tiemposEstimados;
    vector <double> nElementos;
    vector <double> a(3);

    cout<<"Introduzca el valor mínimo del número de elementos del vector"<<endl;
    cin>>nMin;
    cout<<"Introduzca el valor máximo del número de elementos del vector"<<endl;
    cin>>nMax;
    cout<<"Introduzca el incremento del valor del número de elementos del vector"<<endl;
    cin>>incremento;
    cout<<"Introduzca el valor de repeticiones"<<endl;
    cin>>repeticiones;

    tiemposOrdenacionSeleccion( nMin,  nMax,  incremento,  repeticiones, tiemposReales, nElementos);

    ficheroTiemposReales(tiemposReales, nElementos); 

    ajusteCuadratico(nElementos, tiemposReales,a);

    calcularTiemposEstimadosPolinomico(nElementos, a, tiemposEstimados);

    double sigma = calcularCoeficienteDeDeterminacion(tiemposReales, tiemposEstimados);

    cout << endl;
    cout << "El coeficiente de determinación es de " << 1-sigma << endl;
    cout << "f(n) = " << a[0] << " + " << a[1] << " * n + "<< a[2] << " * n2" << endl;

    ficheroDatosFinales(nElementos, tiemposReales, tiemposEstimados);
    //mostrarGrafica("script_gnuplotSeleccion.sh");

    double n;

     while(n != 0){
        cout << endl;
        cout << "Introduzca el valor que quiera estimar" << endl;
        cout << "0.- Salir" << endl;
        cin >> n;
        if (n != 0){
            double microseg = calcularTEstimadoPolinomico(n, a);
            conversionTiempo(microseg);
        }
    }

    
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


double sum(const vector<double> &n,const vector <double> &t, int expN, int expT){

    double sum = 0;

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



double calcularTEstimadoPolinomico(const double &n, vector<double> &a){

    double t = 0.0;
        t = a[0] + a[1] * n + a[2] * pow(n,2);
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