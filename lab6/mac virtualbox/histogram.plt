set title "Histogram"
set xlabel "meteors per minute, k"
set ylabel "Number of times k was observed"
set xr [-1:16.0]
set yr [0.0:40.0]
set key off
plot "meteorpacks2.dat" using 1:2:(sqrt($2+1)) w boxes