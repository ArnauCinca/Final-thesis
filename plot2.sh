#! /bin/bash

N=$1
a=$2

if [ $N -eq 2 ]
then
	gnuplot -e "McGuire(x) = 2*exp(-2*abs(x)/a)/a ; N=$N; a=$a; plot 'out$N-$a.dat', McGuire(x); pause -1"
else
	gnuplot -e "McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a); N=$N; a=$a; plot 'out$N-$a.dat', McGuire(x); pause -1"
fi
