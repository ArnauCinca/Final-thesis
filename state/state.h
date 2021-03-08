#ifndef _state_h
#define _state_h




#include "../coords/coords.h"
#include "../main.h"

extern double a;
typedef struct state{
	unsigned int n_particles;
	double a;
	unsigned int rejected;
	unsigned int tryed;
	coords* particle_coords;
} state;


void initState(state* s, unsigned int N, double a, double initial_dispersion);
void nextState(state* s);



#endif
