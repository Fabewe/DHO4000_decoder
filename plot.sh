#!/bin/bash

#OJO: adaptar las leyendas a los nombres de las variables. En el eje Y se miden tiempos y en el eje X es el tamaño del ejemplar.
cat << _end_ | gnuplot
# Set up the terminal and output file
set terminal pngcairo enhanced font "Helvetica,12"
set output '$1_plot.png'

# Set up the title and labels
set title "$1"
set xlabel "Time"
set ylabel "Volts(V)"
set y2label "Amps(A)"
set y2tics

set datafile separator comma
unset xtics

# Define the data file and column mappings

y1_column = 1           # Column for y1 values
y2_column = 2           # Column for y2 values

# Set up the y range for each axis
set yrange [*:*]
set y2range [*:*]

# Plot the first graph with the first y-axis
plot "$1.txt" using 0:1 with lines title columnhead(1) axis x1y1 , "$1.txt" using 0:y2_column with lines title columnhead(2) axis x1y2

# Plot the second graph with the second y-axis
     
     

_end_
