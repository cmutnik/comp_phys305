## gnuplot script for making trajectory for apollo
## Corey Mutnik 4/7/15

set title "Apollo Rocket Path"
set xlabel "Position in x-direction (km)"
set ylabel "Position in y-direction (km)"
set autoscale x
set autoscale y
#set xr [-29000:-21000]
#set yr [-380000:-365000]
set nologscale x
set nologscale y
set key top left

plot '3days.dat' u ($9/1000):($10/1000) t 'Apollo' w l, \
      '3days.dat' u ($1/1000):($2/1000) t 'Earth' w l, \
      '3days.dat' u ($5/1000):($6/1000) t 'Moon' w l