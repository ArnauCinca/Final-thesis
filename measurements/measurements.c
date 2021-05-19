#include "measurements.h"
#include <math.h>


double fact(double n){
        if(n == 0) return 1;
        else return n*fact(n-1);

}



double castin(double x){
        double s = 0.0;
        for(int k = 0; k <= N-2; ++k)
                s += s1[k] * exp(-(k+1)*fabs(x)/E);

        return p*s/(double)N;
}




void addIteration(measurements* h, state* s){
#if TRIDIM == 1
	double x,y,z;
	double center = centerOfMases(s);
        int index_x,index_y,index_z;
        for(int i = 0; i < N; i++){
		x = s->particle_coords[i].x + h->range;
		y = s->particle_coords[i].y + h->range;
		z = s->particle_coords[i].z - center + h->range;
		index_x = (int)(x/h->delta_x);
                index_y = (int)(y/h->delta_x);
                index_z = (int)(z/h->delta_x);
                if(index_x >= 0 && index_x < h->size)
                        h->histoX[index_x]++;
                if(index_y >= 0 && index_y < h->size)
                        h->histoY[index_y]++;
                if(index_z >= 0 && index_z < h->size)
                        h->histoZ[index_z]++;

	}
	++h->iterations;
#else
	double x, y;
	double center = centerOfMases(s);
	int index_x,index_y;
    	for(int i = 0; i < N; i++){
        	x = s->particle_coords[i].x - center;
                x += h->range;
            	index_x = (int)(x/h->delta_x);
		if(index_x >= 0 && index_x < h->size){
     			h->histoX[index_x]++;
                	for(int j = i+1; j < N; j++){
                        	y = s->particle_coords[j].x - center;
               			y += h->range;
                	        index_y = (int)(y/h->delta_x);
        	        	if(index_y >= 0 && index_y < h->size){
                        		h->heatmap[index_x][index_y]++;
                        		h->heatmap[index_y][index_x]++;
                		}
                	}
		}
	}
    	++h->iterations;
#endif
}

measurements* measurementsInit(double range, unsigned int size){
	measurements*  h = malloc(sizeof(measurements));
	h->size = size;
	h->range = range;
	h->delta_x = (2.0*range)/(double)size;
	h->histoX = calloc(size,sizeof(unsigned int));
#if TRIDIM == 1
	h->histoY = calloc(size,sizeof(unsigned int));
	h->histoZ = calloc(size,sizeof(unsigned int));
#else
	h->heatmap = calloc(size,sizeof(unsigned int*));
	for (int i = 0; i < size; ++i)
		h->heatmap[i] = calloc(size,sizeof(unsigned int));

	 E = a/ (2.0*N);

        p = pow(fact(N),2)/(N*E);


        s1 = malloc((N-1)*sizeof(double));
        for(int k = 0; k <= N-2; ++k)
                s1[k] = (pow(-1,k) * (k+1))/(fact(N-2-k) * fact(N+k));
#endif
	h->iterations = 0;
	return h;
}



