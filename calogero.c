#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double a = 100.0;
unsigned int N = 10;
double E;
double p;
double* s1;

double fact(double n){
	if(n == 0) return 1;
	else return n*fact(n-1);

}



double calogero(double x){
	double s = 0.0;
	for(int k = 0; k <= N-2; ++k)
		s += s1[k] * exp(-(k+1)*fabs(x)/E);

	return p*s/(double)N;
}

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

	E = a/ (2.0*N);

	p = pow(fact(N),2)/(N*E);


	s1 = malloc((N-1)*sizeof(double));
	for(int k = 0; k <= N-2; ++k)
		s1[k] = (pow(-1,k) * (k+1))/(fact(N-2-k) * fact(N+k));

	double range =  (a/((double)(N-1)))*3.0; //[-r,r]
	unsigned int size = 250;

	double delta_x = (2.0*range)/size;
	char str[256];
	sprintf(str, "dpCalo%d-%.2f.dat", N,a);

	FILE *fp_dp;	
	fp_dp = fopen(str, "w");
	
	double x;
	for(int i = 0; i<size; ++i){
		x =  (double)i*delta_x - range + 0.5 * delta_x;
       		fprintf(fp_dp,"%f: %f \n", x, calogero(x));
	}

	//------------------------------------------
	fclose(fp_dp);
}
