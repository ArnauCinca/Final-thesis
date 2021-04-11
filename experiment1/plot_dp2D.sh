#! /bin/bash
mf=$1
N=$2

a=$(echo "scale=2;($N-1) / $mf" | bc -l | sed 's/^\./0./')
gnuplot -e "set terminal png size 800,800; set output 'dp2D$mf.png'; 
			set view map;
			splot 'mf$mf/dp2D$N-$a.dat' with pm3d"
firefox dp2D$mf.png
