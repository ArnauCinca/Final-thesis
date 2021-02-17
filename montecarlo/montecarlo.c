#include "montecarlo.h"
montecarlo* montecarlo1D(unsigned int N, double a, unsigned int steps){
	montecarlo* mc = malloc(sizeof(montecarlo));
	mc->last_state = 0;
	mc->max_states = steps;
	mc->states = malloc(mc->max_states*sizeof(state));
	mc->states[0] = newState1D(N);
	return mc;
}

void runAllSteps(montecarlo* mc){

}

void runOneStep(montecarlo* mc){

}



double centerOfMasesStateI(montecarlo* mc, unsigned int i){
	if (i>mc->last_state) return 0.0;
	double sum = 0;
	for(int x =0; x<mc->states[i].n_particles; x++) sum += mc->states[i].particle_coords[x].x;
	return sum / mc->states[i].n_particles;
	
}
