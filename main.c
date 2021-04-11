#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "montecarlo/montecarlo.h"
#include "histogram/histogram.h"

double a = 100.0;
unsigned int N = 10;
	
//TODO: save configuration




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
	double histogram_range =  (a/((double)(N-1)))*3.0; //[-r,r]
	unsigned int histogram_size = 100;



	char str[256];
	sprintf(str, "dp%d-%.2f.dat", N,a);

	FILE *fp_dp;	
	fp_dp = fopen(str, "w");


	sprintf(str, "dist%d-%.2f.dat", N,a);
	FILE *fp_dist;	
	fp_dist = fopen(str, "w");

	sprintf(str, "energy%d-%.2f.dat", N,a);
	FILE *fp_ene;	
	fp_ene = fopen(str, "w");


	sprintf(str, "dp2D%d-%.2f.dat", N,a);
	FILE *fp_dp2D;	
	fp_dp2D = fopen(str, "w");

	unsigned int total_iterations = 1000000;
	unsigned int measurements = 100000;
	//new class (experiment)-------------------------------
	montecarlo* mc = montecarloInit(initial_dispersion);
	histogram* dp = densityProfileInit(histogram_range, histogram_size); //[-10.0, 10.0]
	histogram* dist = distributionInit(histogram_range, histogram_size); //[-10.0, 10.0]
	histogram* heatmap = densityProfile2DInit(histogram_range, histogram_size); //[-10.0, 10.0]


	
	
	for (int i = 0; i<measurements; ++i){
		runNSteps(mc,total_iterations/measurements);
 		dp->addIteration(dp, mc->state);
 		dist->addIteration(dist, mc->state);
		fprintf(fp_ene, "%d: %f\n", i, getEnergy(mc->state));
		heatmap->addIteration(heatmap,mc->state);
	 	//get metrics(energy, pairs, histo, ...)
	} 
	//energy to array, energy write directly


	printDensityProfile(dp, fp_dp);

	printDistribution(dist, fp_dist);
	printDensityProfile2D(heatmap, fp_dp2D);
	//------------------------------------------
	fclose(fp_dp);
	fclose(fp_dist);
	fclose(fp_ene);
	fclose(fp_dp2D);
	
	printf("Done: out%d-%.2f.dat\n", N, a);	
}
