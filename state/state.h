#ifndef _state_h
#define _state_h


#include "../coords/coords.h"


typedef struct state{
	unsigned int n_particles;
	double a;
	coords* particle_coords;
} state;


void initState(state* s, unsigned int N, double a, double initial_dispersion);
void nextState(state* s, state* ns);



#endif
