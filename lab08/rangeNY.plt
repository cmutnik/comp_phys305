## gnuplot script for making drag = 0 plot
## Corey Mutnik 3/16/15
set terminal pngcairo size 800,600 enhanced font 'Verdana,14'
set out 'rangeNY.png'
set title "Homerun Simulation: headwinds"
set xlabel "Inital angle of ball (degrees)"
set ylabel "Range (m)"
set xr [20:70]
set yr [70:170]


plot 'range.dat' u 1:2 t 'No wind' linestyle 2 w lp, \
      'headwind.dat' u 1:2 t 'tailwind' linestyle 6 w lp, \
      'headwind.dat' u 1:3 t 'headwind' linestyle 8 w lp, \
       124.358 t 'minimum homerun distance' linestyle 4