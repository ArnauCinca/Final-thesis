#include "../state/state.h"
#include "../histogram/histogram.h"
typedef struct montecarlo{
	histogram* histo;
	//histogram* histo...;
	state* state;
} montecarlo;


montecarlo* montecarloInit(double initial_dispersion, unsigned int histogram_size, double histogram_range);

void runOneStep(montecarlo* mc);

void runNSteps(montecarlo* mc, unsigned int steps);

void printHisto(montecarlo* mc);
