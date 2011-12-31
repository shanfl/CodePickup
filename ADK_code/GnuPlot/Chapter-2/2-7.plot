#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '2-7.ps'

set xlabel "n = number of digits"
set ylabel "Execution Time (in ms)" 
set title "GCD performance"

set key top left 
set key box

set xrange [ 0 : 128 ] noreverse nowriteback
set yrange [ 0 : 350000 ] noreverse nowriteback

set xtics 20.0
set ytics 50000.0

plot 'figure2-7.dat' using 1:2 index 0 title "modgcd" with lines,'figure2-7.dat' using 1:3 index 0 title "gcd" with lines

#    EOF
