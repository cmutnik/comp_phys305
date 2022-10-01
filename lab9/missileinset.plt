 # Gnuplot script file for plotting position data inset with vel data

#set term png small
set output 'missileinset.png'

set multiplot
# largerscale plot
set size 1,1
set origin 0,0
set title 'Angle dependent missile trajectory' 
set xlabel "Ballistic range (km)"
set ylabel "Maximum vertical height (m)"

# incase log scale was previously set
#set nologscale x
#set nologscale y

set xr [0:1100]
set yr [(-100):(800)]
#set pointsize 1
set bar small
set key on
# splot Earth's curved surface
Re = 6335437.0;
f(x) = sqrt((Re/1000)**2-x**2)-Re/1000;
plot    f(x) w lines

filename(n) = sprintf("missile%d.dat",n)
ftitle(n) = sprintf("%d{/Symbol \260}",n)
plot for [i=40:70:5] filename(i) u ($2/1000):($3/1000) title ftitle(i) w l, f(x) w l title 'Earth surface' 




# use inset graph for zoomed portion
set size 0.5,0.3
set origin 0.097,0.61
set nologscale x
set nologscale y
set xr[999:1000]
set yr [-78.7:-79.5]
unset key
unset title
unset xlabel
unset ylabel

# splot Earth's curved surface
Re = 6335437.0;
f(x) = sqrt((Re/1000)**2-x**2)-Re/1000;
plot    f(x) w lines

filename(n) = sprintf("missile%d.dat",n)
ftitle(n) = sprintf("%d{/Symbol \260}",n)
plot for [i=45:50:5] filename(i) u ($2/1000):($3/1000) title ftitle(i) w l, f(x) w l title 'Earth surface' 

unset multiplot

