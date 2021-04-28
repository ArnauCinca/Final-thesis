#include "histogram.h"

void addDensityProfileX(histogram* h, state* s){
 double x;
 double center = centerOfMases(s);
 int index;
 for(int i = 0; i < N; i++){
   x = s->particle_coords[i].x - center;
   x += h->range;
   index = (int)(x/h->delta_x);  //20/
   if(index >= 0  && index < h->size){
     h->histo[index]++; //TODO: index   (-1,1) -> 0
    }
  }
  ++h->iterations;
}
#if TRIDIM == 1

void addDensityProfileY(histogram* h, state* s){
 double y;
 double center = centerOfMases(s);
 int index;
 for(int i = 0; i < N; i++){
   y = s->particle_coords[i].y - center;
   y += h->range;
   index = (int)(y/h->delta_x);  //20/
   if(index >= 0  && index < h->size){
     h->histo[index]++; //TODO: index   (-1,1) -> 0
    }
  }
  ++h->iterations;
}

void addDensityProfileZ(histogram* h, state* s){
 double z;
 double center = centerOfMases(s);
 int index;
 for(int i = 0; i < N; i++){
   z = s->particle_coords[i].z - center;
   z += h->range;
   index = (int)(z/h->delta_x);  //20/
   if(index >= 0  && index < h->size){
     h->histo[index]++; //TODO: index   (-1,1) -> 0
    }
  }
  ++h->iterations;
}
#endif

void addDistributionFunction(histogram* h, state* s){
	double x;
	int index;
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			x = dist(s->particle_coords[i], s->particle_coords[j]);
			index = (int)(x/h->delta_x);
			if(index >= 0 && index < h->size){
				h->histo[index]++;
			}
		}
	}
	++h->iterations;
}


void addDensityProfile2D(histogram* h, state* s){
    double x, y;
	double center = centerOfMases(s);
    int index_x,index_y;
    for(int i = 0; i < N; i++){
   		x = s->particle_coords[i].x - center;
   		x += h->range;
	    index_x = (int)(x/h->delta_x);

        if(index_x >= 0 && index_x < h->size){
        	for(int j = i+1; j < N; j++){
	        	y = s->particle_coords[j].x - center;
    	    	y += h->range;
        		index_y = (int)(y/h->delta_x);

            	if(index_y >= 0 && index_y < h->size){
              		h->histo[index_x * h->size + index_y]++;
              		h->histo[index_y * h->size + index_x]++;
            	}
        	}
		}
    }
    ++h->iterations;
}

// normalization: N(N-1)/2
// double the range 

histogram* histogramInit(double range, unsigned int size){
	histogram*  h = malloc(sizeof(histogram));

	h->size = size;
	h->range = range;
	h->delta_x = (2.0*range)/(double)size;
	h->histo = calloc(size,sizeof(unsigned int));
	h->iterations = 0;
	return h;
}

histogram* densityProfileXInit(double range, unsigned int size){
	histogram*  h = malloc(sizeof(histogram));

	h->size = size;
	h->range = range;
	h->delta_x = (2.0*range)/(double)size;
	h->histo = calloc(size,sizeof(unsigned int));
	h->iterations = 0;
	h->addIteration = &addDensityProfileX;
	return h;
}
#if TRIDIM == 1
histogram* densityProfileYInit(double range, unsigned int size){
        histogram*  h = malloc(sizeof(histogram));

        h->size = size;
        h->range = range;
        h->delta_x = (2.0*range)/(double)size;
        h->histo = calloc(size,sizeof(unsigned int));
        h->iterations = 0;
        h->addIteration = &addDensityProfileY;
        return h;
}


histogram* densityProfileZInit(double range, unsigned int size){
        histogram*  h = malloc(sizeof(histogram));

        h->size = size;
        h->range = range;
        h->delta_x = (2.0*range)/(double)size;
        h->histo = calloc(size,sizeof(unsigned int));
        h->iterations = 0;
        h->addIteration = &addDensityProfileZ;
        return h;
}
#endif


histogram* distributionInit(double range, unsigned int size){
	histogram*  h = malloc(sizeof(histogram));

	h->size = size;
	h->range = range;
	h->delta_x = (range)/(double)size;
	h->histo = calloc(size,sizeof(unsigned int));
	h->iterations = 0;
	h->addIteration = &addDistributionFunction;//(Pair)
	return h;
}


histogram* densityProfile2DInit(double range, unsigned int size){
	histogram*  h = malloc(sizeof(histogram));

	h->size = size;
	h->range = range;
	h->delta_x = (2.0*range)/(double)size;
	h->histo = calloc(size*size,sizeof(unsigned int));
	h->iterations = 0;
	h->addIteration = &addDensityProfile2D;
	return h;
}




void printDensityProfile(histogram* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)h->iterations * h->delta_x);
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
}
void printDistribution(histogram* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)h->iterations * h->delta_x);
	if(fp == NULL){
   		for(int i = 0; i<h->size; i++){
       		printf("%f: %f \n", (double)i*h->delta_x + 0.5 * h->delta_x, (double)h->histo[i] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
   		}
	}
	else{
    	for(int i = 0; i<h->size; i++){
			fprintf(fp, "%f: %f \n", (double)i*h->delta_x  + 0.5 * h->delta_x, (double)h->histo[i] * normalization);
    	}
	}
}
void printDensityProfile2D(histogram* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)(N-1) * (double)h->iterations * h->delta_x);
	if(fp == NULL){
   		for(int i = 0; i < h->size; i++){
   			for(int j = 0; j < h->size; j++){
       			printf("%f %f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)j*h->delta_x - h->range + 0.5 * h->delta_x ,(double)h->histo[i*h->size + j] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
   			}
		}
	}
	else{
    	for(int i = 0; i < h->size; i++){
    		for(int j = 0; j < h->size; j++){
       			fprintf(fp,"%f %f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)j*h->delta_x - h->range + 0.5 * h->delta_x ,(double)h->histo[i*h->size + j] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
			}
			fprintf(fp,"\n");   //TODO: print function
    	}
	}
}



void printDensityProfile2DDiag1(histogram* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)(N-1) * (double)h->iterations * h->delta_x);
    if(fp == NULL){
        for(int i = 0; i < h->size; i++){
	        printf("%f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x,(double)h->histo[i*h->size + i] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
        }
    }
    else{
        for(int i = 0; i < h->size; i++){
                fprintf(fp,"%f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)h->histo[i*h->size + (h->size -i -1)] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
        }
    }
}

void printDensityProfile2DDiag2(histogram* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)(N-1) * (double)h->iterations * h->delta_x);
    if(fp == NULL){
        for(int i = 0; i < h->size; i++){
	        printf("%f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x,(double)h->histo[i*h->size + i] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
        }
    }
    else{
        for(int i = 0; i < h->size; i++){
                fprintf(fp,"%f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)h->histo[i*h->size + i] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
        }
    }
}

