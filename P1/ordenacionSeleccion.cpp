#include "ordenacionSeleccion.hpp"
#include "funcionality.hpp"

using namespace std;


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
//ORDENACION SELECCION
void ordenacionSeleccion(){

    Clock time;
    int nMin, nMax, incremento, repeticiones;
    vector <double> tiemposReales;
    vector <double> nElementos;

    cout<<"Introduzca el valor mínimo del número de elementos del vector"<<endl;
    cin>>nMin;
    cout<<"Introduzca el valor máximo del número de elementos del vector"<<endl;
    cin>>nMax;
    cout<<"Introduzca el incremento del valor del número de elementos del vector"<<endl;
    cin>>incremento;
    cout<<"Introduzca el valor de repeticiones"<<endl;
    cin>>repeticiones;

    tiemposOrdenacionSeleccion( nMin,  nMax,  incremento,  repeticiones, tiemposReales, nElementos);

    
}
            
    
//
//RELLENAR VECTOR
//
void rellenarVector(vector<int> &v){

    for(unsigned int i = 0; i < v.size(); i++){
        //numero random
        v[i]=0+rand()%(10000000-1);
    }

}
//
//COMPROBACION DE ORDENACION
//
bool estaOrdenado(const vector<int> &v){
    for(unsigned int i = 0; i < v.size(); i++){
        if(v[i+1]!= NULL){
            if(v[i]>v[i+1])
                return false;
        }
    }
    return true;
}
//
//TIEMPO DE ORDENACION
//
void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, vector<double> &tiemposReales,vector<double> &numeroElementos){

}

void tiemposOrdenacionSelección(int nMin, int nMax, int incremento, int
repeticiones, vector <double> &tiemposReales, vector <double>
&numeroElementos)
{
for(unsigned int a=nMin;a<=nMax;a+incremento){
    long double tiempoAcumulado=0;
    vector <int> v(a);
        for(unsigned int b=0;b<repeticiones;b++){
            
            rellenarVector(v);
            time.restart();

            void ordenacionSeleccion(vector <int> &v);

            if (time.isStarted())
	        {
		        time.stop();
                tiempoAcumulado+=time.elapsed();
                
	        }
        }  
        tiemposReales.push_back(tiempoacumulado/repeticiones);
        numeroElementos.push_back(a);        
    }

}
