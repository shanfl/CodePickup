#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '2-9.ps'

set ylabel "Execution Time (in ms)" 0.0,0.0  
set title "Average execution of 10,000 invocations of 3.14159*2^x" 0.000000,0.000000  

set xrange [ 0 : 140 ] noreverse nowriteback
set yrange [ 0 : 7 ] noreverse nowriteback

set xtics 10.000000
set ytics 1.000000

plot "figure2-9.dat"  using 1:2 notitle with linespoints
#    EOF
