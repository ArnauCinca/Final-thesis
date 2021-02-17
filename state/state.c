#include "state.h"


state newState1D(unsigned int N){
	state s;
	s.n_particles = N;
	s.particle_coords = malloc(N*sizeof(coords));
	for(int i = 0; i<N; i++){
		s.particle_coords[i] = coordsRandomInit();
	}
	return s;
}


state nextState(state s/*, prob_func*/){
	state ns;
	ns.n_particles = s.n_particles;
	ns.particle_coords = malloc(ns.n_particles*sizeof(coords));
	for(int i = 0; i<ns.n_particles; i++){
		ns.particle_coords[i] = s.particle_coords[i];
	}

	for(int i = 0; i<ns.n_particles; i++){
		randomMove(&ns.particle_coords[i]);
		
		//probability
		double pn = 0.0;
		double po = 0.0;
		if(pn < po){
			int x = (int)(pn/po + randomInRange(0,1));
			if(x == 0) ns.particle_coords[i] = s.particle_coords[i];
		}
	}
	return ns;
}
