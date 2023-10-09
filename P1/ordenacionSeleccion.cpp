#include "ordenacionSeleccion.hpp"
#include "funcionality.hpp"

using namespace std;


//
//FICHEROS
//

void ficheroTiemposReales(vector <double> &tiemposReales, vector <double> &numeroElementos){

    ofstream f("tiemposReales.txt");

    f.open("tiemposReales.txt");

    for(auto i = 0; i < numeroElementos.size(); i++){

        f<<numeroElementos[i];
        f<<"; ";
        f<<tiemposReales[i];
        f<<"/n";

    }

    f.close();
}



void ficheroDatosFinales(int size, vector <double> &tiemposReales, vector <double> &tiemposEstimados){

    ofstream f("datosFinales.txt");

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
for(int a=nMin;a<=nMax;a=a+incremento){
    long double tiempoAcumulado=0;
    vector <int> v(a);
        for(int b=0;b<repeticiones;b++){
            
            rellenarVector(v);
            time.restart();

            void ordenacionSeleccion(vector <int> &v);

            if (time.isStarted())
	        {
		        time.stop();
                tiempoAcumulado+=time.elapsed();
                cout<<"Time: "<<tiempoAcumulado<<endl;
                
	        }
        }  
        tiemposReales.push_back(tiempoAcumulado/repeticiones);
        numeroElementos.push_back(a);        
}

ficheroTiemposReales(numeroElementos,tiemposReales); 


}

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

    
}
            
    


