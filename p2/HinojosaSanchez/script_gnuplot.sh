#!/bin/bash

# Archivo de datos
data_file="../Quicksort.txt"

#output_file="../grafico_$(date +%Y%m%d%H%M%S).eps"

# Configuración de Gnuplot
gnuplot <<-EOF
    set terminal postscript eps color
    set output "grafico.eps"
    set key right bottom
    set style data lines
    set xlabel "N de Ejemplar"
    set ylabel "Tiempo(ms)"
    set title "Comparativa Quicksort"
    plot '$data_file' using 1:2 with lines title "Quicksort Hoare", '$data_file' using 1:3 t "Quicksort Mediana" w l
EOF

# Mostrar la gráfica usando un visor de imágenes (por ejemplo, en Linux)
xdg-open grafico.eps
