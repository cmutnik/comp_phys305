# plot file for plotting the time-independent schroedinger 2D potential well 'twoD.dat'
# for plotting x:y:psi(x,y)
#

set terminal pngcairo size 900,700 enhanced font 'Verdana,14'
set out 'xypotential.png'


set title "2D Potential Well"
set xlabel "x position"
set ylabel "y position"
set zlabel "Potential"
set nologscale y
set nologscale x
#set xr [0:1]
#set yr [-1:1.5]
set autoscale
#set dgrid3d 125,125
unset dgrid3d
set key off

splot 'twoD.dat' u 1:2:6
