#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "montecarlo/montecarlo.h"
#include "measurements/measurements.h"
#include <math.h>

double a = 100.0;
unsigned int N = 10;
#if TRIDIM == 1
double Ap = 0.0;
double a1D;
#endif

 measurements* h;
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
#if TRIDIM == 1
		 a1D = -(1.0/a-1.0326);
#endif
	}


	double initial_dispersion = fabs(a)/(2.0*N);  //particle spawn (-initial_dispersion,initial dispersion)
#if TRIDIM == 1
	double histogram_range = ( a/((double)(N-1)))*10.0;
#else
	double histogram_range =  (fabs(a)/((double)(N-1)))*3.0; //[-r,r]
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
	sprintf(str, "energy.dat");
	FILE *fp_ene;	
	fp_ene = fopen(str, "a");


	sprintf(str, "dp2D%d-%.2f.dat", N,a);
	FILE *fp_dp2D;	
	fp_dp2D = fopen(str, "w");

	sprintf(str, "dp2DCastin%d-%.2f.dat", N,a);
	FILE *fp_dp2DCastin;	
	fp_dp2DCastin = fopen(str, "w");
	
	sprintf(str, "dpDiag1-%d-%.2f.dat", N,a);
	FILE *fp_dpDiag1;	
	fp_dpDiag1 = fopen(str, "w");
	
	sprintf(str, "dpDiag2-%d-%.2f.dat", N,a);
	FILE *fp_dpDiag2;	
	fp_dpDiag2 = fopen(str, "w");

	unsigned int total_iterations = 10000000;
	unsigned int measurements = 1000000; 

	montecarlo* mc = montecarloInit(initial_dispersion);

	h  = measurementsInit(histogram_range, histogram_size); //[-10.0, 10.0]

	double energy = 0.0;
	for (int i = 0; i<measurements; ++i){
		runNSteps(mc,total_iterations/measurements);
 		addIteration(h, mc->state);
		energy +=  getEnergy(mc->state);
	} 


	fprintf(fp_ene,"%d %lf %lf \n", N, a, energy/measurements);
	printf("AR N=%d a=%lf ar=%lf\n", N,a, acceptanceRatio(mc->state));
	printDensityProfileX(h, fp_dpX);
#if TRIDIM == 1
	printDensityProfileY(h, fp_dpY);
        printDensityProfileZ(h, fp_dpZ);
#else
	printDensityProfile2D(h, fp_dp2D);
	printDensityProfile2DCastin(h, fp_dp2DCastin);
	printDensityProfile2DDiag1(h, fp_dpDiag1);
	printDensityProfile2DDiag2(h, fp_dpDiag2);
#endif
	fclose(fp_dpX);
#if TRIDIM == 1
	fclose(fp_dpY);
	fclose(fp_dpZ);
#endif
	fclose(fp_ene);
	fclose(fp_dp2D);
	fclose(fp_dp2DCastin);
	fclose(fp_dpDiag1);
	fclose(fp_dpDiag2);
	
	printf("Done: out%d-%.2f.dat\n", N, a);	
}
