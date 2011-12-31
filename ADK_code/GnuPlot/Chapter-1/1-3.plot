#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '1-3.ps'

# recommended to set size and origin before entering multimode
set size 1,1
set origin 0,0

set multiplot

set nokey



# upper left: small allocate
# --------------------------------------------------
set size 0.5,0.5
set origin 0,.5

set title "Time to allocate 4,096 chunks of size n for small n" 0.000000,0.000000

set xlabel "chunk size n" 0.0,0.0  
set ylabel "Execution Time (in ms.)" 0.0,0.0  

set xrange [ 0 : 128 ] noreverse nowriteback
set yrange [ 0 : 1024 ] noreverse nowriteback
plot 'figure1-3.dat' using 1:2 title "allocations" with lines



# upper right: large allocate
# --------------------------------------------------
set size 0.5,0.5
set origin .5,.5

set title "Time to allocate 4,096 chunks of size n for large n" 0.000000,0.000000

set xlabel "chunk size n" 0.0,0.0  
set ylabel "Execution Time (in ms.)" 0.0,0.0  

set xrange [ 0 : 2048 ] noreverse nowriteback
set yrange [ 0 : 16384 ] noreverse nowriteback
plot 'figure1-3.dat' using 1:2 title "allocations" with lines


# get keys back int
set key top left
set key box


# lower left: small free
# --------------------------------------------------
set size 0.5,0.5
set origin 0,0

set title "Time to deallocate chunks of size n for small n" 0.000000,0.000000  

set xlabel "chunk size n" 0.0,0.0  
set ylabel "Execution Time (in ms.)" 0.0,0.0  

set xrange [ 0 : 128 ] noreverse nowriteback
set yrange [ 0 : 1024] noreverse nowriteback

plot 'figure1-3.dat' using 1:3 title "freeUp" with lines, 'figure1-3.dat' using 1:4 title "freeDown" with points,'figure1-3.dat' using 1:5 title "freeScattered" with lines


# lower right: large free
# --------------------------------------------------
set size 0.5,0.5
set origin .5,0

set title "Time to deallocate chunks of size n for large n" 0.000000,0.000000  

set xlabel "chunk size n" 0.0,0.0  
set ylabel "Execution Time (in ms.)" 0.0,0.0  

set xrange [ 0 : 2048 ] noreverse nowriteback
set yrange [ 0 : 16384 ] noreverse nowriteback

plot 'figure1-3.dat' using 1:3 title "freeUp" with lines, 'figure1-3.dat' using 1:4 title "freeDown" with points,'figure1-3.dat' using 1:5 title "freeScattered" with lines

unset multiplot
reset

#    EOF
