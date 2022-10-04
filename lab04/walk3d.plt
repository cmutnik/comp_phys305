# Gnuplot script file for plotting data
# This file is called walk3d.plt

set title "Three Dimensional Random Walk - Three Paths"
set xlabel 'X, steps' 
set ylabel 'Y, steps'  
set zlabel 'Z, steps' rotate by 90

set ticslevel  0
set origin 0,0
set size 1

set view 61, 135
set pointsize 0.95

#set xr [0:1000]
#set yr [-1:40]
set autoscale x
set autoscale y
set autoscale z
set nologscale y
set nologscale x
set nologscale z
#set grid
set key on
splot "walkpath3da.dat" u 2:3:4 t '100 steps' w lines lt rgb "red" ,\
"walkpath3db.dat" u 2:3:4 t '1000 steps' w lines lt rgb "blue" ,\
  "walkpath3dc.dat" u 2:3:4 t '10,000 steps' w lines lt rgb "green"