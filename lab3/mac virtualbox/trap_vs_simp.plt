# Gnuplot script file for chirp integration
set title "numerical integration of damped chirp function"
set xlabel "number of intervals"
set ylabel "integral of chirp function"
set xr [1:4002]
set yr [-2.5:2.5]
set nologscal y  # set these in case they were set log from another time
set logscale x
set grid
plot 'integ.dat' using 1:2 title "Trapezoidal method"  with lines,\
 'integ.dat' using 1:3 title "Simpson's method"  with lines 
