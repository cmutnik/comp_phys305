# Gnuplot script file for plotting data
# This file is called walk3d.plt

set title
set xlabel 'X, steps' 
set ylabel 'Y, steps'  
set zlabel 'Z, steps' rotate by 90 

set ticslevel  0

set origin 0,0
set size 1

set view 55,25
set pointsize 0.95

set nokey 
splot "walkpath3dA.dat" using 2:3:4 with lines,\
  "walkpath3dB.dat" using 2:3:4 with lines,\
  "walkpath3dC.dat"  using 2:3:4 with lines,\
  "walkpath3dD.dat"  using 2:3:4 with lines

