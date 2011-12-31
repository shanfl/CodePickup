#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '9-23.ps'

set key top left 
set key box

set multiplot

# first one
# --------------------
set size .5,.5
set origin 0,.5

set xlabel "Number of dimensions in input data" 
set xtics 2
set ylabel "Execution time (in milliseconds)
set title "Performance of Nearest Neighbor for 128 searches over n=4,096 points"

set xrange [ 0 : 32 ] noreverse nowriteback
set yrange [ 0 : 200 ] noreverse nowriteback

plot '4096_figure9-23.dat' using 1:2 title "kd-build" with lines,'4096_figure9-23.dat' using 1:3 title "kd-search" with lines,'4096_figure9-23.dat' using 1:4 title "Brute Force search" with linespoints

# second one
# --------------------
set size .5,.5
set origin 0,0

set xlabel "Number of dimensions in input data" 
set xtics 2
set ylabel "Execution time (in milliseconds)
set title "Performance of Nearest Neighbor for 128 searches over n=131,072 points"

set xrange [ 0 : 32 ] noreverse nowriteback
set yrange [ 0 : 7000 ] noreverse nowriteback

plot '131072_figure9-23.dat' using 1:2 title "kd-build" with lines,'131072_figure9-23.dat' using 1:3 title "kd-search" with lines,'131072_figure9-23.dat' using 1:4 title "Brute Force search" with linespoints


#EOF

