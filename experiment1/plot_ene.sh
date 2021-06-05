#! /bin/bash
mf=$1

gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2; 
			set output 'ene_$mf.png'; 
			set colors classic;
			a(x) = (x-1.0)/$mf;
			ene(x) = ((-48.0*1.0)/( 2.0*a(x)*a(x)))*x*(x*x -1) ;
			plot 'mf$mf/energy.dat' using 1:3 w line lw 4,
			ene(x) w point pt 2 ps 2 linecolor 'black';"

firefox ene_$mf.png &
