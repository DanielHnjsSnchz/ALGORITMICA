#include "funciones.hpp"


//Cargar Sistema Monetario
void cargarSistemaMonetario(vector<Moneda> &sistemaMonetario, const char *nombreFichero) {
    ifstream archivo(nombreFichero);
    if (archivo.is_open()) {
        int valor;
        while (archivo >> valor) {
            Moneda moneda(valor);
            sistemaMonetario.push_back(moneda);
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

//Cargar Materiales
void cargarMateriales(vector<Material> &materiales, const char *nombreFichero) {
    ifstream archivo(nombreFichero);
    if (archivo.is_open()) {
        int etiqueta;
        float volumen, precio;
        while (archivo >> etiqueta >> volumen >> precio) {
            Material material(etiqueta, volumen, precio);
            materiales.push_back(material);
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

//Escribir Solucion Sistema Monetario
void escribirSolucion(vector<int> &solucion, vector<Moneda> &sistemaMonetario) {
    cout << "Solución del problema del cambio:\n";
    for (size_t i = 0; i < sistemaMonetario.size(); ++i) {
        cout << "Moneda de " << sistemaMonetario[i].getValor() << " céntimos: " << solucion[i] << " unidades\n";
    }
}


//Escribir Solucion Mochila
void escribirSolucion(vector<MaterialUsado> &solucion) {
    cout << "Solución del problema de la mochila:\n";
    for (const auto &materialUsado : solucion) {
        Material material = materialUsado.getMaterial();
        cout << "Material " << material.getEtiqueta() << ": Volumen usado = " << materialUsado.getVolumenUsado()
             << ", Precio por unidad de volumen = " << material.getPrecio() << endl;
    }
}