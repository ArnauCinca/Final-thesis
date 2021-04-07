#! /bin/bash

mf=$1
N=$2

a=$(echo "scale=2;($N-1) / $mf" | bc -l | sed 's/^\./0./')

gnuplot -e "plot 'mf$mf/energy$N-$a.dat'; pause -1"
