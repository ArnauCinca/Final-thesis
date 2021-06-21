#! /bin/bash
mf=$1
N2=3
N4=4
N10=8
N20=10
N100=20

a2=$(echo "($N2-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a4=$(echo "($N4-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a10=$(echo "($N10-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a20=$(echo "($N20-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a100=$(echo "($N100-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')

gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2; 
			set output 'dpX$mf.png';
			set xlabel 'x';
			set ylabel 'n(x)';
			set colors classic;
			set title 'Density profiles(X) with mf=$mf';
                        plot  
				 'mf$mf/dpX$N2-$a2.dat' w lines lw 4 title 'N = $N2, a = $a2', 
				 'mf$mf/dpX$N4-$a4.dat' w lines lw 4 title 'N = $N4, a = $a4',
				 'mf$mf/dpX$N10-$a10.dat' w lines lw 4 title 'N = $N10, a = $a10',
				 'mf$mf/dpX$N20-$a20.dat' w lines lw 4 title 'N = $N20, a = $a20',
				 'mf$mf/dpX$N100-$a100.dat' w lines lw 4 title 'N = $N100, a = $a100'
	"
  
gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2; 
			set output 'dpY$mf.png';
			set xlabel 'y';
			set ylabel 'n(x)';
			set colors classic;
			set title 'Density profiles(Y) with mf=$mf';
			plot 
				 'mf$mf/dpY$N2-$a2.dat' w lines lw 4 title 'N = $N2, a = $a2', 
				 'mf$mf/dpY$N4-$a4.dat' w lines lw 4 title 'N = $N4, a = $a4',
				 'mf$mf/dpY$N10-$a10.dat' w lines lw 4 title 'N = $N10, a = $a10',
				 'mf$mf/dpY$N20-$a20.dat' w lines lw 4 title 'N = $N20, a = $a20',
				 'mf$mf/dpY$N100-$a100.dat' w lines lw 4 title 'N = $N100, a = $a100'
				" 





gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2; 
			set output 'dpZ$mf.png';
			set xlabel 'z - center of masses';
			set ylabel 'n(x)';
			set xrange [-0.5:0.5];
			set colors classic;
			set title 'Density profiles (Z) with mf=$mf';
                        plot 
				 'mf$mf/dpZ$N2-$a2.dat' w lines lw 4 title 'N = $N2, a = $a2', 
				 'mf$mf/dpZ$N4-$a4.dat' w lines lw 4 title 'N = $N4, a = $a4',
				 'mf$mf/dpZ$N10-$a10.dat' w lines lw 4 title 'N = $N10, a = $a10',
				 'mf$mf/dpZ$N20-$a20.dat' w lines lw 4 title 'N = $N20, a = $a20',
				 'mf$mf/dpZ$N100-$a100.dat' w lines lw 4 title 'N = $N100, a = $a100'
		"



firefox dpX$mf.png dpY$mf.png dpZ$mf.png
