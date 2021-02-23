#include "montecarlo.h"
#include <stdio.h>


montecarlo* montecarloInit(unsigned int N,  double a, double initial_dispersion, unsigned int histogram_definition){
	montecarlo* mc = malloc(sizeof(montecarlo));
	mc->histo = malloc(101*histogram_definition*sizeof(int));//[-50,50,hd]
	mc->histogram_definition = histogram_definition;
	mc->last_state = malloc(sizeof(state));
	mc->next_state = malloc(sizeof(state));
	
	for (int i = 0; i< 101; ++i){
		mc->histo[i] = 0;
	}
	
	initState(mc->last_state, N, a, initial_dispersion);
	for(int i = 0; i<N; i++){
		mc->histo[(int)(mc->last_state->particle_coords[i].x*histogram_definition)+50*histogram_definition]++;
	}
	
	initState(mc->next_state, N, a, initial_dispersion);

	return mc;
}

void runOneStep(montecarlo* mc){
	//step
	nextState(mc->last_state,mc->next_state);
	//sum to hist
	for(int i = 0; i< mc->last_state->n_particles; i++){
		mc->histo[(int)(mc->next_state->particle_coords[i].x*mc->histogram_definition)+50*mc->histogram_definition]++;
	}

	//last_step = next_step
	for(int i = 0; i < mc->last_state->n_particles; i++){
        mc->last_state->particle_coords[i] = mc->next_state->particle_coords[i];
    }
}

void runNSteps(montecarlo* mc, unsigned int N){
	for(int i = 0; i < N; ++i){
		runOneStep(mc);
	}
}



double centerOfMasesStateI(montecarlo* mc){
	double sum = 0;
	double tot = 0;
	for(int i =0; i<101; ++i){
		tot += mc->histo[i];
		sum += (i-50)*mc->histo[i];
	}
	return sum / tot;
}

void printHisto(montecarlo* mc){
	for(int i = 0; i<101*mc->histogram_definition; ++i){
		printf("%f: %d \n", (double)(i)/mc->histogram_definition-50.0, mc->histo[i]);
	}
}
