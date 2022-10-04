# Gnuplot script file for randomwalk
set title "Least-Squares Fit Graph"
set xlabel "number of steps"
set ylabel "distance"
#set xr [0:1000]
#set yr [-1:40]
set autoscale x
set autoscale y
set nologscal y  # set these in case they were set log from another time
set nologscale x
set grid
#set key off	# eliminates key in top right of graph
f(x) = x**a
fit f(x) 'walk.dat' u 1:2 via a
plot 'walk.dat' using 1:2:3 title 'walk' with yerrorbars,\
f(x) title 'fitline' linetype -1