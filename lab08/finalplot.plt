## gnuplot script for making drag = 0 plot
## Corey Mutnik 3/16/15

set title "Homerun Simulation"
set xlabel "Inital angle of ball (degrees)"
set ylabel "Range (m)"
set xr [20:70]
set yr [100:150]


plot 'range.dat' u 1:3 t 'Denver no wind' linestyle 3 w lp, \
      'headwind.dat' u 1:3 t 'New York 15mph tailwind' linestyle 8 w lp, \
#      'headwind.dat' u 1:3 t 'headwind in opposite direction of ball' linestyle 8 w lp, \
#       124.358 t 'minimum homerun distance' linestyle 4