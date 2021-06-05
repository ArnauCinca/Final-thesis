#! /bin/bash

Aho=1

gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2 lw 4; 
			set output 'a1vsa3.png';
			set colors classic;
			set xlabel 'a_{3D}/a_{ho}';
			set ylabel 'a_{1D}/a_{ho}';
			f(x) = -$Aho*($Aho/x - A);
			g(x) = -$Aho*$Aho/x;
			A = 1.0326;
                        plot  
				g(x) w lines title 'Mean-Field',
				f(x) w lines title 'Confined Induced Resonance'"

gnuplot -e "set terminal png size 1536,1024 enhanced fontscale 2 lw 4; 
			set output 'a1vsg1.png';
			set colors classic;
			set encoding utf8;
			set xlabel 'a_{3D}/a_{ho}';
			set ylabel 'g_{1D} (ℏ^2/(ma_{ho}))';
			f(x) = -$Aho*($Aho/x - A);
			g(x) = -$Aho*$Aho/x;
			A = 1.0326;
                        plot  
				g(x) w lines title 'Mean-Field',
				f(x) w lines title 'Confined Induced Resonance'"


firefox a1vsa3.png a1vsg1.png
