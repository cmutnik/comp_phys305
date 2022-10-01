# Gnuplot script for fitting line to unstable isotope decay
set title "Decay of Unstable Isotopes C10 and C11"
set xlabel "time (s)"
set ylabel "log of decays per time bin (5s)"

# set the x and y limits for the plot
set autoscale x
set autoscale y
#set xr [0:1000]

# log scales not needed her, so comment out
set nologscale x
set logscale y

#fit line
f(x) = (10*No)/(tau10/log(2))*exp(-(x)/(tau10/log(2)))+(10*No)/(tau11/log(2))*exp(-(x)/(tau11/log(2)));
No=1000;tau10=19;tau11=1221;

fit f(x) 'isotope2_bin5s.dat' u 1:6:(1+(sqrt($6+1))) via No, tau10, tau11;
set pointsize .9
set bar small
plot    "isotope2_bin5s.dat" using 1:6:(1+(sqrt($6+1))) title 'data' w yerrorbars,\
"isotope2_bin5s.dat" using 1:7 t 'remaining' w histeps,\
f(x) t 'fit'
