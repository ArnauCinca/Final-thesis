#! /bin/bash
gnuplot -e "set terminal png size 800,800; set output 'error.png'; plot 
	'mf1_error.dat' w linespoints pt 7 title 'mf = 1', 
	'mf2_error.dat' w linespoints pt 7 title 'mf = 2',
	'mf4_error.dat' w linespoints pt 7 title 'mf = 4', 
	'mf8_error.dat' w linespoints pt 7 title 'mf = 8', 
	'mf16_error.dat' w linespoints pt 7 title 'mf = 16'"
firefox error.png
