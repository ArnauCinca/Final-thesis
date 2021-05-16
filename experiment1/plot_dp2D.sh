#! /bin/bash
mf=$1
N=$2

a=$(echo "($N-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
gnuplot -e "set terminal png size 800,800; set output 'dp2D$mf-$N.png';
			set view map;
			splot 'mf$mf/dp2D$N-$a.dat' with pm3d title ''"
firefox dp2D$mf-$N.png

			#set palette defined (-10 'red',0 'black', 10 'green');
