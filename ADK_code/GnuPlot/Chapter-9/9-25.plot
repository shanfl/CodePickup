#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '9-25.ps'

set key top left 
set key box

set xlabel "d = number of dimensions" 
set ylabel "execution time (projected)
set title  "Projected performance of O(n^(1-1/d)) algorithm"

set xrange [0 : 42] noreverse nowriteback
set yrange [0 : 131072] noreverse nowriteback

plot 'figure9-25.dat' using 1:2 title "n=4096" with linespoints,'figure9-25.dat' using 1:3 title "n=8192" with linespoints,'figure9-25.dat' using 1:4 title "n=16384" with linespoints,'figure9-25.dat' using 1:5 title "n=32768" with linespoints,'figure9-25.dat' using 1:6 title "n=65536" with linespoints,'figure9-25.dat' using 1:7 title "n=131072" with linespoints

#EOF
