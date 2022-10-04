# plot file for plotting the time-independent schroedinger wave in 2D 'twoD.dat'
# for plotting x:y:psi(x,y)^2
#

set terminal pngcairo size 900,700 enhanced font 'Verdana,14'
set out 'xypsisquared_mesh.png'


set title "Normalized |{/Symbol y}(x,y)|^2"
set xlabel "x position"
set ylabel "y position"
set zlabel "|{/Symbol y}(x,y)|^2" -1
set nologscale z
set nologscale y
set nologscale x
#set xr [0:1]
#set yr [-1:1.5]
set autoscale
set dgrid3d 150,150
#unset dgrid3d
set key off

splot 'twoD.dat' u 1:2:4 w l
