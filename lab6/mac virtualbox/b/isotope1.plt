set title "Unstable Isotope Decay"
set xlabel "time (s)"
set ylabel "decaying atoms per time bin (10s)"

# set the x and y limits for the plot
set autoscale x
set autoscale y

# log scales not needed her, so comment out
set nologscale x
set logscale y

#fit line
f(x) = (10*No)/(tau/log(2))*exp(-(x)/(tau/log(2)));
No=2000;tau=100;

fit f(x) 'isotope1.dat' u 1:2:(1+(sqrt($2+1))) via No, tau;
set pointsize .5
set bar small
plot    "isotope1.dat" using 1:2:(1+(sqrt($2+1))) title 'data' w yerrorbars,\
f(x) t 'fit via No, tau'


