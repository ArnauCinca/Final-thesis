#! /bin/bash
mf=$1
N=$2

a=$(echo "($N-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')

./castin2D $N $a

gnuplot -e "set terminal png size 1024,1024 enhanced fontscale 2; 
			set output 'dp2D$mf-$N.png';
			set size 0.8,0.9; set origin 0.1,0.2;
			set colorbox horizontal;
			set colorbox user origin 0.1,0.1 size 0.8,0.1;
			cmax = 0.3;
			set cbrange [0:cmax];
			set palette defined ( 0 0 0 0, cmax*0.1 0.5 0 0, cmax*0.5 1 0 0, cmax 1 1 0);
			set xlabel 'x_i - center of masses (position)';
			set ylabel 'x_j - center of masses (position)';
			set view map;
			splot 'mf$mf/dp2D$N-$a.dat' with pm3d title ''"

gnuplot -e "set terminal png size 1024,1024 enhanced fontscale 2;
                        set output 'dp2DCalo$mf-$N.png';
			set size 0.8,0.9; set origin 0.1,0.2;
			set colorbox horizontal;
			set colorbox user origin 0.1,0.1 size 0.8,0.1;
			cmax = 0.3;
			set cbrange [0:cmax];
			set palette defined (0 0 0 0, cmax*0.1 0.5 0 0, cmax*0.5 1 0 0, cmax 1 1 0);
                        set xlabel 'x_i - center of masses (position)';
                        set ylabel 'x_j - center of masses (position)';
                        set view map;
                        splot 'dp2DCalo$N-$a.dat' with pm3d title ''"

gnuplot -e "set terminal png size 1024,1024 enhanced fontscale 2; 
			set output 'dp2DCastin$mf-$N.png';
			set size 0.8,0.9; set origin 0.1,0.2;
			set colorbox horizontal;
			set colorbox user origin 0.1,0.1 size 0.8,0.1;
			cmax = 0.004;
			set cbrange [-cmax:cmax];
			set palette defined (-cmax 0 1 1, -cmax*0.5 0 0 1, -cmax*0.1 0 0 0.1, 0 0 0 0, cmax*0.1 0.5 0 0, cmax*0.5 1 0 0, cmax 1 1 0);
			set xlabel 'x_i - center of masses (position)';
			set ylabel 'x_j - center of masses (position)';
			set view map;
			splot 'mf$mf/dp2DCastin$N-$a.dat' with pm3d title ''"

gnuplot -e "set terminal png size 1024,1024 enhanced fontscale 2;
                        set output 'CastinApprox$mf-$N.png';
			set size 0.8,0.9; set origin 0.1,0.2;
			set colorbox horizontal;
			set colorbox user origin 0.1,0.1 size 0.8,0.1;
			cmax = 0.004;
			set cbrange [-cmax:cmax];
			set palette defined (-cmax 0 1 1, -cmax*0.5 0 0 1, -cmax*0.1 0 0 0.1, 0 0 0 0, cmax*0.1 0.5 0 0, cmax*0.5 1 0 0, cmax 1 1 0);
                        set xlabel 'x_i - center of masses (position)';
                        set ylabel 'x_j - center of masses (position)';
                        set view map;
                        splot 'CastinApprox$N-$a.dat' with pm3d title ''"

firefox dp2D$mf-$N.png dp2DCalo$mf-$N.png dp2DCastin$mf-$N.png CastinApprox$mf-$N.png &

#			set cbrange [0:cmax];
#			set cbrange [-cmax:cmax];
#set cbrange [0:cmax];
#			set palette defined (-cmax 0 1 1, -cmax*0.5 0 0 1, -cmax*0.1 0 0 0.1, 0 0 0 0, cmax*0.1 0.5 0 0, cmax*0.5 1 0 0, cmax 1 1 0);
#2: cmax = 30, 8, 25, 0.8
#5: cmax = 0.7, 0.7, 0.1, 0.1
#10: cmax = 0.4 0.4, 0.03, 0.03 
#40: cmax = 0.3, 0.3, 0.006, 0.006
#80: cmax = 0.3, 0.3, 0.004, 0.004
