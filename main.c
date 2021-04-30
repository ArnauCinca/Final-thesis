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
#if TRIDIM == 1
	double histogram_range = 3.0;//( a/((double)(N-1)));
#else
	double histogram_range =  (a/((double)(N-1)))*3.0; //[-r,r]
#endif
	unsigned int histogram_size = 100;



	char str[256];

	sprintf(str, "dpX%d-%.2f.dat", N,a);
	FILE *fp_dpX;	
	fp_dpX = fopen(str, "w");
#if TRIDIM == 1
 	sprintf(str, "dpY%d-%.2f.dat", N,a);
        FILE *fp_dpY;
        fp_dpY = fopen(str, "w");

       	sprintf(str, "dpZ%d-%.2f.dat", N,a);
        FILE *fp_dpZ;
        fp_dpZ = fopen(str, "w");
#endif
	sprintf(str, "dist%d-%.2f.dat", N,a);
	FILE *fp_dist;	
	fp_dist = fopen(str, "w");

	sprintf(str, "energy%d-%.2f.dat", N,a);
	FILE *fp_ene;	
	fp_ene = fopen(str, "w");


	sprintf(str, "dp2D%d-%.2f.dat", N,a);
	FILE *fp_dp2D;	
	fp_dp2D = fopen(str, "w");
	
	sprintf(str, "dpDiagi1-%d-%.2f.dat", N,a);
	FILE *fp_dpDiag1;	
	fp_dpDiag1 = fopen(str, "w");
	
	sprintf(str, "dpDiag2-%d-%.2f.dat", N,a);
	FILE *fp_dpDiag2;	
	fp_dpDiag2 = fopen(str, "w");

	unsigned int total_iterations = 1000000;
	unsigned int measurements = 100000; 
	//new class (experiment)-------------------------------
	montecarlo* mc = montecarloInit(initial_dispersion);
	histogram* dpX = densityProfileXInit(histogram_range, histogram_size); //[-10.0, 10.0]
#if TRIDIM == 1
        histogram* dpY = densityProfileYInit(histogram_range, histogram_size); //[-10.0, 10.0]
        histogram* dpZ = densityProfileZInit(histogram_range, histogram_size); //[-10.0, 10.0]
#endif
	histogram* dist = distributionInit(histogram_range, histogram_size); //[-10.0, 10.0]
	histogram* heatmap = densityProfile2DInit(histogram_range, histogram_size); //[-10.0, 10.0]


	
	double center;
	for (int i = 0; i<measurements; ++i){
		runNSteps(mc,total_iterations/measurements);
#if TRIDIM == 1
		center = 0.0;
#else
		center = centerOfMases(mc->state);
#endif
 		dpX->addIteration(dpX, mc->state, center);
#if TRIDIM == 1
                dpY->addIteration(dpY, mc->state, center);
                dpZ->addIteration(dpZ, mc->state, centerOfMases(mc->state));
#endif
 		dist->addIteration(dist, mc->state, center);
		fprintf(fp_ene, "%d: %f\n", i, getEnergy(mc->state));
		heatmap->addIteration(heatmap,mc->state, center);
	 	//get metrics(energy, pairs, histo, ...)
	} 
	//energy to array, energy write directly

	printf("AR N=%d a=%lf ar=%lf\n", N,a, acceptanceRatio(mc->state));
	printDensityProfile(dpX, fp_dpX);
#if TRIDIM == 1
	printDensityProfile(dpY, fp_dpY);
        printDensityProfile(dpZ, fp_dpZ);
#endif
	printDistribution(dist, fp_dist);
	printDensityProfile2D(heatmap, fp_dp2D);
	printDensityProfile2DDiag1(heatmap, fp_dpDiag1);
	printDensityProfile2DDiag2(heatmap, fp_dpDiag2);
	//------------------------------------------
	fclose(fp_dpX);
#if TRIDIM == 1
	fclose(fp_dpY);
	fclose(fp_dpZ);
#endif
	fclose(fp_dist);
	fclose(fp_ene);
	fclose(fp_dp2D);
	fclose(fp_dpDiag1);
	fclose(fp_dpDiag2);
	
	printf("Done: out%d-%.2f.dat\n", N, a);	
}
