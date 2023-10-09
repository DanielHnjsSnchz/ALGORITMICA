#include "fibonacci.hpp"

using namespace std;

int fibonacci(int &n){
    if(n<=2){
        return n-1;
    }else{
        return (fibonacci(n-1)+fibonacci(n-2));
    }
}

void tiemposFibonacci(int &nMin, int &nMax,int &repeticiones,vector <double> &tiemposReales, vector <double> &numeroElementos ){

    Clock time;
    long double tiempoAcumulado=0;
    vector <int> v(nMax-nMin);

    for(unsigned int a=nMin;a<=nMax;a+incremento){
            time.restart();

            int resultado = fibonacci(int &a);
            cout<<resultado<<endl;
            if (time.isStarted())
	        {
		        time.stop();
                tiempoAcumulado+=time.elapsed();
                
	        } 
        tiemposReales.push_back(tiempoAcumulado/repeticiones);
        numeroElementos.push_back(a);        
    }

}

void fibonacci(){

    Clock time;
    int nMin, nMax; 
    vector <double> tiemposReales;
    vector <double> nElementos;   

    cout<<"Introduzca el valor de n minimo"<<endl;
    cin>>nMin;
    cout<<"Introduzca el valor de n minimo"<<endl;
    cin>>nMax;
    cout<<"Introduzca el incremento del valor del número de elementos del vector"<<endl;
    cin>>incremento;


    tiemposFibonacci(nMin,nMax,incremento,tiemposReales,nElementos);
    

}