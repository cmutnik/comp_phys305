# Gnuplot script file for plotting data
set title "Sum of Series as a function of Iterations"
set xlabel "Iteration count"
set ylabel "Values of sum"
#set xrange [0:25]
#set yr [-2000:2000]
set autoscale y
set autoscale x
set nologscale y
set nologscale x
set pointsize 2
set bar small
set grid
plot "valuez_5.dat" using 1:6 title 'z=5' with linespoints, "valuez_20.dat" using 1:6 title 'z=20' with linespoints
