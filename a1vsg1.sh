gnuplot -e " set terminal png size 1536,1024 enhanced fontscale 2 lw 4; 
		set output 'a1vsg1.png';
		 set colors classic;
		 set encoding utf8;

                       set xlabel 'a_{3D}/a_{ho}';
			set ylabel 'g_{1D}, (ℏ²/(ma_{ho})) ';
                        set samples 500;
			set yrange [-20:20];
			f(x) = -aho*(aho/x - A);
			g(x) = -aho*aho/x; 			
			A = 1.0326;
			aho = 1.0;
			set key below;
			plot 
			-2.0/g(x) w lines title 'Mean-Field',
			-2.0/f(x) w lines title 'Confined Induced Resonance',
			;"
