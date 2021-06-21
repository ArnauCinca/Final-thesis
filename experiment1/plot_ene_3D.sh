#! /bin/bash
mf=$1


gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2; 
			set output 'ene_$mf-zoom.png'; 
			set colors classic;
			set xlabel 'Number of Particles';
			set ylabel 'Energy';
			set xrange [4:10];
			set samples 11;
			a(x) = x==1 ? 1.0:(x-1.0)/$mf;
			a1(x) = -1.0*(1.0/a(x) - 1.0326);
			ene(x) = x + (-(1.0*x*(x*x-1.0))/(a1(x)*a1(x)*6.0)) ;
			ene2(x) = x + ( - x/6.0);
			plot
			ene(x) w line lw 4  title 'McGuire',
			ene2(x) w line lw 4 title 'Mean-field',
			'mf$mf/energy.dat' using 1:3 w point pt 2 ps 3 lw 3 linecolor 'black' title 'Monte Carlo',
			"

firefox ene_$mf-zoom.png &


			#set yrange [-2.2:0.2];
			#ene2(x) = - x*x*x(1.0/(6.0*a(x)*a(x)));
#ene(x) = -48.0*(1.0/( 2.0*a(x)*a(x)))*x*(x*x -1.0) ;
#ene(x) = ene(x)/(-48.0*3.0)
