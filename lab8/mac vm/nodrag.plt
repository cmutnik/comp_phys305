## gnuplot script for making drag = 0 plot
## Corey Mutnik 3/16/15

set title "Homerun Simulation: drag-free, sea level"
set xlabel "Horizontal distance (m)"
set ylabel "Vertical distance (m)"
set autoscale x
set yr [0:80]
set bar small

plot 'drag0deg30.dat' u 2:3 title '30{/Symbol \260}' linestyle 1 w l, \
      'drag0deg35.dat' u 2:3 title '35{/Symbol \260}' linestyle 2 w l, \
      'drag0deg40.dat' u 2:3 title '40{/Symbol \260}' linestyle 3 w l, \
      'drag0deg45.dat' u 2:3 title '45{/Symbol \260}' linestyle 4 w l, \
      'drag0deg50.dat' u 2:3 title '50{/Symbol \260}' linestyle 5 w l, \
      'drag0deg55.dat' u 2:3 title '55{/Symbol \260}' linestyle 6 w l, \
      'drag0deg60.dat' u 2:3 title '60{/Symbol \260}' linestyle 7 w l