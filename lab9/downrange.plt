# "downrange" vs time graph plot file

# Corey Mutnik 4/6/15


set title 'Distance VS Time' 
set xlabel "Time (s)"
set ylabel "Distance Covered (km)"
#set yr [0:1100]
set autoscale y
set autoscale x
set pointsize 1.5
set bar small
set key top left
set nologscale x

filename(n) = sprintf("missile%d.dat",n)
ftitle(n) = sprintf("%d{/Symbol \260}",n)
plot for [i=40:70:5] filename(i) u ($1):($2/1000) title ftitle(i) w l

