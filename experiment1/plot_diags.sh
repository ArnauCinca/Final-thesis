#! /bin/bash
mf=$1
N=$2

a=$(echo "($N-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
gnuplot -e "set terminal png size 1024,1024; set output 'dpDiag2$mf.png'; 
			plot 'mf$mf/dpDiagi1-$N-$a.dat' w linespoints pt 7 ps 0 title 'Diag1', 
				 'mf$mf/dpDiag2-$N-$a.dat' w linespoints pt 7 ps 0 title 'Diag2'"
firefox dpDiag2$mf.png
