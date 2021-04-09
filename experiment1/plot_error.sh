#! /bin/bash
gnuplot -e "set terminal png size 800,800; set output 'error.png'; plot 'mf1_error.dat' w linespoints pt 7, 'mf2_error.dat' w linespoints pt 7,'mf4_error.dat' w linespoints pt 7, 'mf8_error.dat' w linespoints pt 7, 'mf16_error.dat' w linespoints pt 7"
firefox error.png
