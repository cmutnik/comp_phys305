#!/bin/bash
#  
# files for Missile study  4/1/14 P. Gorham
#  
# Type code line below in terminal to make this executable file,
# then click "Missile.sh" file in file directory to make all the data files
#chmod a+x Missile.sh


rm missile*.dat;  # get rid of old files first

for ((j=30 ; j<=70; j+= 5 ))
do
# 
  missileSoln $j missile$j.dat;
done

