#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "montecarlo/montecarlo.h"

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
	sprintf(str, "out%d-%f.dat", N,a);

	FILE *fp;	
	fp = fopen(str, "w");



	//new class (experiment)-------------------------------
	montecarlo* mc = montecarloInit(initial_dispersion, histogram_size, histogram_range);


	runNSteps(mc,1000000);
	/*
	
	for (nmedidas){
	 	run N step
	 	get metrics(energy, pairs, histo, ...)
	} 
	*/
	//energy to array, energy write directly


	printHistogram(mc->histo, fp);
	//------------------------------------------
	fclose(fp);
	
	printf("Done: out%d-%f.dat\n", N, a);	
}
