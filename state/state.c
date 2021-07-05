#include "state.h"
#include <math.h>
#include <stdio.h>


double u1 (coords c){
#if TRIDIM == 1
#if HTRAP == 0
	return -0.5*(c.x*c.x + c.y*c.y);
#else
	return -0.5*(c.x*c.x + c.y*c.y  + c.z*c.z);
#endif
#else
#if HTRAP == 0
	return 0.0;
#else
	return -0.5*(c.x*c.x);
#endif
#endif
}

double u1px (coords c){
#if TRIDIM == 1
	return c.x; 
#else
#if HTRAP == 0
	return 0.0;
#else
	return c.x;
#endif
#endif
}

double u1ppx (coords c){
#if TRIDIM == 1
	return 1.0; 
#else
#if HTRAP == 0
	return 0.0;
#else
	return 1.0;
#endif
#endif
}


double u1py (coords c){
#if TRIDIM == 1
	return c.y;
#else
	return 0.0;
#endif
}

double u1ppy (coords c){
#if TRIDIM == 1
	return 1.0; 
#else
	return 0.0;
#endif
}


double u1pz (coords c){
#if TRIDIM == 1
#if HTRAP == 0
	return 0.0;
#else
	return c.z;
#endif
#else
	return 0.0;
#endif
}
double u1ppz (coords c){
#if TRIDIM == 1
#if HTRAP == 0
	return 0.0;
#else
	return 1.0;
#endif
#else
	return 0.0;
#endif
}

double u2(double d){
#if TRIDIM == 1
	return log(1.0 - d/a3D) - ((d*d) / (a1D * (Ap + d)));
#else
	return -d/a1D;
#endif
}

double u2p(double d){
#if TRIDIM == 1
//	return - ( (2.0*d) / (a1D * (Ap + d) ) ) + ( (d *d) / (a1D * pow(Ap + d, 2) ) )  + ( (a) / (d*d*(1.0-a/d)));
	return - (1.0/(a3D*(1.0-d/a3D))) - (2.0*d/(a1D*(d+Ap))) + ((d*d)/(a1D*pow(d+Ap,2)));
#else
	return -1.0/a1D;
#endif
}

double u2pp(double d){
#if TRIDIM == 1
//	return -(2.0/(a1D*(d+Ap))) + ((4.0*d)/(a1D*pow(d+Ap,2))) - ((2.0*d*d)/(a1D*pow(d+Ap,3))) - ((2.0*a)/((1.0-a/d)*d*d*d)) - ((a*a)/(pow(1.0-a/d ,2)*d*d*d*d));
	return -(1.0/(a3D*a3D*pow(1-d/a3D,2))) - (2.0/(a1D*(d+Ap))) + ((4.0*d)/(a1D*pow(d+Ap,2))) - ((2.0*d*d)/(a1D*pow(d+Ap,3)));	
#else
	return 0.0;
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


double drift_force(state* s, int i, int axis){
	double force = 0.0;
	double r = 0.0;
	//u1'
	switch(axis){
		case 0: //x
			force = u1px(s->particle_coords[i]);
			break;
		case 1: //y
			force = u1py(s->particle_coords[i]);
			break;
		case 2: //z
			force = u1pz(s->particle_coords[i]);
			break;
	
	}
	
	//u2'
	for(int j = 0; j < N; j++){
    		if(j != i){ 
		       	r = dist(s->particle_coords[i], s->particle_coords[j]);
#if TRIDIM == 1
			force += u2p(r) * (dist(s->particle_coords[i], orig()) - dist(s->particle_coords[j], orig()))/r;
#else
			force += u2p(r) * (s->particle_coords[i].x  - s->particle_coords[j].x)/r;
#endif

		}
	}
	return force;
}



void initState(state* s, double initial_dispersion){
	s->rejected = 0;
	s->tried = 0;
	s->particle_coords = malloc(N*sizeof(coords));
	for(int i = 0; i < N; i++){
		coordsRandomInit(&(s->particle_coords[i]), initial_dispersion);
	}
}


//single particle move
void nextState(state* s){

	coords c;
	for(int i = 0; i < N; i++){
		s->tried++;
		c = s->particle_coords[i];
		randomMove(&s->particle_coords[i]);
		//probability
		double u = inc_u(s,c,i);
		if (u <= 0){
			int x = (int)(exp(2*u) + randomInRange(0,1));
			if(x == 0) {
				s->particle_coords[i] = c;
				s->rejected++;
			}
		}
	}
}

double acceptanceRatio(state* s){
	return 1.0 - (double)s->rejected/(double)s->tried;
}

double centerOfMases(state* s){
	double sum = 0;
	
	for(int i =0; i<N; ++i){
#if TRIDIM == 1
		sum += s->particle_coords[i].z;
#else
		sum += s->particle_coords[i].x;
#endif
	}
	return sum/(double)N;
}



double getEnergy(state *s){
	double energy = 0.0;
	double ene1 = 0.0, ene21 = 0.0, ene22=0.0;
	for(int i = 0; i<N; i++){
		ene1 = 0.0;
		//F
		ene1 += (double)pow(drift_force(s, i, 0), 2);
#if TRIDIM == 1
		ene1 += (double)pow(drift_force(s, i, 1), 2);
		ene1 += (double)pow(drift_force(s, i, 2), 2);
#endif
//	       if(ene1 < 0){
  //              printf("X: %lf, Y: %lf, Z: %lf; En_pre_pre: %lf; \n",pow(drift_force(s, i, 0), 2),pow(drift_force(s, i, 1), 2),pow(drift_force(s, i, 2), 2), ene1);
    //    }
		//---
		ene1 += u1ppx(s->particle_coords[i]);
#if TRIDIM == 1
		ene1 += u1ppy(s->particle_coords[i]);
		ene1 += u1ppz(s->particle_coords[i]);
#endif

		ene21 = 0.0;
		ene22 = 0.0;
		for( int j = 0; j<i; j++){
			ene21 += u2pp(dist(s->particle_coords[i], s->particle_coords[j]));
#if TRIDIM == 1
			ene22 += 2.0*u2p(dist(s->particle_coords[i], s->particle_coords[j]))/ dist(s->particle_coords[i], s->particle_coords[j]);
#endif				
		}
		if(ene21 + ene22 < 0 ){
//                printf("e21: %lf; e22: %lf; e2: %lf \n", ene21, ene22, ene21+ene22);			
		}
		energy += ene1 + fabs(ene21 + ene22)*2.0;
	}
	

	energy *= -1.0/2.0; //hbar =1 , m = 1  //hbar^2/2m
#if TRIDIM == 1
	energy += 1.0*1.0*(double)N;
#endif
	if(energy < -1000){
//		printf("En: %lf\n", energy);
	}
	return energy;
}
