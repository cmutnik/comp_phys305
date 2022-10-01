# Gnuplot script file for frac err vs number of trials
set title "Fractional Error VS Number of Trials"
set xlabel "Number of Trials (N)"
set ylabel "Fractional Error"
set xr [-500:30000]
#set yr [0:0.35]
#set autoscale x
set autoscale y
set nologscale y  # set these in case they were set log from another time
set nologscale x
set grid
set key on
plot 'fracerr.dat' u 1:4 t '2D' w lines lt rgb "red" ,\
  'fracerr.dat' u 1:5 t '3D' w lines lt rgb "green"