#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '2-3.ps'

set key top left 
set key box


# multiple graphs per image
set multiplot

# left one first
set size .5,.5
set origin 0,0

set xlabel "n" 
set ylabel "Execution Time (in ms)" 
set title "Sorted data"
set xrange [ 0 : 18000 ] noreverse nowriteback
set yrange [ 0 : 8 ] noreverse nowriteback

set xtics 5000.00
set ytics 1.0

plot 'figure2-3.dat' using 1:5 index 0 title "Sort1" with lines,'figure2-3.dat' using 1:3 index 0 title "Sort2" with lines,'figure2-3.dat' using 1:4 index 0 title "Sort3" with lines,'figure2-3.dat' using 1:2 index 0 title "Sort4" with lines

set size .5, .5
set origin .5,0

set xlabel "n" 
set ylabel "Execution Time (in ms)" 
set title "Sorted data with 16 elements out of position" 
set xrange [ 0 : 18000 ] noreverse nowriteback
set yrange [ 0 : 8 ] noreverse nowriteback

set xtics 5000.00
set ytics 1.0

plot 'figure2-3.dat' using 1:5 index 1 title "Sort1" with lines,'figure2-3.dat' using 1:3 index 1 title "Sort2" with lines,'figure2-3.dat' using 1:4 index 1 title "Sort3" with lines,'figure2-3.dat' using 1:2 index 1 title "Sort4" with lines
#    EOF
