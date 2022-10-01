# Gnuplot script file for chirp 
set title "Chirp: cos(t^5)exp(-(t/4)^8)"  # NOTE: we can use exponents in titles!
set xlabel "time, s"
set ylabel "pressure amplitude, Pa"  # Pa == Pascals, SI unit of pressure
set xr [-8:8]
set yr [-28:28]
set nologscale y  # set these in case they were set log from another time
set nologscale x
set grid
set samples 10000  # USEFUL COMMAND: indicates to gnuplot that it should evaluate the function at 10000 evenly spaced points rather than the default 100 samples
set key off  # turn off the legend in the plot
A = 20.0;
plot A*(cos(x**5))*(exp(-(x/4)**8)) with lines