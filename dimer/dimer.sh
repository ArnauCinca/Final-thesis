#! /bin/bash
rm -f *.dat

for N in 2 # 4 8 10
do
	for a in -1 -0.01 -0.0001 1
	do
    		./../main $N $a
	done
done
