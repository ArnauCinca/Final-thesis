#include "histogram.h"


void initHistogram(histogram* h, double range, unsigned int size){
	h->size = size;
	h->range = range;
	h->delta_x = (2.0*range)/(double)size;
	h->histo = calloc(size,sizeof(unsigned int));
	/*for(int i = 0; i<size; ++i){
		h->histo[i] = 0;
	}*/
//	printf("Hola");
	h->iterations = 0;
}


void addDensityProfile(histogram* h, state* s){
 double x;
 double center = centerOfMases(s);
 int index;
 for(int i = 0; i < N; i++){
   x = s->particle_coords[i].x - center;
   x += h->range;
   index = (int)(x/h->delta_x);  //20/
   if(index > 0  && index < h->size){
     h->histo[index]++; //TODO: index   (-1,1) -> 0
    }
  }
  ++h->iterations;
}

void addDistributionFunction(histogram* h, state* s){
	double x;
	int index;
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			x = dist(s->particle_coords[i], s->particle_coords[j]);
			index = (int)(x/h->delta_x);
			if(index > 0 && index < h->size){
				h->histo[index]++;
			}
		}
	}
	++h->iterations;
}
// normalization: N(N-1)/2
// double the range 


//void addEnergy()


void printHistogram(histogram* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)h->iterations * h->delta_x);  //(10/(1000000*0.x)) // (N/(it*d))-> d/(it*N)
//	printf("N: %f\n", normalization );
	if(fp == NULL){
    		for(int i = 0; i<h->size; i++){
        		printf("%f: %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)h->histo[i] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
    		}
	}
	else{
    		for(int i = 0; i<h->size; i++){
			fprintf(fp, "%f: %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)h->histo[i] * normalization);
    		}

	}
    //printf("norm: %f\n", normalization);
}
