#! /bin/bash
rm -f *.dat

for N in 6
do
	for a in 100
	do
    		./../main $N $a
	done
done
