#! /bin/bash
mf=$1


gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2; 
			set output 'E1vsE3.png'; 
			set colors classic;
			set xlabel 'Number of Particles';
			set ylabel 'Energy';
			set samples 11;
			set xrange [0:10];
			a3 = -1.0;
			a1 = -1.0*(1.0/a3 - 1.0326);
			ene1(x) = -(1.0*x*(x*x-1.0))/(a1*a1*6.0) ;
			ene3(x) = x*1.0 + (-(1.0*x*(x*x-1.0))/(a3*a3*6.0));
			plot
			ene1(x) w line lw 4  title 'E_{1D}',
			ene3(x) w line lw 4 title 'E_{3D}',
			"

firefox E1vsE3.png &


			#ene2(x) = - x*x*x(1.0/(6.0*a(x)*a(x)));
#ene(x) = -48.0*(1.0/( 2.0*a(x)*a(x)))*x*(x*x -1.0) ;
#ene(x) = ene(x)/(-48.0*3.0)
