# plot file for plotting the time-independent schroedinger wave in 2D 'twoD.dat'
# for plotting x:y:psi(x,y)
#

set terminal pngcairo size 900,700 enhanced font 'Verdana,14'
set out 'xypsi.png'


set title "2D Schrodinger Wave"
set xlabel "x position"
set ylabel "y position"
set zlabel "{/Symbol y}(x,y)" -1
set nologscale y
set nologscale x
#set xr [0:1]
#set yr [-1:1.5]
set autoscale
set dgrid3d 150,150
set key off

splot 'twoD.dat' u 1:2:3 w l
