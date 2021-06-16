#! /bin/bash
mf=$1
N=$2

a=$(echo "($N-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')

./castin2D $N $a

gnuplot -e "set terminal png size 1024,1024 enhanced fontscale 2; 
			set output 'dp2D-Castin-$N-$a.png';
			set colors classic;
			set xlabel 'x - center of masses (position)';
			set ylabel 'y - center of masses (position)';
			set view map;
			splot 'dp2D-Castin-$N-$a.dat' with pm3d title ''"
firefox dp2D-Castin-$N-$a.png

			#set palette defined (-10 'red',0 'black', 10 'green');
