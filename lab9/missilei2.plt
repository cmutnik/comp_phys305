# Corey Mutnik 4/6/15
# plot file for No-Dong missile trajectory

set title 'Maximum range comparison' 
set xlabel "Ballistic range (km)"
set ylabel "Maximum vertical height (m)"
set xr [1001.9:1002.5]
set yr [-79.95:-79.45]
#set autoscale x
#set autoscale y
set pointsize 1.5
set bar small
set key top right

# splot Earth's curved surface
Re = 6335437.0;
f(x) = sqrt((Re/1000)**2-x**2)-Re/1000;
plot    f(x) w lines

filename(n) = sprintf("missile%d.dat",n)
ftitle(n) = sprintf("%d{/Symbol \260}",n)
plot for [i=45:50:5] filename(i) u ($2/1000):($3/1000) title ftitle(i) w l, f(x) w l title 'Earths surface' 


