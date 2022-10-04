set title "Poisson probability distribution: P(k:{/Symbol m}) = {/Symbol m}^k e^{-{/Symbol m}} / k!"
set xlabel "integral value k"
set ylabel "Probability to observe k"
# set the x and y limits for the plot
set xr [0:12.0]
set yr [0:*]
# log scales not needed her, so comment out
#set logscale x
#set logscale y
# 
#
set key
set samples 13
mu01=0.1; mu1=1; mu2=2.; mu3=3; mu4=4;
mu5=5; mu6=6;
set grid
plot 0.5**x *exp(-0.5)/gamma(x+1) title '{/Symbol m} = 0.5' with histeps,\
2**x *exp(-2)/gamma(x+1) title '{/Symbol m} = 2   ' with histeps,\
4**x *exp(-4)/gamma(x+1) title '{/Symbol m} = 4   ' with histeps,\
6**x *exp(-6)/gamma(x+1) title '{/Symbol m} = 6   ' with histeps
