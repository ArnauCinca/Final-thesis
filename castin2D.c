#include <math.h>
#include <stdio.h>
#include <stdlib.h>

	unsigned int N;
	double a;
double E;

double c;
double p;
double* s1;

double fact(double n){
	if(n == 0) return 1;
	else return n*fact(n-1);
}

double castin2D (double x, double y){
	double x1 = x/E;
	double y1 = y/E;
	double a = (2.0+fabs(x1-y1)) * sinh(x1/2.0) * sinh(y1/2.0) + 2.0*sinh(fabs(x1-y1)/2.0);
	double b = pow(cosh(x1/2.0)*cosh(y1/2.0),3);
	return c*a/b;


}
double calogero(double x){
        double s = 0.0;
        for(int k = 0; k <= N-2; ++k)
                s += s1[k] * exp(-(k+1)*fabs(x)/E);

        return p*s;
}

int main (int argc, char** argv) {
	if(argc > 1){ //N
                int t;
                sscanf(argv[1],"%d", &t);
                if(t>0) N = t;
                else return 0;
        }
	 if(argc > 2){ //a
                 sscanf(argv[2],"%lf", &a);
        }
	

	E = a/(2.0*N);

	c = -((double)(N))/(16.0*E*E);


        p = pow(fact(N),2)/(N*E);


        s1 = malloc((N-1)*sizeof(double));
        for(int k = 0; k <= N-2; ++k)
                s1[k] = (pow(-1,k) * (k+1))/(fact(N-2-k) * fact(N+k));




	char str[256];
	sprintf(str, "CastinApprox%d-%.2f.dat",N,a);
        FILE *fp_dp;
        fp_dp = fopen(str, "w");

	sprintf(str, "CastinApproxDiag1-%d-%.2f.dat",N,a);
        FILE *fp_dpDiag1;
        fp_dpDiag1 = fopen(str, "w");

	sprintf(str, "CastinApproxDiag2-%d-%.2f.dat",N,a);
        FILE *fp_dpDiag2;
        fp_dpDiag2 = fopen(str, "w");

	sprintf(str, "dp2DCalo%d-%.2f.dat",N,a);
        FILE *fp_dpCalo;
        fp_dpCalo = fopen(str, "w");

	sprintf(str, "dp2DCaloDiag1-%d-%.2f.dat",N,a);
        FILE *fp_dpCaloDiag1;
        fp_dpCaloDiag1 = fopen(str, "w");

	sprintf(str, "dp2DCaloDiag2-%d-%.2f.dat",N,a);
        FILE *fp_dpCaloDiag2;
        fp_dpCaloDiag2 = fopen(str, "w");

	int size = 100;
	double range = (a/((double)(N-1)))*3.0;
	double delta_x = (2.0*range)/(double)size;


	for(int i = 0; i < size; i++){
		double x = (double)i*delta_x - range + 0.5 * delta_x;
        	for(int j = 0; j < size; j++){
			double y =  (double)j*delta_x - range + 0.5 * delta_x;
                	fprintf(fp_dp,"%f %f %f \n", x, y, castin2D(x,y)/(double)(N*(N-1)));
                	fprintf(fp_dpCalo,"%f %f %f \n", x, y, calogero(x)*calogero(y)/(double)(N*(N-1)));
		}
                fprintf(fp_dpDiag2,"%f %f\n", x, castin2D(x,x)/(double)(N*(N-1)));
                fprintf(fp_dpCaloDiag2,"%f %f \n", x, calogero(x)*calogero(x)/(double)(N*(N-1)));
                fprintf(fp_dpDiag1,"%f %f\n", x, castin2D(x,-x)/(double)(N*(N-1)));
                fprintf(fp_dpCaloDiag1,"%f %f \n", x, calogero(x)*calogero(-x)/(double)(N*(N-1)));


                fprintf(fp_dp,"\n");
                fprintf(fp_dpCalo,"\n");
        }













	fclose(fp_dp);
	fclose(fp_dpDiag1);
	fclose(fp_dpDiag2);
	fclose(fp_dpCalo);
	fclose(fp_dpCaloDiag1);
	fclose(fp_dpCaloDiag2);
}
