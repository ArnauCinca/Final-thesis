#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "montecarlo/montecarlo.h"
double a = 100.0;

	//histo distancias
	//definition -> resolition
	//define elements by all the range (histo)
int main(int argc, char** argv){
	srand(1111);
	unsigned int N = 10;
//	double a = 10.0;
	double initial_dispersion = a/(2.0*N);  //particle spawn (-initial_dispersion,initial dispersion)
	//histogram_step
	//  1/hist_step
	unsigned int histogram_resolution = 1;//1/N //1 -> -50, -49,.., 49,50; 10 -> -50, -49.9,...,49.9,50; ...
	unsigned int histogram_range = 15; //[-r,r]
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
	montecarlo* mc = montecarloInit(N, a, initial_dispersion, histogram_resolution, histogram_range);
//	printHisto(mc);
//McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a)


	runNSteps(mc,100000);
	printHisto(mc);
	printf("----------------------------------------------------------------------------------\n");
	for (int i  =0; i< mc->state->n_particles; ++i){
		printf("%f\n",mc->state->particle_coords[i].x);
	}
	printf("----------------------------------------------------------------------------------\n");
	
	printf("Accrptance ratio: %lf\n", 1.-(double)mc->state->rejected/(double)mc->state->tryed);
	//printf("Rejected: %d\n", mc->state->rejected);
//	printf("%f\n",centerOfMasesStateI(mc));	
}
