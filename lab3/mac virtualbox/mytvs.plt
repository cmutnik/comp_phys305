# Gnuplot script file for chirp integration
set title "Chirp Function: cos((wt)^3)exp(-(t/4)^8)"
set xlabel "Time (s)"
set ylabel "Integration of Energy/Area (J/m^2)"
set xr [-6:6]
set yr [-1:4]
set nologscal y  # set these in case they were set log from another time
set nologscale x
set grid
plot 'myinteg4.dat' using 1:2 title "Trapezoidal method"  with lines