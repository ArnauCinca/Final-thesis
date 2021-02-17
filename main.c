#include <stdlib.h>
#include <stdio.h>
#include "montecarlo/montecarlo.h"


int main(int argc, char** argv){
//	srand(1111);
	unsigned int N = 100;
	unsigned int steps = 100;
	double a = 1.0;
	if(argc > 1){ //N
		long r = strtol(argv[1], NULL, 10);
		if(r > 0){
			N = r;
			printf("Now N is %d \n", N);
		}
		else{
			printf("Invalid N (first argument), must be >0\n");
		}
	}
	montecarlo* mc1D = montecarlo1D(N, a, steps);
			printf("%f\n",centerOfMasesStateI(mc1D,0));	
}
