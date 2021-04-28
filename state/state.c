#include "state.h"
#include <math.h>
#include <stdio.h>


//1D
//u1 = 0
//3D
//u1 = -alpha*(x^2 +y^2)
double u1 (coords c){
#if TRIDIM == 1
	return -0.5*(c.x*c.x + c.y*c.y); //alpha?
#else
	return 0.0;
#endif
}
double u1px (coords c){
#if TRIDIM == 1
	return c.x; //alpha?
#else
	return 0.0;
#endif
}
double u1py (coords c){
#if TRIDIM == 1
	return c.y; //alpha?
#else
	return 0.0;
#endif
}
double u1pz (coords c){
	return 0.0;
}
//1D
//u2 = -r/a
//3D
//u2 = -r/a - ln r
double u2(double d){
#if TRIDIM == 1
	return -d/a - log(d);
#else
	return -d/a;
#endif
}

double u2p(double d){
	return -1.0/a;
}

double u2pp(double d){
	return 0;
}

//pn/po =exp(2*inc_u)
//if inc_u > 0 then pn/po>1 -> pn > po
//else "inc_u < 0" then pn < po
double inc_u(state* s, coords particle_old, int i){
//(u1-u1) + sum(u2-u2)

double res = u1(s->particle_coords[i]) - u1(particle_old);
double sum = 0;
for(int j = 0; j< N; j++){
    if(j != i){  
       		sum += u2(dist(s->particle_coords[i] , s->particle_coords[j])) -
              	       u2(dist(      particle_old    , s->particle_coords[j]));
    	}
	}
	return res + sum;
}


double drift_force(state* s, int i, int axis){
	double force = 0.0;
	double r = 0.0;
	//u1'
	switch(axis){
		case 0: //x
			u1px(s->particle_coords[i]);
			break;
		case 1: //y
			u1py(s->particle_coords[i]);
			break;
		case 2: //z
			u1pz(s->particle_coords[i]);
			break;
	
	}
	
	//u2'
	for(int j = 0; j < N; j++){
    		if(j != i){ 
		       	r = dist(s->particle_coords[i], s->particle_coords[j]);
#if TRIDIM == 1
			force += u2p(r) * (dist(s->particle_coords[i], orig()) - dist(s->particle_coords[j], orig()))/r;
#else
			force += u2p(r) * (s->particle_coords[i].x  - s->particle_coords[j].x)/r;//(dist(s->particle_coords[i], orig()) - dist(s->particle_coords[j], orig()))/r;
#endif

		}
	}
	return force;
}



void initState(state* s, double initial_dispersion){
	s->rejected = 0;
	s->tryed = 0;
	s->particle_coords = malloc(N*sizeof(coords));
	for(int i = 0; i < N; i++){
		coordsRandomInit(&(s->particle_coords[i]), initial_dispersion);
	}
}


//single particle move
void nextState(state* s){

	coords c;
	for(int i = 0; i < N; i++){
		s->tryed++;
		c = s->particle_coords[i];
		randomMove(&s->particle_coords[i]);
		//probability
		//if mas grande conserva el cambio
		double u = inc_u(s,c,i);
	//	if (u > 0) s->particle_coords[i] = c;
		if (u <= 0){
			int x = (int)(exp(2*u) + randomInRange(0,1));
			if(x == 0) {
				s->particle_coords[i] = c;
				s->rejected++;
			}
		//	if(x != 0) s->particle_coords[i] = c;
		}
	}
}

//each x iterations do other metrics
//pairs
//void energy(....)

double centerOfMases(state* s){
	double sum = 0;
	
	for(int i =0; i<N; ++i){
		sum += s->particle_coords[i].x;
	}
	return sum/(double)N;
}



double getEnergy(state *s){
	double energy = 0.0;
	for(int i = 0; i<N; i++){
		energy += pow(drift_force(s, i, 0), 2);
#if TRIDIM == 1
		energy += pow(drift_force(s, i, 1), 2);
		energy += pow(drift_force(s, i, 2), 2);
#endif
	}
	energy *= 1.0/2.0; //hbar =1 , m = 1  //hbar^2/2m
	return energy;
}
