#! /bin/bash
rm -f *.dat
rm -rf mf*/

for meanField in 1 2 4 8 10 20
do
	mkdir mf$meanField
	cd mf$meanField
	for N in 2 4 6 8 10 20
	do
		a=$(echo "($N-1) / $meanField" | bc -l )
    	./../../main $N $a
	done
	cd  ..
done
