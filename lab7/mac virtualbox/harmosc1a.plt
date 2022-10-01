# Gnuplot script file for plotting data
# 
set title "Harmonic oscillator: Euler's solution"
set xlabel "time, s"
set ylabel "position, velocity, or energy"
set xr [0:50]
set yr [-10:10]
#set autoscale x
#set autoscale y
set bar small

#f(x) = sin(n*x)
#g(x) = cos(r*x)

#fit f(x) 'osc1.dat' using 1:2 via n
#fit g(x) 'osc1.dat' using 1:3 via r

#plot  "osc300.dat" using 1:2 title 'position' with lines,\
#      "osc300.dat" using 1:3 title 'velocity' with lines
plot 'osc300.dat' u 1:2 title 'x(t), Euler' w l, \
	'osc300.dat' u 1:3 title 'v(t), Euler' w l, \
	'osc300.dat' u 1:4 title 'x(t), true' w l, \
	'osc300.dat' u 1:5 title 'v(t), true'  w l, \
	'osc300.dat' u 1:7 title 'E' w l,\
#	'osc300.dat' u 1:6 title 'dE/E' w l, \
#	f(x) title 'x fit', \
#	g(x) title 'v fit'
      