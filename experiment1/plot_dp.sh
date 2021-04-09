#! /bin/bash
mf=$1
N2=2
N4=4
N6=6
N10=10
N20=20
N100=100

a2=$(echo "scale=2;($N2-1) / $mf" | bc -l | sed 's/^\./0./')
a4=$(echo "scale=2;($N4-1) / $mf" | bc -l | sed 's/^\./0./')
a6=$(echo "scale=2;($N6-1) / $mf" | bc -l | sed 's/^\./0./')
a10=$(echo "scale=2;($N10-1) / $mf" | bc -l | sed 's/^\./0./')
a20=$(echo "scale=2;($N20-1) / $mf" | bc -l | sed 's/^\./0./')
a100=$(echo "scale=2;($N100-1) / $mf" | bc -l | sed 's/^\./0./')
gnuplot -e "set terminal png size 800,800; set output 'dp$mf.png'; 
			McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a);
			N=$N100; a=$a100;
			plot 'mf$mf/dp$N2-$a2.dat', 
				 'mf$mf/dp$N4-$a4.dat',
				 'mf$mf/dp$N6-$a6.dat',
				 'mf$mf/dp$N10-$a10.dat',
				 'mf$mf/dp$N20-$a20.dat',
				 'mf$mf/dp$N100-$a100.dat', 
				 McGuire(x)"
firefox dp$mf.png
