#include "state.h"
#include <math.h>



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


double centerOfMases(state* s){
	double sum = 0;
	
	for(int i =0; i<N; ++i){
		sum += s->particle_coords[i].x;
	}
	return sum/(double)N;
}
