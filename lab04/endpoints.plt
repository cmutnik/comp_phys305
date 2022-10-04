# Gnuplot script file for walk endpoints
set title "Endpoints"
set xlabel "x coordinate"
set ylabel "y coordinate"
#set xr [0:1000]
#set yr [-1:40]
set autoscale x
set autoscale y
set nologscal y  # set these in case they were set log from another time
set nologscale x
set grid
#set key off	# eliminates key in top right of graph
set pointsize .5
set style line 1 lc rgb 'black' pt 9   			# makes points triangles
plot 'endpoints.dat' using 1:2 title 'endpoint'