# gnuplot script for making sea level
# Corey Mutnik 3/16/15

set terminal pngcairo size 900,700 enhanced font 'Verdana,14'
set out 'fixkey2.png'

set multiplot layout 2, 1 title 'Homerun Simulation: sea level' font 'Verdana,14'
set tmargin 2
#set title 'Drag-free'

unset xlabel
unset ylabel
set key default
set key font ',8'
set xr [0:220]
set yr [0:100]

plot 'drag0deg30.dat' u 2:3 title '30{/Symbol \260}' linestyle 1 w l, \
      'drag0deg35.dat' u 2:3 title '35{/Symbol \260}' linestyle 2 w l, \
      'drag0deg40.dat' u 2:3 title '40{/Symbol \260}' linestyle 3 w l, \
      'drag0deg45.dat' u 2:3 title '45{/Symbol \260}' linestyle 4 w l, \
      'drag0deg50.dat' u 2:3 title '50{/Symbol \260}' linestyle 5 w l, \
      'drag0deg55.dat' u 2:3 title '55{/Symbol \260}' linestyle 6 w l, \
      'drag0deg60.dat' u 2:3 title '60{/Symbol \260}' linestyle 7 w l


#set title 'With drag'
set xlabel "Horizontal distance (m)"
set ylabel "Vertical distance (m)"
set xr [0:220]
set yr [0:100]
set key default
set key font ',8'

plot 'dragdeg30.dat' u 2:3 t '30{/Symbol \260}' linestyle 1 w l, \
      'dragdeg35.dat' u 2:3 t '35{/Symbol \260}' linestyle 2 w l, \
      'dragdeg40.dat' u 2:3 t '40{/Symbol \260}' linestyle 3 w l, \
      'dragdeg45.dat' u 2:3 t '45{/Symbol \260}' linestyle 4 w l, \
      'dragdeg50.dat' u 2:3 t '50{/Symbol \260}' linestyle 5 w l, \
      'dragdeg55.dat' u 2:3 t '55{/Symbol \260}' linestyle 6 w l, \
      'dragdeg60.dat' u 2:3 t '60{/Symbol \260}' linestyle 7 w l
      
unset multiplot