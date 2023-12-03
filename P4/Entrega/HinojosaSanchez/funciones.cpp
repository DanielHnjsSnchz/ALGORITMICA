#include "funciones.hpp"

#include <fstream>
#include <iostream>

//Cargar Sistema Monetario
void cargarSistemaMonetario(vector<Moneda> &sistemaMonetario, const char *nombreFichero) {
    ifstream f(nombreFichero);
    if (f.is_open()) {
        int valor;
        while (f >> valor) {
            Moneda moneda(valor);
            sistemaMonetario.push_back(moneda);
        }
        cout << "\nEl fichero "<<nombreFichero <<" ha sido cargado con éxito.\n";
        f.close();
    } else {
        cout << "\nError al abrir el fichero "<<nombreFichero <<".\n";
    }
}

//Cargar Materiales
void cargarMateriales(vector<Material> &materiales, const char *nombreFichero) {
    ifstream f(nombreFichero);
    if (f.is_open()) {
        int etiqueta;
        float volumen, precio;
        while (f >> etiqueta >> volumen >> precio) {
            Material material(etiqueta, volumen, precio);
            materiales.push_back(material);
        }
        cout << "\nEl fichero "<<nombreFichero <<" ha sido cargado con éxito.\n";
        f.close();
    } else {
        cout << "\nError al abrir el fichero "<<nombreFichero <<".\n";
    }
}

//Escribir Solucion Sistema Monetario
void escribirSolucion(vector<int> &solucion, vector<Moneda> &sistemaMonetario) {
    cout << "\nSolución del problema del cambio:\n";
    for (size_t i = 0; i < sistemaMonetario.size(); ++i) {
        cout << "\tMoneda de " << sistemaMonetario[i].getValor() << " céntimos: " << solucion[i] << " unidades\n";
    }
}


//Escribir Solucion Mochila
void escribirSolucion(vector<MaterialUsado> &solucion) {

    float precioTotal=0;
    cout << "\nSolución del problema de la mochila: \n";

    for (size_t i = 0; i < solucion.size(); ++i) {

        Material material = solucion[i].getMaterial();
        cout << "\tMaterial " << material.getEtiqueta() << ": Volumen usado = " << solucion[i].getVolumenUsado()
             << ", Precio por unidad de volumen = " << material.getPrecio() << endl;
        
        precioTotal+=(material.getPrecio()*solucion[i].getVolumenUsado());

    }

    cout<<"\nPrecio total: "<<precioTotal<<endl;

}


//Obtener solucion Sistema Monetario
void obtenerSolucion(vector<vector<int>>& matrizEstados, vector<int>& solucion, vector<Moneda>& sistemaMonetario) {
    int n = matrizEstados.size();
    int N = matrizEstados[0].size() - 1;

    // Inicializar el vector de solución
    solucion.resize(n, 0);

    // Obtener la solución a partir de la matriz de estados
    int i = n - 1;
    int j = N; 

    while (i >= 0 && j > 0) {
        if (i == 0 || matrizEstados[i][j] != matrizEstados[i - 1][j]) {
            // Se utiliza la moneda i
            solucion[i]++;
            j -= sistemaMonetario[i].getValor();
        } else {
            // No se utiliza la moneda i
            i--;
        }
    }
}

//Obtener solucion Mochila
void obtenerSolucion(vector<vector<double>> &matrizEstados, vector<MaterialUsado> &solucion, vector<Material> &materiales ) {
    int i = materiales.size() - 1;
    int j = matrizEstados[0].size() - 1;

    while (i > 0 && j > 0) {
        if (matrizEstados[i][j] != matrizEstados[i - 1][j]) {
            solucion[i].setMaterial(materiales[i]);
            solucion[i].setVolumenUsado(materiales[i].getVolumen());
            j -= solucion[i].getVolumenUsado();
        }
        i--;
    }

    if (matrizEstados[i][j] != 0) {
        solucion[i].setMaterial(materiales[i]);
        solucion[i].setVolumenUsado(materiales[i].getVolumen());
    }
}

/*void obtenerSolucion(vector<vector<double>> &matrizEstados, vector<MaterialUsado> &solucion, vector<Material> &materiales ) {
    int i = matrizEstados.size() - 1; // Índice de la última fila
    int j = matrizEstados[0].size() - 1; // Índice de la última columna
    solucion.clear();
    solucion.resize(i);

    while(i >= 0 && j >= 0){

        if (i == 0){
            if(j>=materiales[i].getVolumen()){
                solucion[i].setMaterial(materiales[i]);
                solucion[i].setVolumenUsado(materiales[i].getVolumen());
            }else{
                solucion[i].setMaterial(materiales[i]);
                solucion[i].setVolumenUsado(0);
            }
        }else{

            if(matrizEstados[i][j] != matrizEstados[i-1][j]){
                if(j>=materiales[i].getVolumen()){
                    solucion[i].setMaterial(materiales[i]);
                    solucion[i].setVolumenUsado(materiales[i].getVolumen());

                    j=j-solucion[i].getVolumenUsado();
                }else{
                    solucion[i].setMaterial(materiales[i]);
                    solucion[i].setVolumenUsado(0);
                }
            }

        }
        i--;
    }

}*/

