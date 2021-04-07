#! /bin/bash

N=$1
a=$2

gnuplot -e "McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a); N=$N; a=$a; plot 'dp$N-$a.dat', McGuire(x); pause -1"
