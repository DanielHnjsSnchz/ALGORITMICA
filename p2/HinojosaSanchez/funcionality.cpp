#include "funcionality.hpp"
#include "quicksort.hpp"
#include "misc.hpp"

using namespace std;

void comparacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo){

    vector<double> tiemposRealesQSHOARE;
    vector<double> tiemposRealesQSMEDIANA;
    vector<double> numeroElementos;

    tiemposOrdenacionVariantesQuicksort(nMin, nMax, incremento, repeticiones, nMediana, nElementosMinimo, tiemposRealesQSHOARE, tiemposRealesQSMEDIANA, numeroElementos);

    ficheroTiemposReales(numeroElementos, tiemposRealesQSHOARE, tiemposRealesQSMEDIANA);
    cout << "\nGuardando y mostrando gráfica: "<< endl;
    mostrarGrafica("../script_gnuplot.sh");

}

void rellenarVector(vector<int> &v){

    for(unsigned int i = 0; i < v.size(); i++){
        //numero random
        v[i]=rand()%(10000000-1);
    }

}


void ficheroTiemposReales(vector <double> &numeroElementos, vector <double> &tiemposRealesHoare, const vector <double> &tiemposRealesMediana){

    ofstream file("../Quicksort.txt");

    file << "Tamaño Ejemplar        Tiempos reales QSHOARE         Tiempos reales QSMEDIANA" << endl;

    for(int i=0; i<=numeroElementos.size() -1; i++){

        file << numeroElementos[i] << "                 " << tiemposRealesHoare[i] << "                  " << tiemposRealesMediana[i] << endl;
    }

    file.close();

}