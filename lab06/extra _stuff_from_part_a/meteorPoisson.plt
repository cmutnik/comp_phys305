set title "Poisson distribution test"
set xlabel "meteors per minute, k"
set ylabel "Number of times k was observed"
# set the x and y limits for the plot
set xr [-1:16.0]
set yr [0.0:40.0]
# log scales not needed her, so comment out
#set logscale x
#set logscale y
#
set samples 100
# here is the Poisson function, with parameters N (total number of meteors)
#  and m, the mean value per minute
f(x) = N*(m**x)*(exp(-m)/gamma(x+1))
# we need starting guesses for the fit:
m=4;N=150;
# now actually do the fit from data file columns 1 and 2 for x,y, and
# fitting parameters m and N in the equation above
fit f(x) 'meteorpacks2.dat' using 1:2 via m , N
set pointsize 2
set bar small
plot    "meteorpacks2.dat" using 1:2:(sqrt($2+1))  title 'Meteors per minute' with yerrorbars, \
 N*(m**x)*(exp(-m)/gamma(x+1)) with lines title 'Poisson Fit'

