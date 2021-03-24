#! /bin/bash

N=$1
a=$2

gnuplot -e "McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a); McGuire2(x) = 2*exp(-2*abs(x)/a)/a ;N=$N; a=$a; plot 'dp$N-$a.dat', McGuire(x), McGuire2(x); pause -1"
