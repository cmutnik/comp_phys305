# Gnuplot script file for chirp integration
set title "Integral of Exponential (theoretical - actual)"
set xlabel "number of intervals"
set ylabel "numerical error magnitude"
set xr [0:1000]
set yr [-1:4]
set nologscal y  # set these in case they were set log from another time
set nologscale x
set grid
plot 'integ.dat' using 1:2 title "Trapezoidal method"  with lines,\
 'integ.dat' using 1:3 title "Simpson's method"  with lines 
