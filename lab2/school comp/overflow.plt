# Gnuplot script file for plotting data
set title "Machine Overflow and Underflow"
set xlabel "number of terms N"
set ylabel "log Value"
set xrange [.5:155]
set yr [-55:55]
set nologscale y
set nologscale x
set pointsize 1.5
set bar small
set grid
plot "overflow.dat" using 2:(log10($4)) title 'Overflow' with linespoints,\
     "overflow.dat" using 2:(log10($6)) title 'Underflow' with linespoints



