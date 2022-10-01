# velocity vs time graph plot file

# Corey Mutnik 4/6/15


set title 'Velocity VS Time' 
set xlabel "Time (s)"
set ylabel "Velocity (m/s)"
#set yr [0:1100]
set autoscale y
set autoscale x
set pointsize 1.5
set bar small
set key bottom right
set nologscale x

filename(n) = sprintf("missile%d.dat",n)
ftitle(n) = sprintf("%d{/Symbol \260}",n)
plot for [i=40:70:5] filename(i) u ($1):($9) title ftitle(i) w l

