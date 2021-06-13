gnuplot -e "set terminal png size 1536,1024 fontscale 2 lw 4; 
		set output 'a1vsa3.png';
		 set colors classic;
                        set xlabel 'a_{3D}/a_{ho}';
                        set ylabel 'a_{1D}/a_{ho}';
                        set samples 500;
			set yrange [-20:20];
			f(x) = -aho*(aho/x - A);
			g(x) = -aho*aho/x;
			A = 1.0326;
			aho = 1.0;
			set key below;
			plot 
			g(x) w lines title 'Mean-Field',
			f(x) w lines title 'Confined Induced Resonance',
			0 w lines lc 'black' lw .75 lt '-' not;"
		     
		
		
firefox a1vsa3.png &
 
