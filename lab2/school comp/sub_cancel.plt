# Gnuplot script file for plotting data
set title "Subtraction Cancellation"
set xlabel "log N"
set ylabel "log Fractional Error"
#set xrange [0:0.00000001]
#set yr [0:1100000]
set autoscale y
set autoscale x
set nologscale y
set nologscale x
set pointsize 2
set bar small
set grid
plot "sub_cancel.dat" using (log10($1)):(log10($8)) title 'frec err' with linespoints


