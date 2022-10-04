# Corey Mutnik 4/6/15
# plot file for No-Dong missile trajectory

set title 'Angle dependent missile trajectory' 
set xlabel "Ballistic range (km)"
set ylabel "Maximum vertical height (m)"
set yr [-100:700]
set xr [0:1000]
set pointsize 1.5
set bar small
set key

# splot Earth's curved surface
Re = 6335437.0;
f(x) = sqrt((Re/1000)**2-x**2)-Re/1000;
plot    f(x) w lines

filename(n) = sprintf("missile%d.dat",n)
ftitle(n) = sprintf("%d{/Symbol \260}",n)
plot for [i=40:70:5] filename(i) u ($2/1000):($3/1000) title ftitle(i) w l, f(x) w l title 'Earths surface' 


