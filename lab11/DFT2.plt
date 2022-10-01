# gnuplot script for pulsarpectrum

set title 'Pulsar Spectrum' font 'sans,20'
set xlabel "frequency (Hz)" font 'sans,20'
set ylabel "log(Fourier magnitude)" font 'sans,20'
set logscale y  # set these in case they were set log from another time
set nologscale x
set xr [2.0e6:5.0e6]
#set autoscale x
set autoscale y
set grid

set key off
plot 'pulsarspectrum2.dat' u 1:(sqrt(($3**2)+($2**2))) w boxes lc rgb 'red'

##plot 'pulsarspectrum.dat' u 1:(sqrt($3**2)) w boxes t 'Im' lc rgb 'blue', \
##	'pulsarspectrum.dat' u 1:(sqrt($2**2)) w boxes t 'Re' lc rgb 'red'
##
##'cellphonespectrum.dat' u 1:(sqrt(($3**2)+($2**2))) w boxes t 'sqrt(Re^2 + Im^2)' lc rgb 'green', \
