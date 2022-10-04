#We will plot sin(x+t) in this gif animation
reset
set term gif animate
set output "animate.gif"
n=24    #n frames
dt=2*pi/n
set xrange [0:4*pi]
set yrange [-1:1]
set zrange [-1:1]
i=0
load "animation.gnuplot"
set out 
