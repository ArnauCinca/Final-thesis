#include "../state/state.h"

typedef struct montecarlo{
	unsigned int* histo;
	unsigned int histogram_definition;
	state* last_state;
	state* next_state;
} montecarlo;


montecarlo* montecarloInit(unsigned int N,  double a, double initial_dispersion, unsigned int histogram_definition);

void runOneStep(montecarlo* mc);

void runNSteps(montecarlo* mc, unsigned int steps);

double centerOfMasesStateI(montecarlo* mc);

void printHisto(montecarlo* mc);
