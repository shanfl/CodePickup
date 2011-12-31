#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '2-5.ps'

set key top left 
set key box

# multiple graphs per image
set multiplot

# top-left one first
set size .5,.5
set origin 0,0

set xlabel "n = number of digits" 
set ylabel "Execution Time (in ms)" 
set title "Comparing add on Desktop PC"
set xrange [ 0 : 33000 ] noreverse nowriteback
set yrange [ 0 : 12500 ] noreverse nowriteback

set xtics 5000.00
set ytics 1000.00

plot 'figure2-5.dat' using 1:11 title "pc.add.Ox" with linespoints,'figure2-5.dat' using 1:12 title "pc.add.java" with linespoints,'figure2-5.dat' using 1:24 title "pc.add.none" with linespoints

# top-right
set size .5,.5
set origin .5,0

set xlabel "n = number of digits" 
set ylabel "Execution Time (in ms)" 
set title "Comparing add on High-end Computer"
set xrange [ 0 : 33000 ] noreverse nowriteback
set yrange [ 0 : 5000 ] noreverse nowriteback

set xtics 5000.00
set ytics 1000.00

plot 'figure2-5.dat' using 1:2 title "add.O1" with linespoints,'figure2-5.dat' using 1:3 title "add.O2" with linespoints,'figure2-5.dat' using 1:4 title "add.O3" with linespoints,'figure2-5.dat' using 1:6 title "add.none" with linespoints,'figure2-5.dat' using 1:8 title "add.java" with linespoints


# bottom-left
set size .5,.5
set origin 0,.5

set xlabel "n = number of digits" 
set ylabel "Execution Time (in ms)" 
set title "Comparing last on Desktop PC"
set xrange [ 0 : 33000 ] noreverse nowriteback
set yrange [ 0 : 12500 ] noreverse nowriteback

set xtics 5000.00
set ytics 1000.00

plot 'figure2-5.dat' using 1:22 title "pc.last.Ox" with linespoints,'figure2-5.dat' using 1:23 title "pc.last.java" with linespoints,'figure2-5.dat' using 1:25 title "pc.last.none" with linespoints

# bottom-right
set size .5,.5
set origin .5,.5

set xlabel "n = number of digits" 
set ylabel "Execution Time (in ms)" 
set title "Comparing last on High-end Computer"
set xrange [ 0 : 33000 ] noreverse nowriteback
set yrange [ 0 : 5000 ] noreverse nowriteback

set xtics 5000.00
set ytics 1000.00

plot 'figure2-5.dat' using 1:13 title "last.O1" with linespoints,'figure2-5.dat' using 1:14 title "last.O2" with linespoints,'figure2-5.dat' using 1:15 title "last.O3" with linespoints,'figure2-5.dat' using 1:17 title "last.none" with linespoints,'figure2-5.dat' using 1:19 title "last.java" with linespoints
#    EOF
