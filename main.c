#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "montecarlo/montecarlo.h"

double a = 100.0;
unsigned int N = 10;

int main(int argc, char** argv){
	srand(1111);
	if(argc > 1){ //N
		int t;
		 sscanf(argv[1],"%d", &t);
		if(t>0) N = t;
		else return 0;
	}
	if(argc > 2){ //a
		 sscanf(argv[2],"%lf", &a);
	}


	double initial_dispersion = a/(2.0*N);  //particle spawn (-initial_dispersion,initial dispersion)
	unsigned int histogram_range = (int) a+1;//15; //[-r,r]
	unsigned int histogram_size = 100;//1/N //1 -> -50, -49,.., 49,50; 10 -> -50, -49.9,...,49.9,50; ...



	char str[256];
	sprintf(str, "out%d-%f.dat", N,a);
	if(argc > 3){
		sprintf(str, "%s", argv[3]);
		
	}

	FILE *fp;	
	fp = fopen(str, "w");
	montecarlo* mc = montecarloInit(initial_dispersion, histogram_size, histogram_range);
//McGuire(x) = ((N-1)/cosh(((N-1)*x)/a)**2)/(2.*a)


	runNSteps(mc,1000000);
	printHistogram(mc->histo, fp);
	fclose(fp);
//	printf("----------------------------------------------------------------------------------\n");
//	for (int i  =0; i< N; ++i){
//		printf("%f\n",mc->state->particle_coords[i].x);
//	}
//	printf("----------------------------------------------------------------------------------\n");
	
//	printf("Accrptance ratio: %lf\n", 1.-(double)mc->state->rejected/(double)mc->state->tryed);
	//printf("Rejected: %d\n", mc->state->rejected);
//	printf("%f\n",centerOfMasesStateI(mc));
	printf("Done: out%d-%f.dat\n", N, a);	
}
