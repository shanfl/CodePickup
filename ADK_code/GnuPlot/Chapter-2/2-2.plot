#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '2-2.ps'

set key top left
set key box

# two graphs one on top of the other...
set multiplot

# left one first
set size .5,.5
set origin 0,.5

set xlabel "Size of input set"
set ylabel "Execution Time (in microseconds)" 
set title "Average of 48 trials of sorting small data sets"

set xrange [ 0 : 128 ] noreverse nowriteback
set yrange [ 0 : 240 ] noreverse nowriteback

set xtics 16.0

plot 'figure2-2.dat' using 1:2 index 0 title "Sort1" with lines,'figure2-2.dat' using 1:3 index 0 title "Sort2" with lines,'figure2-2.dat' using 1:4 index 0 title "Sort3" with lines,'figure2-2.dat' using 1:5 index 0 title "Sort4" with lines

# now right one
set size .5, .5
set origin 0,0

set key top left
set key box

set xlabel "Size of input set"
set ylabel "Execution Time (in microseconds)" 
set title "Average of 48 trials of sorting small data sets"

set xrange [ 0 : 512 ] noreverse nowriteback
# 400 is sufficient, but for full range, show up to 1310
set yrange [ 0 : 1310 ] noreverse nowriteback

set xtics 32.0

plot 'figure2-2.dat' using 1:2 index 0 title "Sort1" with lines,'figure2-2.dat' using 1:3 index 0 title "Sort2" with lines,'figure2-2.dat' using 1:4 index 0 title "Sort3" with lines,'figure2-2.dat' using 1:5 index 0 title "Sort4" with lines

#    EOF
