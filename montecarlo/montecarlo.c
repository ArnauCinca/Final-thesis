#include "montecarlo.h"
#include <stdio.h>

montecarlo* montecarloInit(unsigned int N,  double a, double initial_dispersion, unsigned int histogram_definition, unsigned int histogram_range){
	montecarlo* mc = malloc(sizeof(montecarlo));
	mc->histo = malloc(101*histogram_definition*sizeof(int));//[-50,50,hd]
	mc->histogram_definition = histogram_definition;
	mc->histogram_range = histogram_range;
	mc->state = malloc(sizeof(state));
	
	for (int i = 0; i< 50*histogram_definition+1; ++i){
		mc->histo[i] = 0;
	}
	
	initState(mc->state, N, a, initial_dispersion);
	
	
	mc->steps = 0;	
	runOneStep(mc);
	return mc;
}

void runOneStep(montecarlo* mc){
	//step
	nextState(mc->state);
	//sum to hist
	double x;
	double center = centerOfMasesState(mc);
	for(int i = 0; i< mc->state->n_particles; i++){
		x = mc->state->particle_coords[i].x - center;
		if(x > -50  && x < 50){
			mc->histo[(int)(x*mc->histogram_definition)+50*mc->histogram_definition]++;
		}
	}
	mc->steps++;

}

void runNSteps(montecarlo* mc, unsigned int N){
	for(int i = 0; i < N; ++i){
		runOneStep(mc);
	}
}



double centerOfMasesState(montecarlo* mc){
	double sum = 0;
	
	for(int i =0; i<mc->state->n_particles; ++i){
		sum += mc->state->particle_coords[i].x;
	}
	return sum/(double)mc->state->n_particles;
}

void printHisto(montecarlo* mc){
	double normalization = 0.0;
	for(int i = 0; i<2*50*mc->histogram_definition+1; ++i){
		normalization += (double)(mc->histo[i] * mc->histogram_definition)/(double)(mc->steps);
		printf("%f: %f \n", (double)(i)/mc->histogram_definition-50.0, (double)(mc->histo[i] * mc->histogram_definition)/(double)(mc->steps));
	}
	normalization /=  (double)mc->histogram_definition;   //1/def
	printf("norm: %f\n", normalization);
}
