NHTRAP = -DHTRAP=0
HTRAP = -DHTRAP=1
TRIDIM = -DTRIDIM=1
ONEDIM = -DTRIDIM=0
1:
	mkdir -p makes/
	mkdir -p makes/main
	gcc -o makes/misc.o -c misc/misc.c -O3 -Wall $(ONEDIM) $(NHTRAP)
	gcc -o makes/coords.o -c coords/coords.c -O3 -Wall $(ONEDIM) $(NHTRAP)
	gcc -o makes/state.o -c state/state.c -O3 -Wall $(ONEDIM) $(NHTRAP)
	gcc -o makes/measurements.o -c measurements/measurements.c -O3 -Wall $(ONEDIM) $(NHTRAP)
	gcc -o makes/montecarlo.o -c montecarlo/montecarlo.c -O3 -Wall $(ONEDIM) $(NHTRAP)
	gcc -o makes/main/main.o -c main.c -Wall $(ONEDIM) $(NHTRAP)
	gcc makes/*.o makes/main/main.o -o main -lm -Wall $(ONEDIM) $(NHTRAP)
3:
	mkdir -p makes/
	mkdir -p makes/main
	gcc -o makes/misc.o -c misc/misc.c -O3 -Wall $(TRIDIM) $(NHTRAP)
	gcc -o makes/coords.o -c coords/coords.c -O3 -Wall $(TRIDIM) $(NHTRAP)
	gcc -o makes/state.o -c state/state.c -O3 -Wall $(TRIDIM) $(NHTRAP)
	gcc -o makes/measurements.o -c measurements/measurements.c -O3 -Wall $(TRIDIM) $(NHTRAP)
	gcc -o makes/montecarlo.o -c montecarlo/montecarlo.c -O3 -Wall $(TRIDIM) $(NHTRAP)
	gcc -o makes/main/main.o -c main.c -Wall $(TRIDIM) $(NHTRAP)
	gcc makes/*.o makes/main/main.o -o main -lm -Wall $(TRIDIM) $(NHTRAP)
1T:
	mkdir -p makes/
	mkdir -p makes/main
	gcc -o makes/misc.o -c misc/misc.c -O3 -Wall $(ONEDIM) $(HTRAP)
	gcc -o makes/coords.o -c coords/coords.c -O3 -Wall $(ONEDIM) $(HTRAP)
	gcc -o makes/state.o -c state/state.c -O3 -Wall $(ONEDIM) $(HTRAP)
	gcc -o makes/measurements.o -c measurements/measurements.c -O3 -Wall $(ONEDIM) $(HTRAP)
	gcc -o makes/montecarlo.o -c montecarlo/montecarlo.c -O3 -Wall $(ONEDIM) $(HTRAP)
	gcc -o makes/main/main.o -c main.c -Wall $(ONEDIM) $(HTRAP)
	gcc makes/*.o makes/main/main.o -o main -lm -Wall $(ONEDIM) $(HTRAP)
3T:
	mkdir -p makes/
	mkdir -p makes/main
	gcc -o makes/misc.o -c misc/misc.c -O3 -Wall $(TRIDIM) $(HTRAP)
	gcc -o makes/coords.o -c coords/coords.c -O3 -Wall $(TRIDIM) $(HTRAP)
	gcc -o makes/state.o -c state/state.c -O3 -Wall $(TRIDIM) $(HTRAP)
	gcc -o makes/measurements.o -c measurements/measurements.c -O3 -Wall $(TRIDIM) $(HTRAP)
	gcc -o makes/montecarlo.o -c montecarlo/montecarlo.c -O3 -Wall $(TRIDIM) $(HTRAP)
	gcc -o makes/main/main.o -c main.c -Wall $(TRIDIM) $(HTRAP)
	gcc makes/*.o makes/main/main.o -o main -lm -Wall $(TRIDIM) $(HTRAP)
error: error.c
	gcc error.c -o experiment1/error -lm
calogero: calogero.c
	gcc calogero.c -o experiment1/calogero -lm
castin2D: castin2D.c
	gcc castin2D.c -o experiment1/castin2D -lm



clean:
	rm -r makes
	rm -f main
	rm -f error
