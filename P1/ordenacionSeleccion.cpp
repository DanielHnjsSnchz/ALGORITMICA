#include "ordenacionSeleccion.hpp"
#include "funcionality.hpp"

using namespace std;


//
//FICHEROS
//

void ficheroTiemposReales(vector <double> &tiemposReales, vector <double> &numeroElementos){

    ofstream f("tiemposReales.txt");

    f << "Numero de elementos    Tiempos Reales" << endl;


    for(auto i = 0; i < numeroElementos.size(); i++){

        f << numeroElementos[i]<<"                      " <<tiemposReales[i] << "\n";

    }

    f.close();
}



void ficheroDatosFinales(vector <double> &numeroElementos, vector <double> &tiemposReales, vector <double> &tiemposEstimados){

    ofstream f("datosFinales.txt");

    f << "Tamaño Ejemplar    Tiempo Real     Tiempos Estimados" << endl;

    for(auto i=0; i < numeroElementos.size(); i++){

        f << numeroElementos[i] << "\t" << tiemposReales[i] << "\t" << tiemposEstimados[i] << endl;
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
    /*for(vector<int>::iterator it=v.begin(); it != v.end(); ++it){
        if(v[it+1]!= NULL){
            if(v[it]>v[it+1])
                return false;
        }
    }*/
    for(size_t i=0; i <= v.size(); i++){
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
                tiempoAcumulado=tiempoAcumulado/repeticiones;
                cout<<"Time Elapsed: "<<time.elapsed()<<endl;
                cout<<"Time: "<<tiempoAcumulado<<endl;
            }  

            tiemposReales.push_back(tiempoAcumulado);
            numeroElementos.push_back(a);  
              
    }
    /*
    Clock time; // Para calcular el tiempo del algoritmo, utilizaremos la clase Clock

    // Creamos un vector vacio de tipo entero
    vector <int> v;
     // Tamano actual del vector
    int tamActual = nMin;
    // Variable que calcula el tiempo medio del algoritmo
    float media = 0.0;

    // para n de minimo a maximo + incremento
    while(tamActual < nMax + incremento){

        if(tamActual > nMax){
            tamActual = nMax;
        }
        
        // Ejecutamos el algoritmo durante el numero de repeticiones indicado por el usuario
        for(unsigned int j=0; j<=repeticiones; j++){
            
            //Limpiamos el vector
            v.clear();

            //Reservamos el tamaño del vector
            v.resize(tamActual);

            //Rellenamos el vector
            rellenarVector(v);

            //Iniciamos el tiempo
            time.restart();

            //Ordenamos el vector
            ordenar(v);

            //Comprobamos ordenació

            //Medimos el tiempo en la iteración actual
            //Comprobamos que empezó y lo paramos
            if(time.isStarted()){
                time.stop();
            }

            //Actualizamos la media de tiempo de ejecución del algoritmo
            media += time.elapsed();
        }

        //Calculamos tiempo media de todas las repeticiones de esta iteración
        media = media/repeticiones;

        //Guardamos en tiemposRealesel tiempo medio de todas las repeticiones de la iteración
        tiemposReales.push_back(media);

        cout<<tamActual<<":"<<media<<endl;

        //Guardamos en numeroElementos el tamaño actual del vector
        numeroElementos.push_back(tamActual);

        //Aplicamos el incremento para actualizar el valor del tamaño del vector
        tamActual += incremento;
    }
    */

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
    vector <double> a(2);

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

    ficheroDatosFinales(nElementos, tiemposReales, tiemposEstimados);

    
}
            
    
//
//AJUSTES Y ESTIMACIONES
//

void crearMatrizA(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizA){   

    cout<<"Creando matriz A..."<<endl;

    for(int i = 0; i < numeroElementos.size();i++){
        cout<<"CFor1..."<<endl;
        for(int j = 0; j < tiemposReales.size();j++){
            cout<<"CFor2..."<<endl;
            if(i==0 && j==0){
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
    cout<<"Creando matriz B..."<<endl;

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
