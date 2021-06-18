#! /bin/bash
mf=$1
N20=5 #20
N40=10 #40
N45=40 #45
N50=80 #50

a20=$(echo "($N20-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a40=$(echo "($N40-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a45=$(echo "($N45-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
a50=$(echo "($N50-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
./castin2D $N20 $a20 
./castin2D $N40 $a40 
./castin2D $N45 $a45 
./castin2D $N50 $a50 
gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2 lw 4; 
			set output 'dpDiag1_$mf.png';
			set ylabel 'δρ(x,-x)';
			set xlabel 'x - center of masses (position)';
			set key below;
			set colors classic;
			plot 
			 	 'mf$mf/dpDiag1-$N20-$a20.dat' w lines title 'N = $N20, a = $a20', 
			 	 'CastinApproxDiag1-$N20-$a20.dat' w points pt 6 lw 0.5 ps 2 linecolor 'black' title 'Castin Approx: N = $N20, a = $a20', 
				 'mf$mf/dpDiag1-$N40-$a40.dat' w lines title 'N = $N40, a = $a40',
			 	 'CastinApproxDiag1-$N40-$a40.dat' w points pt 4 lw 0.5 ps 2 linecolor 'black' title 'Castin Approx: N = $N40, a = $a40', 
				 'mf$mf/dpDiag1-$N45-$a45.dat' w lines title 'N = $N45, a = $a45',
			 	 'CastinApproxDiag1-$N45-$a45.dat' w points pt 3 lw 0.5 ps 2 linecolor 'black' title 'Castin Approx: N = $N45, a = $a45', 
				 'mf$mf/dpDiag1-$N50-$a50.dat' w lines title 'N = $N50, a = $a50',
			 	 'CastinApproxDiag1-$N50-$a50.dat' w points pt 2 lw 0.5 ps 2 linecolor 'black' title 'Castin Approx: N = $N50, a = $a50', 
	   "


gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2 lw 4; 
			set output 'dpDiag2_$mf.png'; 
			set ylabel 'δρ(x,x)';
			set key below;
			set xlabel 'x - center of masses (position)';
			set colors classic;
			plot
		       		 'mf$mf/dpDiag2-$N20-$a20.dat' w lines title 'N = $N20, a = $a20', 
				 'CastinApproxDiag2-$N20-$a20.dat' w points pt 6 lw 0.5 ps 2 linecolor 'black' title 'Castin Approx: N = $N20, a = $a20',
				 'mf$mf/dpDiag2-$N40-$a40.dat' w lines title 'N = $N40, a = $a40',
				 'CastinApproxDiag2-$N40-$a40.dat' w points pt 4 lw 0.5 ps 2 linecolor 'black' title 'Castin Approx: N = $N40, a = $a40',
				 'mf$mf/dpDiag2-$N45-$a45.dat' w lines title 'N = $N45, a = $a45',
				 'CastinApproxDiag2-$N45-$a45.dat' w points pt 3 lw 0.5 ps 2 linecolor 'black' title 'Castin Approx: N = $N45, a = $a45',
				 'mf$mf/dpDiag2-$N50-$a50.dat' w lines title 'N = $N50, a = $a50',
				 'CastinApproxDiag2-$N50-$a50.dat' w points pt 2 lw 0.5 ps 2 linecolor 'black' title 'Castin Approx: N = $N50, a = $a50', 
	  "

firefox dpDiag1_$mf.png &
firefox dpDiag2_$mf.png &
#CastinApproxDiag1-10-9.00.dat
