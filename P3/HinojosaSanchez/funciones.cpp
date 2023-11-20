#include "funciones.hpp"


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