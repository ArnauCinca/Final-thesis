#! /bin/bash
mf=$1
N10=10
N20=20
N40=40
N45=45
N50=50
N70=70

a10=$(echo "($N10-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a20=$(echo "($N20-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a40=$(echo "($N40-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a45=$(echo "($N45-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a50=$(echo "($N50-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a70=$(echo "($N70-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2 lw 4; 
			set output 'dpDiag1_$mf.png';
			set ylabel 'δρ(x,-x)';
			set xlabel 'x - center of masses (position)';
			set key below;
			set colors classic;
			plot 
				 'mf$mf/dpDiag1-$N10-$a10.dat' w lines title 'N = $N10, a = $a10',
			 	 'mf$mf/dpDiag1-$N20-$a20.dat' w lines title 'N = $N20, a = $a20', 
				 'mf$mf/dpDiag1-$N40-$a40.dat' w lines title 'N = $N40, a = $a40',
				 'mf$mf/dpDiag1-$N45-$a45.dat' w lines title 'N = $N45, a = $a45',
				 'mf$mf/dpDiag1-$N50-$a50.dat' w lines title 'N = $N50, a = $a50',
				 'mf$mf/dpDiag1-$N70-$a70.dat' w lines title 'N = $N70, a = $a70'
	   "


gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2 lw 4; 
			set output 'dpDiag2_$mf.png'; 
			set ylabel 'δρ(x,x)';
			set key below;
			set xlabel 'x - center of masses (position)';
			set colors classic;
			plot
				 'mf$mf/dpDiag2-$N10-$a10.dat' w lines title 'N = $N10, a = $a10',
		       		 'mf$mf/dpDiag2-$N20-$a20.dat' w lines title 'N = $N20, a = $a20', 
				 'mf$mf/dpDiag2-$N40-$a40.dat' w lines title 'N = $N40, a = $a40',
				 'mf$mf/dpDiag2-$N45-$a45.dat' w lines title 'N = $N45, a = $a45',
				 'mf$mf/dpDiag2-$N50-$a50.dat' w lines title 'N = $N50, a = $a50',
				 'mf$mf/dpDiag2-$N70-$a70.dat' w lines title 'N = $N70, a = $a70'
	  "
firefox dpDiag1_$mf.png &
firefox dpDiag2_$mf.png &
