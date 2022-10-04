# gnuplot script for making sea level
# Corey Mutnik 3/16/15

set terminal pngcairo size 800,600 enhanced font 'Verdana,14'
set out 'finalplot2.png'
set title "Homerun Simulation: 40{/Symbol \260}"

set xlabel "Horizontal distance (m)"
set ylabel "Vertical distance (m)"
set key default
set xr [0:150]
set yr [0:60]

plot 'dragdeg40withw.dat' u 2:3 title 'NY 15mph wind' linestyle 1 w l, \
      'dragdeg40denver.dat' using 2:3 title 'Denver no wind' linestyle 2 w l
