#include <math.h>
#include <stdio.h>

double E;

double c;

double castin2D (double x, double y){
	double x1 = x/E;
	double y1 = y/E;
	double a = (2.0+fabs(x1-y1)) * sinh(x1/2.0) * sinh(y1/2.0) + 2.0*sinh(fabs(x1-y1)/2.0);
	double b = pow(cosh(x1/2.0)*cosh(y1/2.0),3);
	return c*a/b;


}

int main (int argc, char** argv) {
	unsigned int N;
	double a;
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
	c = -N/(16.0*E*E);

	char str[256];
	sprintf(str, "dp2D-Castin-%d-%.2f.dat",N,a);
        FILE *fp_dp;
        fp_dp = fopen(str, "w");

	int size = 250;
	double range = (a/((double)(N-1)))*3.0;
	double delta_x = (2.0*range)/(double)size;


	for(int i = 0; i < size; i++){
		double x = (double)i*delta_x - range + 0.5 * delta_x;
        	for(int j = 0; j < size; j++){
			double y =  (double)j*delta_x - range + 0.5 * delta_x;
                	fprintf(fp_dp,"%f %f %f \n", x, y, castin2D(x,y));
		}
                fprintf(fp_dp,"\n");
        }













	fclose(fp_dp);
}
