# Carbon 14 decay fitting
# corey mutnik modified from P. Gorham for Physics 305 3/10/14
set title "Decay of C14"
set xlabel "Counts per minute"
set ylabel "Occurances of counts per minute"
# set the x and y limits for the plot
#set xr [0:12.0]
set autoscale x
set autoscale y
set nologscale x
set nologscale y
#
set samples 100
# here is the Poisson function, with parameters N
#  and m, the mean value per minute
f(x) = N*(m**x)*(exp(-m)/gamma(x+1))
#m1 = 6.0*15.0*exp(-21600.0/(5730./log(2)));
#m2 = 0.2*15.0*exp(-1985.0/(5730./log(2)));
#m3 = 0.2*15.0*exp(-700.0/(5730./log(2)));
#m4 = 0.01*15.0*exp(-4700.0/(5730./log(2)));

#g1(x) = N*(m1**x)*(exp(-m1)/gamma(x+1))
#g2(x) = N*(m2**x)*(exp(-m2)/gamma(x+1))
#g3(x) = N*(m3**x)*(exp(-m3)/gamma(x+1))
#g4(x) = N*(m4**x)*(exp(-m4)/gamma(x+1))

# we need starting guesses for the fit:
m=0.1;
N=10000;

# now actually do the fit from data file columns 1 and 2 for x,y, and
# fitting parameters m and N in the equation above
# NOTE: need to edit for the correct file and fitting function for each sample
fit f(x) 'sample2_1985.dat' using 1:2:(1+sqrt($2+1)) via m, N
set pointsize 1.25
set bar small
plot    "sample2_1985.dat" using 1:2:(1+sqrt($2+1)) title 'decays per minute (1985yrs)' with yerrorbars, \
"sample2_700.dat" using 1:2:(1+sqrt($2+1)) title 'decays per minute (700yrs)' with yerrorbars, \
f(x) with histeps title 'Poisson Fit'
#  f(x) with histeps title 'Poisson Fit',\
# g2(x) with histeps title 'Poisson actual, 1985 yrs',\
# g3(x) with histeps title 'Poisson actual, 700 yrs'
