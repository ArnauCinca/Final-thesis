#! /bin/bash
mf=$1
N=$2

a=$(echo "scale=2;($N-1) / $mf" | bc -l | sed 's/^\./0./')

gnuplot -e "McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a);N=$N; a=$a; plot 'mf$mf/dp$N-$a.dat', McGuire(x); pause -1"
