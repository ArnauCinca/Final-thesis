#! /bin/bash

N=$1
a=$2

gnuplot -e "plot 'dist$N-$a.dat'; pause -1"
