# Gnuplot script file for plotting data
# 
set title "Harmonic oscillator: RK4 method"
set xlabel "time, s"
set ylabel "position, velocity, or energy"
set xr [0:50]
set yr [-3:3]
set bar small

plot 'oscRK4_1.dat' u 1:2 title 'x(t), RK2' linestyle 1 w l, \
	'oscRK4_1.dat' u 1:3 title 'v(t), RK2' linestyle 2 w l, \
	'oscRK4_1.dat' u 1:4 title 'x(t), true' linestyle 3 w l, \
	'oscRK4_1.dat' u 1:5 title 'v(t), true' linestyle 4 w l, \
	'oscRK4_1.dat' u 1:7 title 'Energy' linestyle 5 w l
	