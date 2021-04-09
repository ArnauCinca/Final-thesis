#! /bin/bash

N=$1
a=$2

gnuplot -e "set terminal png size 500,500; set output 'dp$N-$a.png'; McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a); N=$N; a=$a; plot 'dp$N-$a.dat', McGuire(x);"

firefox dp$N-$a.png
