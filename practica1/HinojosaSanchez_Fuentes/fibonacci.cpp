#include "fibonacci.hpp"

using namespace std;


//
//FICHEROS
//

void ficheroTiemposRealesFibonacci(vector <double> &tiemposReales, vector <double> &numeroElementos){

    ofstream f("tiemposRealesFibonacci.txt");

    f << "Numero de elementos    Tiempos Reales" << endl;


    for(auto i = 0; i <= tiemposReales.size(); i++){

        f << numeroElementos[i]<<"                      " <<tiemposReales[i] << "\n";

    }

    f.close();
}



void ficheroDatosFinalesFibonacci(vector <double> &numeroElementos, vector <double> &tiemposReales, vector <double> &tiemposEstimados){

    ofstream f("datosFinalesSeleccion.txt");

    f << "Tamaño Ejemplar    Tiempo Real     Tiempos Estimados" << endl;

    for(auto i=0; i <= numeroElementos.size(); i++){

        f << numeroElementos[i] << "                      " << tiemposReales[i] << "                      " << tiemposEstimados[i] << endl;
    }

    f.close();


}

int fibonacci(int &n){
    if(n<=2){
        return n-1;
    }else{
        return (fibonacci(n-1)+fibonacci(n-2));
    }
}

//
//TIEMPO DE ORDENACION
//

void tiemposFibonacci(int &nMin, int &nMax, int &incremento, vector <double> &tiemposReales, vector <double> &numeroElementos){
    Clock time;
    double tiempoAcumulado=0;

    for(int a=nMin;a<=nMax;a=a+incremento){

                time.restart();

                fibonacci(a);

                if(time.isStarted()){
		            time.stop();
	            }
                tiempoAcumulado+=time.elapsed();

            tiemposReales.push_back(tiempoAcumulado);
            numeroElementos.push_back(a);  
              
    }

}



void fibonacci(){

    Clock time;
    int nMin, nMax, incremento; 
    vector <double> tiemposReales;
    vector <double> tiemposEstimados;
    vector <double> nElementos;
    vector <double> a; 

    cout<<"Introduzca el valor de n minimo"<<endl;
    cin>>nMin;
    cout<<"Introduzca el valor de n minimo"<<endl;
    cin>>nMax;
    cout<<"Introduzca el incremento del valor"<<endl;
    cin>>incremento;


    tiemposFibonacci(nMin,nMax,incremento,tiemposReales,nElementos);

    ficheroTiemposRealesFibonacci(tiemposReales, nElementos); 

    ajusteExponencial(nElementos, tiemposReales,a);

    calcularTiemposEstimadosPolinomicoFibonacci(nElementos, a, tiemposEstimados);

    double sigma = calcularCoeficienteDeDeterminacionFibonacci(tiemposReales, tiemposEstimados);

    cout << endl;
    cout << "El coeficiente de determinación es de " << sigma << endl;
    cout << "f(n) = " << a[0] << " + " << a[1] << " * n + "<< a[2] << " * n2" << endl;

    ficheroDatosFinalesFibonacci(nElementos, tiemposReales, tiemposEstimados);
    //mostrarGrafica("script_gnuplotFibonacci.sh");

    double n;

     while(n != 0){
        cout << endl;
        cout << "Introduzca el valor que quiera estimar" << endl;
        cout << "0.- Salir" << endl;
        cin >> n;
        if (n != 0){
            double microseg = calcularTEstimadoPolinomicoFibonacci(n, a);
            conversionTiempo(microseg);
        }
    }
    

}



//
//AJUSTES Y ESTIMACIONES
//

void crearMatrizAFibonacci(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizA){   

    for(auto i = 0; i < matrizA.size();i++){

        for(auto j = 0; j < matrizA.size();j++){

            if(i==0 && j==0){
                matrizA[i][j] = numeroElementos.size();
            }
            else{
                matrizA[i][j] = sumFibonacci(numeroElementos, tiemposReales, i+j, 0);
            }
        }

    }

}

void crearMatrizBFibonacci(const vector<double> &numeroElementos,const vector<double> &tiemposReales,vector <vector<double>> &matrizB){

    for(int i = 0; i < matrizB.size();i++){

        matrizB[i][0] = sumFibonacci(numeroElementos,tiemposReales,i,1);

    }

}

void ajusteExponencial(const vector<double> &numeroElementos, const vector<double> &tiemposReales, vector<double> &a){

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


double sumFibonacci(const vector<double> &n,const vector <double> &t, int expN, int expT){

    double sum = 0;

    for(int i=0; i<n.size(); i++){
        
        sum+=(pow(n[i], expN)*pow(t[i], expT));

    }
    return sum;

}


void calcularTiemposEstimadosPolinomicoFibonacci(const vector<double> &numeroElementos, const vector<double> &a, vector<double> &tiemposEstimados){

    for(int i=0; i<numeroElementos.size(); i++){
        double t = a[0] + a[1] * numeroElementos[i] + a[2] * pow(numeroElementos[i],2);
        tiemposEstimados.push_back(t);
    }
    
}    



double calcularTEstimadoPolinomicoFibonacci(const double &n, vector<double> &a){

    double t = 0.0;
        t = a[0] + a[1] * n + a[2] * pow(n,2);
    return t;

}



double calcularCoeficienteDeDeterminacionFibonacci(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados){

    double vartReal = 0;
    double vartEstimados = 0;

    vartReal = calcularVFibonacci(tiemposReales);
    vartEstimados = calcularVFibonacci(tiemposEstimados);

    double coeficienteDeterminacion = 0;

    coeficienteDeterminacion = vartEstimados/vartReal;

    return coeficienteDeterminacion;

}


double calcularVFibonacci(const vector<double> &v){

    double med = 0;
    med = calcularMFibonacci(v);

    double aux = 0;
    double cont = v.size();
    //Calcular varianza
    for(int i=0; i<cont; i++){
        aux += pow((v[i] - med), 2);
    }

    return (aux/cont);
}


double calcularMFibonacci(const vector <double> &v){
    
    double aux = 0;
    double cont = v.size();

    for(int i = 0; i<cont; i++){
        aux += v[i];
    }

    return (aux/cont);

}