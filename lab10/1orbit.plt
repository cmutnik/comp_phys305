## gnuplot script for making trajectory for ~1 orbit
## Corey Mutnik 4/7/15

set title "Earth's Trajectory"
set xlabel "Position in x-direction (km)"
set ylabel "Position in y-direction (km)"
set autoscale x
set autoscale y
set nologscale x
set nologscale y


plot '1orbit.dat' u ($1/1000):($2/1000) t 'Earth'
##      '1orbit.dat' u ($5/1000):($6/1000) title 'Moon'