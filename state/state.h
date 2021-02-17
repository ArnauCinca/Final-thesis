#ifndef _state_h
#define _state_h


#include "../coords/coords.h"


typedef struct state{
	unsigned int n_particles;
	coords* particle_coords;
} state;


state newState1D(unsigned int N);
state nextState(state s);




#endif
