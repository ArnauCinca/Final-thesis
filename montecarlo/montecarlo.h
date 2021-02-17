#include "../state/state.h"

typedef struct montecarlo{
	unsigned int last_state;
	unsigned int max_states;
	state* states;
} montecarlo;


montecarlo* montecarlo1D(unsigned int N, double a, unsigned int steps);

void runAllSteps(montecarlo* mc);

void runOneStep(montecarlo* mc);

