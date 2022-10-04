## gnuplot script for making drag = 0 plot
## Corey Mutnik 3/16/15

set title "Homerun Simulation: range comparison"
set xlabel "Inital angle of ball (degrees)"
set ylabel "Range (m)"
set xr [20:70]
set yr [90:140]


#plot 'range.dat' u 1:4 title 'drag-free New York' linestyle 2 w lp, \

plot 'range.dat' u 1:2 t 'normal drag New York' linestyle 2 w lp, \
      'range.dat' u 1:3 t 'normal drag Denver' linestyle 3 w lp, \
       124.358 t 'minimum homerun distance New York' linestyle 4, \
       126.492 t 'minimum homerun distance Denver' linestyle 5