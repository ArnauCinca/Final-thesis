#! /bin/bash
N2=2
N4=4
N6=6
N10=10
N20=20
N100=100

a2=1.00 #$(echo "($N2-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a4=1.00 #$(echo "($N4-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a6=1.00 #$(echo "($N6-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a10=1.00 #$(echo "($N10-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a20=1.00 #$(echo "($N20-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a100=1.00 #$(echo "($N100-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
gnuplot -e "set terminal png size 2048,1024; set output 'dp$mf.png';
			set colors classic;
			set xlabel 'Distance of the center of masses';
			set ylabel 'n(x)';
			set samples 150;
			set title 'Density profiles with mf=$mf';
			plot
				 'dpX$N2-$a2.dat' w lines lw 2 title 'N = $N2, a = $a2', 
				 'dpX$N4-$a4.dat' w lines lw 2 title 'N = $N4, a = $a4',
				 'dpX$N6-$a6.dat' w lines lw 2 title 'N = $N6, a = $a6',
				 'dpX$N10-$a10.dat' w lines lw 2 title 'N = $N10, a = $a10',
				 'dpX$N20-$a20.dat' w lines lw 2 title 'N = $N20, a = $a20',
				 'dpX$N100-$a100.dat' w lines lw 2 title 'N = $N100, a = $a100'",
firefox dp$mf.png
