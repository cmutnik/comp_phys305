# gnuplot script for crabspectrum

set title 'Crab Pulsar Spectrum' font 'sans,20'
set xlabel "frequency (Hz)" font 'sans,20'
set ylabel "log(Fourier magnitude)" font 'sans,20'
#set ylabel "amplitude" font 'sans,20'
set logscale y  # set these in case they were set log from another time
set nologscale x
#set xr [2.0e6:5.0e6]
set autoscale x
set autoscale y
set grid

set key off
plot 'crabspectrum.dat' u 1:(sqrt(($3**2)+($2**2))) w boxes lc rgb 'red'

