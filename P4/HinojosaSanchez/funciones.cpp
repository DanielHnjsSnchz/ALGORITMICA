#include "funciones.hpp"
#include <algorithm>

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

/*void escribirSolucion(vector<MaterialUsado> &solucion) {
    cout << "Solución de la mochila:" << endl;

    float costoTotal = 0.0;
    for (const auto &materialUsado : solucion) {
        Material material = materialUsado.getMaterial();
        float volumenUsado = materialUsado.getVolumenUsado();
        float costoMaterial = material.getPrecio() * volumenUsado;

        cout << "Material " << material.getEtiqueta() << ": Volumen usado = " << volumenUsado
             << ", Costo = " << costoMaterial << endl;

        costoTotal += costoMaterial;
    }

    cout << "Costo total de la mochila: " << costoTotal << endl;
}*/


/**/





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

/*void obtenerSolucion(vector<vector<int>> &matrizEstados, vector<int> &solucion, vector<Moneda> &sistemaMonetario) {
    int numMonedas = sistemaMonetario.size();
    int cantidad = solucion.size() - 1;
    int i = numMonedas - 1;

    while (i >= 0 && cantidad > 0) {
        if (i == 0 || matrizEstados[i][cantidad] != matrizEstados[i - 1][cantidad]) {
            solucion[i] = matrizEstados[i][cantidad] - matrizEstados[i - 1][cantidad];
            cantidad -= sistemaMonetario[i].getValor();
        }

        --i;
    }
}*/

//Obtener solucion Mochila
void obtenerSolucion(vector<vector<double>> &matrizEstados, vector<MaterialUsado> &solucion, vector<Material> &materiales ) {
    int i = matrizEstados.size() - 1; // Índice de la última fila
    int j = matrizEstados[0].size() - 1; // Índice de la última columna

    while (i > 0 && j > 0) {
        // Si el valor es diferente al de la fila anterior, entonces el material i está en la solución
        if ((matrizEstados[i][j] != matrizEstados[i - 1][j]) && (matrizEstados[i][j] = (matrizEstados[i - 1][j-materiales[i].getVolumen()])+materiales[i].getVolumen()*materiales[i].getPrecio())) {
            float volumenUsado = materiales[i].getVolumen();
            solucion.push_back(MaterialUsado(materiales[i], volumenUsado));
            j -= volumenUsado;
        }
        i--;
    }

    // Si queda algún material en la primera fila por revisar, añádelo si es necesario
    if (i == 0 && matrizEstados[i][j] != 0) {
        float volumenUsado = materiales[i].getVolumen();
        solucion.push_back(MaterialUsado(materiales[i], volumenUsado));
    }

}

/*void obtenerSolucion(vector<vector<double>> &matrizEstados, vector<MaterialUsado> &solucion, vector<Material> &materiales ) {
    int n = materiales.size();
    int volumenMochila = matrizEstados[0].size() - 1;

    int i = n - 1;
    int j = volumenMochila;

    while (i > 0 && j > 0) {
        if (matrizEstados[i][j] != matrizEstados[i - 1][j]) {
            float volumenUsado = materiales[i].getVolumen();
            MaterialUsado materialUsado(materiales[i], volumenUsado);
            solucion.push_back(materialUsado);
            j -= volumenUsado;
        }
        i--;
    }

    if (matrizEstados[i][j] != 0) {
        float volumenUsado = materiales[i].getVolumen();
        MaterialUsado materialUsado(materiales[i], volumenUsado);
        solucion.push_back(materialUsado);
    }
}*/


/*void obtenerSolucion(vector<vector<double>> &matrizEstados, vector<MaterialUsado> &solucion, vector<Material> &materiales) {
    int n = materiales.size();
    int volumenMochila = matrizEstados[0].size() - 1;
    int i = n - 1;
    int j = volumenMochila;

    // Recorrer la matriz de estados para obtener la solución
    while (i >= 0 && j >= 0) {
        if (i == 0 && matrizEstados[i][j] > 0) {
            solucion.push_back(MaterialUsado(materiales[i], materiales[i].getVolumen()));
            break;
        }

        if (i > 0 && matrizEstados[i][j] != matrizEstados[i - 1][j]) {
            solucion.push_back(MaterialUsado(materiales[i], materiales[i].getVolumen()));
            j -= materiales[i].getVolumen();
        }

        --i;
    }
}*/



/*void obtenerSolucion(vector<vector<double>> &matrizEstados, vector<MaterialUsado> &solucion, vector<Material> &materiales) {
    int i = matrizEstados.size() - 1;
    int j = matrizEstados[0].size() - 1;

    while (i >= 0 && j >= 0) {
        if (i == 0) {
            if (matrizEstados[i][j] > 0) {
                solucion.push_back(MaterialUsado(materiales[i], j));
            }
            break;
        }

        if (matrizEstados[i][j] != matrizEstados[i - 1][j]) {
            solucion.push_back(MaterialUsado(materiales[i], j));
            j = j - materiales[i].getVolumen();
        }

        --i;
    }
}*/

