#include "histogram.h"
#include <stdio.h>


void initHistogram(histogram* h, unsigned int histogram_resolution, unsigned int histogram_range){
	h->histogram_resolution = histogram_resolution;
	h->histogram_range = histogram_range;
	h->histo = malloc((2*50*histogram_resolution+1)* sizeof(unsigned int));
	for(int i = 0; i<2*50*histogram_resolution+1; ++i){
		h->histo[i] = 0;
	}
	h->steps = 0;
}
void addStep(histogram* h, state* s){
 double x;
 double center = centerOfMases(s);
 for(int i = 0; i< N; i++){
   x = s->particle_coords[i].x - center;
   if(x > -50  && x < 50){
     h->histo[(int)(x*h->histogram_resolution)+50*h->histogram_resolution]++; //TODO: index
    }
  }
  ++h->steps;
}
void printHistogram(histogram* h){
    double normalization = 0.0;
    for(int i = 0; i<2*50*h->histogram_resolution+1; ++i){
        normalization += (double)(h->histo[i] * h->histogram_resolution)/(double)(h->steps);
        printf("%f: %f \n", (double)(i)/h->histogram_resolution-50.0, (double)(h->histo[i] * h->histogram_resolution)/(double)(h->steps));
    }
    normalization /=  (double)h->histogram_resolution;   //1/def
    printf("norm: %f\n", normalization);



}
