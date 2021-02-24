#include "state.h"
#include <math.h>

//1D
//u1 = 0
//3D
//u1 = -alpha*(x^2 +y^2)
double u1 (coords c){
#ifdef TRIDIM
	return -1*(c.x*c.x + c.y*c.y); //alpha?
#else
	return 0;
#endif
}
//1D
//u2 = -r/a
//3D
//u2 = -r/a - ln r
double u2(double d, double a){
#ifdef TRIDIM
	return -d/a - log(d);
#else
	return -d/a;
#endif
}


//pn/po =exp(2*inc_u)
//if inc_u > 0 then pn/po>1 -> pn > po
//else "inc_u < 0" then pn < po
double inc_u(state* s, state* ns, int i){
//(u1-u1) + sum(u2-u2)

double res = u1(ns->particle_coords[i]) - u1(s->particle_coords[i]);
double sum = 0;
for(int j = 0; j< s->n_particles; ++j){
	if(j != i){  //no need because dist of coord[i] & coord[i] = 0
		//for now a = 1
		sum += u2(abs(dist(ns->particle_coords[i], ns->particle_coords[j])),ns->a) -
			   u2(abs(dist( s->particle_coords[i],  s->particle_coords[j])), s->a);
	}
}
return res + sum;



}



void initState(state* s, unsigned int N, double a, double initial_dispersion){
	s->n_particles = N;
	s->a = a;
	s->particle_coords = malloc(s->n_particles*sizeof(coords));
	for(int i = 0; i < s->n_particles; i++){
		coordsRandomInit(&(s->particle_coords[i]), initial_dispersion);
	}
}


//single particle move
void nextState(state* s, state *ns){
	
	for(int i = 0; i < ns->n_particles; i++){
		ns->particle_coords[i] = s->particle_coords[i];
	}

	for(int i = 0; i < ns->n_particles; i++){
		randomMove(&ns->particle_coords[i]);
		
		//probability
		//if mas grande conserva el cambio
		double u = inc_u(s,ns,i);
		//if u > 0 accept change
		if(u <= 0){
			int x = (int)(exp(2*u) + randomInRange(0,1));
			if(x == 0) ns->particle_coords[i] = s->particle_coords[i];
			//if > 1 accept change 
		}
	}
}


