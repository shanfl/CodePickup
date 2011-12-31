#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '2-4.ps'

set ylabel "Execution Time (in ms)" 
set title "Nearly sorted data where n/4 entries are\n randomly shifted to be 4 away from their proper position" 

set key top left
set key box

set xrange [ 0 : 18000 ] noreverse nowriteback
set yrange [ 0 : 16 ] noreverse nowriteback

set xtics 5000.00
set ytics 1.0

plot 'figure2-4.dat' using 1:2 title "Sort1" with lines,'figure2-4.dat' using 1:3 title "Sort2" with lines,'figure2-4.dat' using 1:4 title "Sort3" with lines,'figure2-4.dat' using 1:5 title "Sort4" with lines
#    EOF
