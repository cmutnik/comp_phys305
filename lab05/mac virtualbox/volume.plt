# Gnuplot script file for frac err vs number of trials
set title "Volume of N-Hypersphere"
set xlabel "Number of Dimensions (N)"
set ylabel "Volume"
#set xr [-500:30000]
#set yr [0:0.35]
set autoscale x
set autoscale y
set nologscale y  # set these in case they were set log from another time
set nologscale x
set grid
set key on
plot 'volume300.dat' u 1:3 t '300 trials' w lines lt rgb "red" ,\
  'volume30000.dat' u 1:3 t '30,000 trials' w lines lt rgb "green"