#ifndef _state_h
#define _state_h




#include "../coords/coords.h"

extern double a;
extern unsigned int N;

typedef struct state{
	unsigned int rejected;
	unsigned int tried;
	coords* particle_coords;
} state;

// returns the ratio of acceptance of the Metropolis algorithm a good ratio must be between 0.1 and 0.9.
double acceptanceRatio(state* s);

// initializes all the particles in the state s using the randomInit method from the coordinates struct with initial_dispersion.
void initState(state* s, double initial_dispersion);

// applies the Manhattan algorithm over the state to generate the next state, and it overrides the state s with it.
void nextState(state* s);

// returns the center (mean) of all the positions from the particles. 1D: x; 3D: z
double centerOfMases(state* s);

// returns the energy of the state.
double getEnergy(state *s);


#endif
