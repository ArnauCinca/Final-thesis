all:
	mkdir -p makes/
	gcc -o makes/misc.o -c misc/misc.c -O3 -Wall
	gcc -o makes/coords.o -c coords/coords.c -O3 -Wall
	gcc -o makes/state.o -c state/state.c -O3 -Wall
	gcc -o makes/histogram.o -c histogram/histogram.c -O3 -Wall
	gcc -o makes/montecarlo.o -c montecarlo/montecarlo.c -O3 -Wall
	rm -f main
main: main.c
	mkdir -p makes/main
	gcc -o makes/main/main.o -c main.c -Wall
	gcc makes/*.o makes/main/main.o -o main -lm -Wall
error: error.c
	gcc error.c -o experiment1/error -lm



clean:
	rm -r makes
	rm -f main
	rm -f error
