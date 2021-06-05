#! /bin/bash
rm -f *.dat

for N in 2 4 6 8 10 20 100
do
	for a in 1 #.25 .5 .75 1 # 2 3 4 5 #0  -1 -0.01 -0.0001 1
	do 
    		./../main $N $a
	done
done
