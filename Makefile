TRIDIM = -DTRIDIM=1
ONEDIM = -DTRIDIM=0
1:
	mkdir -p makes/
	mkdir -p makes/main
	gcc -o makes/misc.o -c misc/misc.c -O3 -Wall $(ONEDIM)
	gcc -o makes/coords.o -c coords/coords.c -O3 -Wall $(ONEDIM)
	gcc -o makes/state.o -c state/state.c -O3 -Wall $(ONEDIM)
	gcc -o makes/measurements.o -c measurements/measurements.c -O3 -Wall $(ONEDIM)
	gcc -o makes/montecarlo.o -c montecarlo/montecarlo.c -O3 -Wall $(ONEDIM)
	gcc -o makes/main/main.o -c main.c -Wall $(ONEDIM)
	gcc makes/*.o makes/main/main.o -o main -lm -Wall $(ONEDIM)
3:
	mkdir -p makes/
	mkdir -p makes/main
	gcc -o makes/misc.o -c misc/misc.c -O3 -Wall $(TRIDIM)
	gcc -o makes/coords.o -c coords/coords.c -O3 -Wall $(TRIDIM)
	gcc -o makes/state.o -c state/state.c -O3 -Wall $(TRIDIM)
	gcc -o makes/measurements.o -c measurements/measurements.c -O3 -Wall $(TRIDIM)
	gcc -o makes/montecarlo.o -c montecarlo/montecarlo.c -O3 -Wall $(TRIDIM)
	gcc -o makes/main/main.o -c main.c -Wall $(TRIDIM)
	gcc makes/*.o makes/main/main.o -o main -lm -Wall $(TRIDIM)
error: error.c
	gcc error.c -o experiment1/error -lm
castin: castin.c
	gcc castin.c -o experiment1/castin -lm



clean:
	rm -r makes
	rm -f main
	rm -f error
