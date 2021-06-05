#! /bin/bash
mf=$1
N2=2
N4=4
N10=10
N20=20
N100=100

a2=$(echo "($N2-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a4=$(echo "($N4-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a10=$(echo "($N10-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a20=$(echo "($N20-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a100=$(echo "($N100-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
gnuplot -e "set terminal png size 1024,1024 enhanced fontscale 2; 
			set output 'dp$mf.png';
			set colors classic;
			set xlabel 'x - center of masses (position)';
			set ylabel 'n(x)';
			set samples 250;
			McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a);
			set title '(D)';
			McGuire2(x) = exp(-2.0*abs(x)/(a/2.0))/(a/2.0);
			N=$N2; a=$a2;
			plot 
				 'mf$mf/dpX$N2-$a2.dat' w lines lw 4 title 'N = $N2, a = $a2', 
				 'mf$mf/dpX$N4-$a4.dat' w lines lw 4 title 'N = $N4, a = $a4',
				 'mf$mf/dpX$N10-$a10.dat' w lines lw 4 title 'N = $N10, a = $a10',
				 'mf$mf/dpX$N20-$a20.dat' w lines lw 4 title 'N = $N20, a = $a20',
				 'mf$mf/dpX$N100-$a100.dat' w lines lw 4 title 'N = $N100, a = $a100',
				 McGuire2(x) w points pt 2 ps 2 linecolor 'black' title 'Dimer',
				 McGuire(x) w points pt 1 ps 2 linecolor 'black' title 'Gross-Pitaevskii',
				 "
firefox dp$mf.png
