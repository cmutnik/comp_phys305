
# Gnuplot script file for plotting data
# This file is called pond.plt
set title 'Monte Carlo Integration of 3D Sphere'
set xlabel 'X distance'
set ylabel 'Y distance'
set zlabel 'Z distance' font "Helvetica, 5"
set xr [-1.05:1.05]
set yr [-1.05:1.05]
set zr [-1.05:1.05]
set ticslevel  0
set origin 0,0
set size 1
set pointsize 0.95
set nokey 
splot "pond3.dat" index 0 using 1:2:3 with points,\
      "pond3.dat" index 1 using 1:2:3 with points,\
      "pond3.dat" index 2 using 1:2:3 with points
      