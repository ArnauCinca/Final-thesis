#include <stdlib.h>
#include <stdio.h>
#include "montecarlo/montecarlo.h"


int main(int argc, char** argv){
//	srand(1111);
	unsigned int N = 100;
	double a = 1.0;
	double initial_dispersion = 5.0;  //particle spawn (-initial_dispersion,initial dispersion)
	unsigned int histogram_definition = 1; //1 -> -50, -49,.., 49,50; 10 -> -50, -49.9,...,49.9,50; ...
	/*if(argc > 1){ //N
		long r = strtol(argv[1], NULL, 10);
		if(r > 0){
			N = r;
			printf("Now N is %d \n", N);
		}
		else{
			printf("Invalid N (first argument), must be >0\n");
		}
	}*/
	montecarlo* mc = montecarloInit(N, a, initial_dispersion, histogram_definition);
	printHisto(mc);
//	runOneStep(mc);
//	printHisto(mc);

	printf("----------------------------------------------------------------------------------\n");
	runNSteps(mc,100);
	printHisto(mc);
//	printf("%f\n",centerOfMasesStateI(mc));	
}
