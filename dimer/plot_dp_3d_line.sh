#! /bin/bash
N=$1
a=$2

gnuplot -e "set terminal png size 1536,1024; set output 'dpX.png';
                               plot  'dpX$N-$a.dat' w lines title 'N = $N, a = $a'"


gnuplot -e "set terminal png size 1536,1024; set output 'dpY.png';
			plot 
				 'dpY$N-$a.dat' w lines title 'N = $N, a = $a'"
				 





gnuplot -e "set terminal png size 1536,1024; set output 'dpZ.png';
                        plot 
                                 'dpZ$N-$a.dat' w lines title 'N = $N, a = $a'"




firefox dpX.png dpY.png dpZ.png
