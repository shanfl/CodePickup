#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '7-7.ps'

set key top left 
set key box

set multiplot
#top-left one first

set size .5,.5
set origin 0,0

set xlabel "n = ply depth" 
set ylabel "search tree size" 
set title "Comparing search tree size from three initial positions (N1, N2, N3)"
set xrange [ 0 : 30 ] noreverse nowriteback
set yrange [ 0 : 35000 ] noreverse nowriteback

set xtics 5
set ytics 5000.00

plot 'figure7-7.dat' using 1:2 title "N1" with linespoints,'figure7-7.dat' using 1:3 title "N2" with linespoints,'figure7-7.dat' using 1:4 title "N3" with linespoints

set size .5,.5
set origin .5,0

set xlabel "n = ply depth" 
set ylabel "search tree size" 
set title "Comparing search tree size from three initial positions (N1, N2, N3)"
set xrange [ 0 : 30 ] noreverse nowriteback
set yrange [ 0 : 35000 ] noreverse nowriteback

set xtics 5
set ytics 5000.00

trend1(x)=0.3429*x**2.6978
trend2(x)=.2403*x**3.2554
trend3(x)=0.2814*x**3.044

plot trend1(x) title "trend-N1" with lines,trend2(x) title "trend-N2" with lines,trend3(x) title "trend-N3" with lines

#EOF
