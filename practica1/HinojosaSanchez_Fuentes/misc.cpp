#include "misc.hpp"

#include <vector>
#include <cmath>
#include <numeric>
#include <string>
#include <fstream>
#include <iostream>

void conversionTiempo(double microseg){
    double seg = microseg / 1000000;
    long int min = seg / 60;
    double decimales = seg - (long int) seg;
    long int seg_int = ((long int) seg) % 60;

    seg = seg_int + decimales;

    long int hrs = min/60;
    min %= 60;

    long int dias = hrs/24;
    hrs %= 24;

    long int years = dias/365;
    dias %= 365;
    
    std::cout << "Años: " << years << std::endl;
    std::cout << "Días: " << dias << std::endl;
    std::cout << "Minutos: " << min << std::endl;
    std::cout << "Segundos: " << seg << std::endl;
}

void mostrarGrafica(std::string script){
    std::string orden = "./" + script;
    system(orden.c_str());
}