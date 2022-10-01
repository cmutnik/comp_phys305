# plot file for Fourier series stuff
# CM 4/14/15
set title 'Fourier Series approximation'
set xlabel "time, s"
set ylabel "amplitude"
set nologscale y  # set these in case they were set log from another time
set nologscale x
set xr [0:1]
set yr [-1.5:1.5]
set grid


plot 'Fseries2.dat' using 1:3 w l t 'Fourier approximation', \
	'Fseries.dat' using 1:2 with lines title 'Sawtooth'
