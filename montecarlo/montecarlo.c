#include "montecarlo.h"
#include <stdio.h>

montecarlo* montecarloInit(double initial_dispersion, unsigned int histogram_size, double histogram_range){
	montecarlo* mc = malloc(sizeof(montecarlo));
	mc->histo = malloc(sizeof(histogram));
	mc->state = malloc(sizeof(state));
	
	initHistogram(mc->histo, histogram_range, histogram_size); //[-10.0, 10.0]
	initState(mc->state, initial_dispersion);
	
	runOneStep(mc);
	return mc;
}

void runOneStep(montecarlo* mc){
	//step
	nextState(mc->state);
	//sum to hist
	
	addDensityProfile(mc->histo, mc->state);
}

void runNSteps(montecarlo* mc, unsigned int N){
	for(int i = 0; i < N; ++i){
		runOneStep(mc);
	}
}

