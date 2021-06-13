#! /bin/bash
rm -f *.dat

for N in 20 #100
do
	for a in 19  #.25 .5 .75 1 # 2 3 4 5 #0  -1 -0.01 -0.0001 1
	do 
    		./../main $N $a &
	done
done
