#! /bin/bash
rm -f *.dat
rm -rf mf*/

for meanField in 1  #2 4 8 16
do
	mkdir mf$meanField
	cd mf$meanField
	for N in 2 3 4 5 6 7 8 9 10 20 # 100 
	do
		a=$(echo "($N-1) / $meanField" | bc -l )
    		./../../main $N $a &
	done
	cd  ..
done
