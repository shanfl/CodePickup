#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '2-6.ps'

set ylabel "Execution Time (in ms)" 
set xlabel "n = number of digits"
set title "Multiplication performance"

set key top left 
set key box

set xrange [ 0 : 512 ] noreverse nowriteback
set yrange [ 0 : 300000 ] noreverse nowriteback

set xtics 100.0
set ytics 50000.0

plot 'figure2-6.dat' using 1:2 index 0 title "mult" with lines,'figure2-6.dat' using 1:3 index 0 title "alt" with lines

#    EOF
