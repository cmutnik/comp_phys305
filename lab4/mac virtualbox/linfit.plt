# Gnuplot script file for fitting and plotting linear data
# This file is called linfit.plt
set title ""   # insert your own title here
set xlabel "x values"
set ylabel "y=f(x)"
set autoscale x
f(x) = m*x + b;
m = 1.0 ; b = 1.0
fit f(x) 'data.dat' using 1:2:3 via m, b   # column three is for std errors
set pointsize 1.5
set bar small
plot    "data.dat" using 1:2:3 title 'Linear data' with yerrorbars, \
 f(x) 
