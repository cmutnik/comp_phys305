## gnuplot script for making trajectory for ~1 orbit
## Corey Mutnik 4/7/15

set title "Apollo's Trajectory"
set xlabel "Position in x-direction (km)"
set ylabel "Position in y-direction (km)"
set autoscale x
set autoscale y
set nologscale x
set nologscale y


plot '3days.dat' u ($9/1000):($10/1000) t 'Apollo' w l