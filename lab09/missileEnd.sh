for ((j=40 ; j<=70; j+= 5 ))
do   # "do ... done"takes the place of the curly braces
#NY with no drag, args are [theta0 (deg)][v0 (m/s)][wind v(m/s)][Alt(m)][drag on=1 off=0]
#  projectile $j 45.2 > SeaDragOn$j.dat
  tail -n 1 -q missile$j.dat >> MissileRange.dat  # collect the farthest distances
done