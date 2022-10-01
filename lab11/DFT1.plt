# gnuplot script for cellphonespectrum

set title 'Cellphone Spectrum' font 'sans,20'
set xlabel "frequency (Hz)" font 'sans,20'
set ylabel "amplitude (V)" font 'sans,20'
set nologscale y  # set these in case they were set log from another time
set nologscale x
set xr [2.35e9:2.5e9]
set autoscale y
set grid


plot 'cellphonespectrum.dat' u 1:(sqrt($3**2)) w boxes t 'Im' lc rgb 'blue', \
	'cellphonespectrum.dat' u 1:(sqrt($2**2)) w boxes t 'Re' lc rgb 'red'
