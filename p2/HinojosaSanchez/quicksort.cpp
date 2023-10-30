#include "funcionality.hpp"
#include "quicksort.hpp"
#include "misc.hpp"

using namespace std;

void tiemposOrdenacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo, vector <double> &tiemposRealesQSHOARE, vector <double> &tiemposRealesQSMEDIANA, vector <double> &numeroElementos){
    
    Clock time; 
    vector<int> v1,v2;
    int n=nMin;
    double media1, media2, mediaGlobal1, mediaGlobal2;

    for(int a=nMin;a<=nMax;a=a+incremento){

        media1 = 0.0;
        media2 = 0.0;

            for(int b=0;b<repeticiones;b++){

                v1.clear();
                v1.resize(a);
                v2.clear();
                v2.resize(a);

                rellenarVector(v1);
                v2 = v1;

                time.restart();

                quicksortHoare(nMin, v1.size()-1, v1);

                if(time.isStarted()){
                    time.stop();
                }

                media1 += time.elapsed();

                time.restart();

                quicksortMediana(nMin, v2.size()-1, nMediana, nElementosMinimo, v2);

                if(time.isStarted()){
                    time.stop();
                }

                media2 += time.elapsed();

            }

        media1 = media1/repeticiones;
        media2 = media2/repeticiones;

        cout <<"Tamaño actual: "<< a <<"         "<< "t_QSHOARE: "<< media1 << "       " << "t_QSMEDIANA: " << media2 << endl;

        tiemposRealesQSHOARE.push_back(media1);
        tiemposRealesQSMEDIANA.push_back(media2);

        numeroElementos.push_back(a);

        mediaGlobal1 += media1;
        mediaGlobal2 += media2;

    }

    double mediatHoare = mediaGlobal1/tiemposRealesQSHOARE.size();
    double mediatMediana = mediaGlobal2/tiemposRealesQSMEDIANA.size();

    cout << "\nLa media de los tiempos reales del Quicksort de Hoare es " <<  mediatHoare << endl;
    cout << "La media de los tiempos reales del Quicksort Mediana es " <<  mediatMediana << endl;
    cout << "\nCociente entre tQuicksort mediana / tQuicksort de hoare: " << mediatMediana/mediatHoare << endl;    
    
}


void quicksortHoare(int izq, int der, vector<int> &v){

    int i = izq;
    int j = der;
    int pivote = (izq+der)/2;
    int x = v[pivote];

    do{
        while(v[i] < x){
            i += 1;
        }

        while(v[j] > x){
            j -= 1;
        }

        if(i <= j){
            int aux = v[i]; v[i] = v[j];
            v[j] = aux; i += 1;
            j -= 1;
        }
    } while(i <= j);

    if(izq < j)
        quicksortHoare(izq, j, v);
    if(i < der)
        quicksortHoare(i, der, v);

}


void quicksortMediana(int izq, int der, int nMediana, int nElementosMinimo, vector<int> &v){

    int i = izq;
    int j = der;
    int x = 0;

    if((j - i) <= nElementosMinimo){
        int pivote = (izq+der)/2;
        x = v[pivote];
    }else{

        vector<int> aux(nMediana);
        aux.clear();
        aux.resize(nMediana);
        int n = 0;

        for(size_t i = izq; i < izq+nMediana+1; i++){
            aux[n] = v[i];
            n++;
        }

        ordenarSeleccion(aux);

        x = aux[(nMediana+1)/2];

    }

    do{
        while(v[i] < x){
            i += 1;
        }

        while(v[j] > x){
            j -= 1;
        }

        if(i <= j){
            int aux = v[i]; v[i] = v[j];
            v[j] = aux; i += 1;
            j -= 1;
        }

    }while(i <= j);

    if(izq < j){

        quicksortMediana(izq, j, nMediana, nElementosMinimo, v);

    }
        
    if(i < der){

        quicksortMediana(i, der, nMediana, nElementosMinimo, v);

    }
        


}

void ordenarSeleccion(vector<int> &v) {

    int n = v.size();

    for (int i = 1; i < n; ++i) {

        int aux = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > aux) {

            v[j + 1] = v[j];
            j = j - 1;

        }

        v[j + 1] = aux;

    }

}