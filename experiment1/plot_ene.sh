#! /bin/bash

mf=$1
N=$2
a=$(echo "($N-1) / $mf" | bc -l | awk '{printf("%.2f\n", $1)}')


gnuplot -e "plot 'mf$mf/energy$N-$a.dat'; pause -1"
