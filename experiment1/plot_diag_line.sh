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
gnuplot -e "set terminal png size 1024,1024; set output 'dpDiag2$mf.png'; 
			McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a);
			McGuire2(x) = exp(-2*abs(x)/(a/2.0))/(a/2.0);
			N=$N2; a=$a2;
			plot 'mf$mf/dpDiag$N2-$a2.dat' w linespoints pt 7 ps 0 title 'N = $N2, a = $a2', 
				 'mf$mf/dpDiag$N4-$a4.dat' w linespoints pt 7 ps 0 title 'N = $N4, a = $a4',
				 'mf$mf/dpDiag$N6-$a6.dat' w linespoints pt 7 ps 0 title 'N = $N6, a = $a6',
				 'mf$mf/dpDiag$N10-$a10.dat' w linespoints pt 7 ps 0 title 'N = $N10, a = $a10',
				 'mf$mf/dpDiag$N20-$a20.dat' w linespoints pt 7 ps 0 title 'N = $N20, a = $a20',
				 'mf$mf/dpDiag$N100-$a100.dat' w linespoints pt 7 ps 0 title 'N = $N100, a = $a100',
				 McGuire2(x) linecolor 'grey30' lw 2 lt '.' title 'Dimer',
				 McGuire(x) linecolor 'black' lw 2 lt '-' title 'Gross-Pitaevskii'"
firefox dpDiag2$mf.png
