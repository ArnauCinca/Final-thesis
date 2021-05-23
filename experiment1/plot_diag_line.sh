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
gnuplot -e "set terminal png size 1536,1024; set output 'dpDiag1_$mf.png'; 
			plot 'mf$mf/dpDiag1-$N2-$a2.dat' w linespoints pt 7 ps 0 title 'N = $N2, a = $a2', 
				 'mf$mf/dpDiag1-$N4-$a4.dat' w linespoints pt 7 ps 0 title 'N = $N4, a = $a4',
				 'mf$mf/dpDiag1-$N6-$a6.dat' w linespoints pt 7 ps 0 title 'N = $N6, a = $a6',
				 'mf$mf/dpDiag1-$N10-$a10.dat' w linespoints pt 7 ps 0 title 'N = $N10, a = $a10',
				 'mf$mf/dpDiag1-$N20-$a20.dat' w linespoints pt 7 ps 0 title 'N = $N20, a = $a20',
				 'mf$mf/dpDiag1-$N100-$a100.dat' w linespoints pt 7 ps 0 title 'N = $N100, a = $a100'"
gnuplot -e "set terminal png size 1536,1024; set output 'dpDiag2_$mf.png'; 
			plot 'mf$mf/dpDiag2-$N2-$a2.dat' w linespoints pt 7 ps 0 title 'N = $N2, a = $a2', 
				 'mf$mf/dpDiag2-$N4-$a4.dat' w linespoints pt 7 ps 0 title 'N = $N4, a = $a4',
				 'mf$mf/dpDiag2-$N6-$a6.dat' w linespoints pt 7 ps 0 title 'N = $N6, a = $a6',
				 'mf$mf/dpDiag2-$N10-$a10.dat' w linespoints pt 7 ps 0 title 'N = $N10, a = $a10',
				 'mf$mf/dpDiag2-$N20-$a20.dat' w linespoints pt 7 ps 0 title 'N = $N20, a = $a20',
				 'mf$mf/dpDiag2-$N100-$a100.dat' w linespoints pt 7 ps 0 title 'N = $N100, a = $a100'"
firefox dpDiag1_$mf.png &
firefox dpDiag2_$mf.png &
