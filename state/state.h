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


double acceptanceRatio(state* s);
void initState(state* s, double initial_dispersion);
void nextState(state* s);
double centerOfMases(state* s);
double getEnergy(state *s);


#endif
