#include "montecarlo.h"
#include <stdio.h>

montecarlo* montecarloInit(double initial_dispersion){
	montecarlo* mc = malloc(sizeof(montecarlo));
	mc->state = malloc(sizeof(state));
	
	initState(mc->state, initial_dispersion);
	
	runOneStep(mc);
	return mc;
}

void runOneStep(montecarlo* mc){
	nextState(mc->state);
}

void runNSteps(montecarlo* mc, unsigned int N){
	for(int i = 0; i < N; ++i){
		runOneStep(mc);
	}
}

