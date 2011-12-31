#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '9-12.ps'

set key top left 
set key box

set multiplot

# first one
# --------------------
set size .5,.5
set origin 0,0

set xlabel "n = number of initial points" 
set ylabel "execution time (in milliseconds) 
set title "Performance of Convex Hull variations on Uniform Distribution"

set xrange [ 512 : 131072 ] noreverse nowriteback
set yrange [ 0 : 400 ] noreverse nowriteback

plot 'figure9-12a.dat' using 1:2 index 0 title "QuickSort" with linespoints,'figure9-12a.dat' using 1:3 index 0 title "HeapSort" with linespoints,'figure9-12a.dat' using 1:4 index 0 title "Balanced" with linespoints,'figure9-12a.dat' using 1:5 index 0 title "Bucket" with linespoints,'figure9-12a.dat' using 1:6 index 0 title "Sorting Only" with linespoints

# second one
# --------------------
set size .5,.5
set origin .5,0

set xlabel "n = number of initial points" 
set ylabel "execution time (in milliseconds) 
set title "Performance of Convex Hull variations on Circle Distribution"

plot 'figure9-12a.dat' using 1:2 index 1 title "QuickSort" with linespoints,'figure9-12a.dat' using 1:3 index 1 title "HeapSort" with linespoints,'figure9-12a.dat' using 1:4 index 1 title "Balanced" with linespoints,'figure9-12a.dat' using 1:5 index 1 title "Bucket" with linespoints,'figure9-12a.dat' using 1:6 index 1 title "Sorting Only" with linespoints

# third one
# --------------------
set size .5,.5
set origin 0,.5

set xlabel "n = number of initial points" 
set ylabel "execution time (in milliseconds) 
set title "Performance of Convex Hull variations on Slice Distribution"

set xrange [ 128 : 2048 ] noreverse nowriteback
set yrange [ 0 : 57 ] noreverse nowriteback

plot 'figure9-12b.dat' using 1:2 title "QuickSort" with linespoints,'figure9-12b.dat' using 1:3 title "HeapSort" with linespoints,'figure9-12b.dat' using 1:4 title "Balanced" with linespoints,'figure9-12b.dat' using 1:5 title "Bucket" with linespoints,'figure9-12b.dat' using 1:6 title "Sorting Only" with linespoints

#EOF

