#! /bin/bash
mf=$1
N=$2

a=$(echo "scale=2;($N-1) / $mf" | bc -l | sed 's/^\./0./')
gnuplot -e "splot 'mf$mf/dp2D$N-$a.dat' with pm3d; pause -1;"
