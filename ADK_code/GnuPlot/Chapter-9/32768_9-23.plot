#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '9-23.ps'

set key top left 
set key box

set xlabel "Number of dimensions in input data" 
set ylabel "Execution time (in milliseconds)
set title "Compare performance of kd-tree to Brute Force Nearest Neighbor for 128 searches over n-32768 points"

set xrange [ 0 : 32 ] noreverse nowriteback
set yrange [ 0 : 2048 ] noreverse nowriteback

set xtics 1

plot 'figure9-23.dat' using 1:2 title "kd-build" with linespoints,'figure9-23.dat' using 1:3 title "kd-search" with linespoints,'figure9-23.dat' using 1:4 title "Brute Force search" with linespoints,'figure9-23.dat' using 1:5 title "Combined kd-build+kd-search" with linespoints

#EOF

