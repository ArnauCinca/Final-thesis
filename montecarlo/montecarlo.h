#include "../state/state.h"


#ifndef _montecarlo_h
#define _montecarlo_h
typedef struct montecarlo{
	state* state;
} montecarlo;

// initializes the montecarlo struct and then initializes the first state.
montecarlo* montecarloInit(double initial_dispersion);

// initializes the montecarlo struct and then initializes the first state.
void runOneStep(montecarlo* mc);

// initializes the montecarlo struct and then initializes the first state.
void runNSteps(montecarlo* mc, unsigned int steps);
#endif
