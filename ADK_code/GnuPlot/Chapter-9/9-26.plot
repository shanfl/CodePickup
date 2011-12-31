#!/usr/bin/gnuplot -persist
set terminal postscript monochrome "TimesNewRomanPSMT" 10
set output '9-26.ps'

set key 50,-50

set multiplot

# first one
# --------------------
set size .3,.175
set origin 0,.7

set xlabel ""
set ylabel ""
set noxtics
set ytics nomirror
set title  "KD-tree performance: Ratio=.23"

set xrange [ 0 : 15 ] noreverse nowriteback
set yrange [ 0 : 5500 ] noreverse nowriteback

plot 'figure9-26.dat' using 1:2 index 0 title "n=4096" with lines,'figure9-26.dat' using 1:3 index 0 title "n=8192" with lines,'figure9-26.dat' using 1:4 index 0 title "n=16384" with lines,'figure9-26.dat' using 1:5 index 0 title "n=32768" with lines,'figure9-26.dat' using 1:6 index 0 title "n=65536" with lines,'figure9-26.dat' using 1:7 index 0 title "n=131072" with lines

# never again.
set nokey

# second one
# --------------------
set size .3,.175
set origin .3,.7

set title "Brute-Force performance: Ratio=.23"

plot 'figure9-26.dat' using 1:2 index 1 title "n=4096" with lines,'figure9-26.dat' using 1:3 index 1 title "n=8192" with lines,'figure9-26.dat' using 1:4 index 1 title "n=16384" with lines,'figure9-26.dat' using 1:5 index 1 title "n=32768" with lines,'figure9-26.dat' using 1:6 index 1 title "n=65536" with lines,'figure9-26.dat' using 1:7 index 1 title "n=131072" with lines

# third one
# --------------------
set size .3,.175
set origin 0,.525

set xlabel ""
set title  "KD-tree performance: Ratio=.115"

set xrange [ 0 : 15 ] noreverse nowriteback
set yrange [ 0 : 5500 ] noreverse nowriteback

plot 'figure9-26.dat' using 1:2 index 2 title "n=4096" with lines,'figure9-26.dat' using 1:3 index 2 title "n=8192" with lines,'figure9-26.dat' using 1:4 index 2 title "n=16384" with lines,'figure9-26.dat' using 1:5 index 2 title "n=32768" with lines,'figure9-26.dat' using 1:6 index 2 title "n=65536" with lines,'figure9-26.dat' using 1:7 index 2 title "n=131072" with lines

# fourth one
# --------------------
set size .3,.175
set origin .3,.525

set xlabel ""
set title "Brute-Force performance: Ratio=.115"

plot 'figure9-26.dat' using 1:2 index 3 title "n=4096" with lines,'figure9-26.dat' using 1:3 index 3 title "n=8192" with lines,'figure9-26.dat' using 1:4 index 3 title "n=16384" with lines,'figure9-26.dat' using 1:5 index 3 title "n=32768" with lines,'figure9-26.dat' using 1:6 index 3 title "n=65536" with lines,'figure9-26.dat' using 1:7 index 3 title "n=131072" with lines


# ----------------------------------------------------------------------

# fifth one
# --------------------
set size .3,.175
set origin 0,.35

set xlabel ""
set title  "KD-tree performance: Ratio=.0575"

set xrange [ 0 : 15 ] noreverse nowriteback
set yrange [ 0 : 5500 ] noreverse nowriteback

plot 'figure9-26.dat' using 1:2 index 4 title "n=4096" with lines,'figure9-26.dat' using 1:3 index 4 title "n=8192" with lines,'figure9-26.dat' using 1:4 index 4 title "n=16384" with lines,'figure9-26.dat' using 1:5 index 4 title "n=32768" with lines,'figure9-26.dat' using 1:6 index 4 title "n=65536" with lines,'figure9-26.dat' using 1:7 index 4 title "n=131072" with lines

# sixth one
# --------------------
set size .3,.175
set origin .3,.35

set xlabel ""
set title "Brute-Force performance: Ratio=.0575"

plot 'figure9-26.dat' using 1:2 index 5 title "n=4096" with lines,'figure9-26.dat' using 1:3 index 5 title "n=8192" with lines,'figure9-26.dat' using 1:4 index 5 title "n=16384" with lines,'figure9-26.dat' using 1:5 index 5 title "n=32768" with lines,'figure9-26.dat' using 1:6 index 5 title "n=65536" with lines,'figure9-26.dat' using 1:7 index 5 title "n=131072" with lines

# ----------------------------------------------------------------------

# seventh one
# --------------------
set size .3,.175
set origin 0,.175

set xlabel ""
set title  "KD-tree performance: Ratio=0.02875"

set xrange [ 0 : 15 ] noreverse nowriteback
set yrange [ 0 : 5500 ] noreverse nowriteback

plot 'figure9-26.dat' using 1:2 index 6 title "n=4096" with lines,'figure9-26.dat' using 1:3 index 6 title "n=8192" with lines,'figure9-26.dat' using 1:4 index 6 title "n=16384" with lines,'figure9-26.dat' using 1:5 index 6 title "n=32768" with lines,'figure9-26.dat' using 1:6 index 6 title "n=65536" with lines,'figure9-26.dat' using 1:7 index 6 title "n=131072" with lines

# eighth one
# --------------------
set size .3,.175
set origin .3,.175

set xlabel ""
set title "Brute-Force performance: Ratio=0.02875"

plot 'figure9-26.dat' using 1:2 index 7 title "n=4096" with lines,'figure9-26.dat' using 1:3 index 7 title "n=8192" with lines,'figure9-26.dat' using 1:4 index 7 title "n=16384" with lines,'figure9-26.dat' using 1:5 index 7 title "n=32768" with lines,'figure9-26.dat' using 1:6 index 7 title "n=65536" with lines,'figure9-26.dat' using 1:7 index 7 title "n=131072" with lines

# ninth one
# --------------------
set size .3,.21
set origin 0,0

set xlabel "Number of dimensions in input data" 
set title  "KD-tree performance: Ratio=0.014375"

set xrange [ 0 : 15 ] noreverse nowriteback
set xtics nomirror
set yrange [ 0 : 5500 ] noreverse nowriteback

plot 'figure9-26.dat' using 1:2 index 8 title "n=4096" with lines,'figure9-26.dat' using 1:3 index 8 title "n=8192" with lines,'figure9-26.dat' using 1:4 index 8 title "n=16384" with lines,'figure9-26.dat' using 1:5 index 8 title "n=32768" with lines,'figure9-26.dat' using 1:6 index 8 title "n=65536" with lines,'figure9-26.dat' using 1:7 index 8 title "n=131072" with lines

# tenth one
# --------------------
set size .3,.21
set origin .3,0

set xlabel "Number of dimensions in input data" 
set xtics nomirror
set title "Brute-Force performance: Ratio=0.014375"

plot 'figure9-26.dat' using 1:2 index 9 title "n=4096" with lines,'figure9-26.dat' using 1:3 index 9 title "n=8192" with lines,'figure9-26.dat' using 1:4 index 9 title "n=16384" with lines,'figure9-26.dat' using 1:5 index 9 title "n=32768" with lines,'figure9-26.dat' using 1:6 index 9 title "n=65536" with lines,'figure9-26.dat' using 1:7 index 9 title "n=131072" with lines


#EOF





