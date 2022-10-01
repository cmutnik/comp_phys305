
# Gnuplot script file for plotting data
# This file is called array.plt
set title 'portion 0s-10000s'
set xlabel 'time in seconds'
set ylabel '1 represents a meteor seen'
set xr [0:10000]
set yr [-0.5:1.5]
set key off
plot "array01.dat" using 1:3 with points