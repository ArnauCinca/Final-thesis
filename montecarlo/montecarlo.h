#include "../state/state.h"


#ifndef _montecarlo_h
#define _montecarlo_h
typedef struct montecarlo{
	state* state;
} montecarlo;


montecarlo* montecarloInit(double initial_dispersion);

void runOneStep(montecarlo* mc);

void runNSteps(montecarlo* mc, unsigned int steps);
#endif