void printDensityProfileX(measurements* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)h->iterations * h->delta_x);
    if(fp == NULL){
        for(int i = 0; i<h->size; i++){
            printf("%f: %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)h->histoX[i] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
        }
    }
    else{
        for(int i = 0; i<h->size; i++){
            fprintf(fp, "%f: %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)h->histoX[i] * normalization);
        }
    }
}

#if TRIDIM == 1
void printDensityProfileY(measurements* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)h->iterations * h->delta_x);
    if(fp == NULL){
        for(int i = 0; i<h->size; i++){
       	    printf("%f: %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)h->histoY[i] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
        }
    }
    else{
        for(int i = 0; i<h->size; i++){
	    fprintf(fp, "%f: %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)h->histoY[i] * normalization);
        }
    }
}
void printDensityProfileZ(measurements* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)h->iterations * h->delta_x);
    if(fp == NULL){
        for(int i = 0; i<h->size; i++){
            printf("%f: %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)h->histoZ[i] * normalization ); //size = 2 r =1 -> (-1,0) ->  (-.5, 0.5)i
        }
    }
    else{
        for(int i = 0; i<h->size; i++){
            fprintf(fp, "%f: %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)h->histoZ[i] * normalization);
        }
    }
}

#else
void printDensityProfile2D(measurements* h, FILE *fp){
    double normalization = 1.0/  ((double)N  * (double)h->iterations * h->delta_x);
    if(N < 85){
        if(fp == NULL){
            for(int i = 0; i < h->size; i++){
                for(int j = 0; j < h->size; j++){
                    printf("%f %f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)j*h->delta_x - h->range + 0.5 * h->delta_x ,((double)h->heatmap[i][j]*normalization/((double)N-1.0) - castin( (double)i*h->delta_x - h->range + 0.5 * h->delta_x) * castin( (double)j*h->delta_x - h->range + 0.5 * h->delta_x)) );
                 }
                 fprintf(fp,"\n");
             }
        }
        else{
            for(int i = 0; i < h->size; i++){
                for(int j = 0; j < h->size; j++){
                     fprintf(fp,"%f %f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)j*h->delta_x - h->range + 0.5 * h->delta_x ,((double)h->heatmap[i][j]*normalization/((double)N-1.0) - castin( (double)i*h->delta_x - h->range + 0.5 * h->delta_x) * castin( (double)j*h->delta_x - h->range + 0.5 * h->delta_x)) );
                }
                fprintf(fp,"\n");
            }
        }
    }
    else{
    	if(fp == NULL){
            for(int i = 0; i < h->size; i++){
                for(int j = 0; j < h->size; j++){
                    printf("%f %f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)j*h->delta_x - h->range + 0.5 * h->delta_x ,((double)h->heatmap[i][j]*normalization/((double)N-1.0) - h->histoX[i]*normalization * h->histoX[j]*normalization) );
                }
                fprintf(fp,"\n");
            }
        }
        else{
            for(int i = 0; i < h->size; i++){
                for(int j = 0; j < h->size; j++){
                    fprintf(fp,"%f %f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, (double)j*h->delta_x - h->range + 0.5 * h->delta_x ,((double)h->heatmap[i][j]*normalization/((double)N-1.0) - h->histoX[i]*normalization * h->histoX[j]*normalization) );
                }
                fprintf(fp,"\n");
            }
        }
    }
}



void printDensityProfile2DDiag1(measurements* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)(N-1) * (double)h->iterations * h->delta_x);
    if(fp == NULL){
        for(int i = 0; i < h->size; i++){
       		printf("%f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, ((double)h->heatmap[i][h->size - i - 1] *normalization - castin( (double)i*h->delta_x - h->range + 0.5 * h->delta_x) * castin( (double)(h->size - i - 1)*h->delta_x - h->range + 0.5 * h->delta_x)));
        }
    }
    else{
        for(int i = 0; i < h->size; i++){
       		fprintf(fp,"%f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, ((double)h->heatmap[i][h->size - i - 1]  *normalization - castin( (double)i*h->delta_x - h->range + 0.5 * h->delta_x) * castin( (double)(h->size - i - 1)*h->delta_x - h->range + 0.5 * h->delta_x)));
        }
    }
}

void printDensityProfile2DDiag2(measurements* h, FILE *fp){
    double normalization = 1.0/  ((double)N * (double)(N-1) * (double)h->iterations * h->delta_x);
    if(fp == NULL){
        for(int i = 0; i < h->size; i++){
       		printf("%f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, ((double)h->heatmap[i][i]*normalization - castin( (double)i*h->delta_x - h->range + 0.5 * h->delta_x) * castin( (double)i*h->delta_x - h->range + 0.5 * h->delta_x)));
        }
    }
    else{
        for(int i = 0; i < h->size; i++){
       		fprintf(fp,"%f %f \n", (double)i*h->delta_x - h->range + 0.5 * h->delta_x, ((double)h->heatmap[i][i] *normalization - castin( (double)i*h->delta_x - h->range + 0.5 * h->delta_x) * castin( (double)i*h->delta_x - h->range + 0.5 * h->delta_x)));
        }
    }
}
#endif
