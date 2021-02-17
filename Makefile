all:
	mkdir -p makes/
	gcc -o makes/misc.o -c misc/misc.c -O3
	gcc -o makes/coords.o -c coords/coords.c -O3
	gcc -o makes/state.o -c state/state.c -O3
	gcc -o makes/montecarlo.o -c montecarlo/montecarlo.c -O3
main: main.c
	mkdir -p makes/main
	gcc -o makes/main/main.o -c main.c
	gcc makes/*.o makes/main/main.o -o main -lm

clean:
	rm -r makes
