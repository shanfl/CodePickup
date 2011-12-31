#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '2-8.ps'

set ylabel "Execution Time (in ms)" 
set title "Average time to compute 2^x"

set xrange [ 0 : 64 ] noreverse nowriteback
set yrange [ 0 : 310 ] noreverse nowriteback

set xtics 10.0
set ytics 50.0

plot "figure2-8.dat" using 1:2 with linespoints notitle
#    EOF
