#! /bin/bash
mf=$1
N2=2
N4=4
N10=10
N20=20

a2=$(echo "($N2-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a4=$(echo "($N4-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a10=$(echo "($N10-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a20=$(echo "($N20-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')


./calogero $N2 $a2
./calogero $N4 $a4
./calogero $N10 $a10
./calogero $N20 $a20


gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2; 
			set output 'dp$mf-calo.png';
			set colors classic;
			set xlabel 'x - center of masses (position)';
			set ylabel 'n(x)';
			plot 
			 'mf$mf/dpX$N2-$a2.dat' w lines lw 4 title 'N = $N2, a = $a2',
			'dpCalo$N2-$a2.dat' w points pt 6 ps 2 linecolor 'black' title 'Calogero: N = $N2, a = $a2', 
			 'mf$mf/dpX$N4-$a4.dat' w lines lw 4 title 'N = $N4, a = $a4',
			'dpCalo$N4-$a4.dat' w points pt 3 ps 2 linecolor 'black' title 'Calogero: N = $N4, a = $a4', 
			 'mf$mf/dpX$N10-$a10.dat' w lines lw 4 title 'N = $N10, a = $a10',
			'dpCalo$N10-$a10.dat' w points pt 2 ps 2 linecolor 'black' title 'Calogero: N = $N10, a = $a10', 
			 'mf$mf/dpX$N20-$a20.dat' w lines lw 4 title 'N = $N20, a = $a20',
			'dpCalo$N20-$a20.dat' w points pt 1 ps 2 linecolor 'black' title 'Calogero: N = $N20, a = $a20', 
			"
firefox dp$mf-calo.png
