#include "funcionesMedioNivel.hpp"

using namespace std;

//Funcion de Medio Nivel del Cambio

void problemaCambio(){
    
    cout<<"\n<--------------------------------------------------------------------------------->\n";

    // Definir vector para el sistema monetario.
    vector<Moneda> sistemaMonetario;

    // Cargar el sistema monetario desde el archivo
    cargarSistemaMonetario(sistemaMonetario, "./sistemamonetario.txt");
    
    //Vector solucion
    vector<int> solucionCambio(sistemaMonetario.size(),0);
    
    // Pedir al usuario la cantidad para el problema del cambio
    int cantidad;
    cout<<"\nIntroduce la cantidad en centimos para el problema del cambio: "<<endl;
    cin>>cantidad;

    vector<vector<int>> matrizEstadosCambio(sistemaMonetario.size(),vector<int>(cantidad+1,0));

    // Obtener el cambio con el menor número de monedas
    cambio(cantidad, sistemaMonetario, matrizEstadosCambio);
    obtenerSolucion(matrizEstadosCambio, solucionCambio,sistemaMonetario);

    // Mostrar la solución del problema del cambio
    escribirSolucion(solucionCambio, sistemaMonetario);

}

void problemaMochila(){

    cout<<"\n<--------------------------------------------------------------------------------->\n";

    // Definir vector para los materiales
    vector<Material> materiales;

    // Cargar los materiales desde el archivo
    cargarMateriales(materiales, "./materialesmochila.txt");

    //Vector solucion
    vector<MaterialUsado> solucionMochila;
    for(int i = 0; i<materiales.size(); i++){
        solucionMochila.push_back(MaterialUsado(materiales[i],0));
    }

    // Pedir al usuario el volumen de la mochila para el problema de la mochila
    float volumenMochila;
    cout << "\nIntroduce el volumen de la mochila para el problema de la mochila: ";
    cin >> volumenMochila;

    vector<vector<double>> matrizEstadosMochila(materiales.size(),std::vector<double>(volumenMochila));
    /*for(int i = 0; i<materiales.size(); i++){
        for(int j = 0; j<volumenMochila; j++){
            matrizEstadosMochila[i][j] = 0;
        }
    }*/

    // Resolver el problema de la mochila
    mochila(volumenMochila, materiales, matrizEstadosMochila);
    obtenerSolucion(matrizEstadosMochila,solucionMochila,materiales);
    // Mostrar la solución del problema de la mochila
    escribirSolucion(solucionMochila);


}