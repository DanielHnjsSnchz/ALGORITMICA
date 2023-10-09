#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Numero de elementos"
set ylabel "Tiempo (ms)"
plot 'datosFinalesSeleccion.txt' using 1:2 t "Tiempos reales frente a numero elementos", 'datosFinales.txt' using 1:3 t "Tiempos estimados frente a numero elementos" w l 
_end_