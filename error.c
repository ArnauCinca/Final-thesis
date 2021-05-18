#include <stdio.h>
#include <math.h>

int N;
double a;
int mf;
//McGuire(x) = ( (N-1) / cosh( ( (N-1)*x )/a )**2)/(2.*a)
double mcGuire(double x){
	double c = cosh(((float)(N-1)*x)/a);
	double i = ((double)(N-1)/(c*c));
 	return i/(2.0*a);
}

int main(int argc, char** argv){

    if(argc > 1){ //a
         sscanf(argv[1],"%d", &mf);
    }


	int n[7] = {2,4,6,8,10,20,100};
    FILE *fp_dp;
    FILE *out;
	char str[256];
	sprintf(str, "mf%d_error.dat", mf);
    out = fopen(str, "w");
	for(int j = 0; j<7; ++j){
		N = n[j];
		a = ((double)N-1.0)/(double)mf;
		sprintf(str, "mf%d/dpX%d-%.2f.dat", mf,N,a);
    	fp_dp = fopen(str, "r");

		double x, value;
		double error_add = 0;
		int i = 0;
		double delta_x = -1.0;
		double min;
		while(fscanf(fp_dp, "%lf: %lf\n", &x, &value) > 0) {  	//get index
			error_add +=  fabs(value - mcGuire(x));
			if(i == 0) min = x;
			i++;
		}
		printf("%d %lf %lf", i, min, x);
		delta_x = (x - min)/(i);
		fprintf(out, "%d: %lf\n",N, error_add*delta_x);

		fclose(fp_dp);
	}
	fclose(out);
}
