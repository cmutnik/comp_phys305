# plot file for Fourier series stuff
# Corey Mutnik 4/15
# mod from: PG 4/14/15
set title 'Fourier Series approximation'
set xlabel "time, s"
set ylabel "amplitude"
set nologscale y  # set these in case they were set log from another time
set nologscale x
set xr [0:1]
set yr [-1.5:1.5]
set grid


plot 'Fseries.dat' using 1:2 with lines title 'Sawtooth', \
     'Fseries.dat' using  1:3 with lines title 'Fourier approximation', \
    'Fseries.dat' u 1:($2-$3) w l t 'Residuals'
   


