#! /bin/bash
rm -f *.dat
rm -rf mf*/

for meanField in 1 2 4 8 16
do
	mkdir mf$meanField
	cd mf$meanField
	for N in 2 3 4 5 6 7 8 9 10 # 11 12 13 14 15 16 17 18 19 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 100 
	do
		a=$(echo "($N-1) / $meanField" | bc -l )
    	./../../main $N $a &
	done
	cd  ..
done
