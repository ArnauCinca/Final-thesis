#! /bin/bash
make
make main
for N in 2 4 6 8 10 20
do
	for a in 0.1 1.0 10.0 100.0
	do
    		./main $N $a
	done
done
