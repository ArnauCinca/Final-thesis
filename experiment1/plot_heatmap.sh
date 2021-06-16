#! /bin/bash
mf=$1
N=$2

a=$(echo "($N-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')
gnuplot -e "set terminal png size 1024,1024 enhanced fontscale 2; 
			set output 'dp2D$mf-$N.png';
			cmax = 0.5;
			set palette defined (0 0 0 0, cmax*0.1 0.5 0 0, cmax*0.5 1 0 0, cmax 1 1 0);
			set xlabel 'x - center of masses (position)';
			set ylabel 'y - center of masses (position)';
			set view map;
			splot 'mf$mf/dp2D$N-$a.dat' with pm3d title ''"

gnuplot -e "set terminal png size 1024,1024 enhanced fontscale 2; 
			set output 'dp2DCastin$mf-$N.png';
			cmax = 0.2;
			set palette defined (-cmax 0 1 1, -cmax*0.5 0 0 1, -cmax*0.1 0 0 0.1, 0 0 0 0, cmax*0.1 0.5 0 0, cmax*0.5 1 0 0, cmax 1 1 0);
			set xlabel 'x - center of masses (position)';
			set ylabel 'y - center of masses (position)';
			set view map;
			splot 'mf$mf/dp2DCastin$N-$a.dat' with pm3d title ''"
./castin2D $N $a

gnuplot -e "set terminal png size 1024,1024 enhanced fontscale 2;
                        set output 'dp2DCastinReal$mf-$N.png';
			cmax = 14;
			set palette defined (-cmax 0 1 1, -cmax*0.5 0 0 1, -cmax*0.1 0 0 0.1, 0 0 0 0, cmax*0.1 0.5 0 0, cmax*0.5 1 0 0, cmax 1 1 0);
                        set xlabel 'x - center of masses (position)';
                        set ylabel 'y - center of masses (position)';
                        set view map;
                        splot 'dp2D-Castin-$N-$a.dat' with pm3d title ''"

firefox dp2D$mf-$N.png dp2DCastin$mf-$N.png dp2DCastinReal$mf-$N.png

#			set cbrange [0:cmax];
#			set cbrange [-cmax:cmax];
#set cbrange [0:cmax];
#set palette defined (-cmax 0 1 1, -cmax*0.5 0 0 1, -cmax*0.1 0 0 0.1, 0 0 0 0, cmax*0.1 0.5 0 0, cmax*0.5 1 0 0, cmax 1 1 0);
#2: cmax = 2, 4, 1.6
#10: cmax = 1, 0.3, 2.5
#20: cmax = 0.2, 0.2, 4.5
#40: cmax = 0.3, 0.1, 9
#45: cmax = 0.3, 0.1, 10
#50: cmax = 0.4, 0.1, 12
#70: cmax = 0.5, 0.2, 14
