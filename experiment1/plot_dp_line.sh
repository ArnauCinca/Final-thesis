#! /bin/bash
mf=$1
N2=2
N4=4
N6=6
N10=10
N20=20
N100=100

a2=$(echo "($N2-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a4=$(echo "($N4-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a6=$(echo "($N6-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a10=$(echo "($N10-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a20=$(echo "($N20-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a100=$(echo "($N100-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
gnuplot -e "set terminal png size 800,800; set output 'dp$mf.png'; 
			McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a);
			N=$N100; a=$a100;
			plot 'mf$mf/dp$N2-$a2.dat' w linespoints pt 7 ps 0 title 'N = $N2, a = $a2', 
				 'mf$mf/dp$N4-$a4.dat' w linespoints pt 7 ps 0 title 'N = $N4, a = $a4',
				 'mf$mf/dp$N6-$a6.dat' w linespoints pt 7 ps 0 title 'N = $N6, a = $a6',
				 'mf$mf/dp$N10-$a10.dat' w linespoints pt 7 ps 0 title 'N = $N10, a = $a10',
				 'mf$mf/dp$N20-$a20.dat' w linespoints pt 7 ps 0 title 'N = $N20, a = $a20',
				 'mf$mf/dp$N100-$a100.dat' w linespoints pt 7 ps 0 title 'N = $N100, a = $a100', 
				 McGuire(x)"
firefox dp$mf.png
