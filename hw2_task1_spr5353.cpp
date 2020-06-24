#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
void get_walltime(double* wcTime) { //function used to get the run time
	struct timeval tp;
	gettimeofday(&tp, NULL);
	*wcTime = (double)(tp.tv_sec + tp.tv_usec / 1000000.0);
}

void dummy(double *A, double *B, double *C, double *D)
{
	return;
}

double gen_rand() {
	int min = -1;
	int max = 1;
	float r = (float)rand() / (float)RAND_MAX;
	return (min + r * (max - min));
}

int main() {

	int N = 10, R = 1000000;//start N and R with these values
	double *A, *B, *C1, *C2, *C3, *D;
	double start, end, MFLOPS;

	for (int i = 0; i <= 32; i++) {

		if (i == 32) { //for the last loop set N and R
			N = 1000000;
			R = 100;
		}

		A = new double[N];
		B = new double[N];
		C1 = new double[N];
		C2 = new double[N];
		C3 = new double[N];
		D = new double[N];

		for (int i = 0; i < N; i++)
		{
			A[i] = 0.0;
			B[i] = 1.0;
			D[i] = 3.0;
		}

		for (int i = 0; i < N; i++) {//C set to positive values 
			C1[i] = i;
		}

		for (int i = 0; i < N; i++) {//C set to negative values 
			C2[i] = i*(-1);

		}
		for (int i = 0; i < N; i++) {//C set to random values -1 to +1
			C3[i] = gen_rand();


		}

		get_walltime(&start); // start timer C1
		for (int j = 0; j < R; j++)
		{
			for (int i = 0; i < N; i++) {
				if (C1[i] < 0)
				{
					A[i] = B[i] - C1[i] * D[i];
				}
				else
				{
					A[i] = B[i] + C1[i] * D[i];

				}
			}
			if (A[2] < 0) dummy(A, B, C1, D);

		}
		get_walltime(&end); //end timer
		MFLOPS = (double)R*(double)N*2.0 / ((end - start)*1000000.0); //calculate MFLOPS

		cout << "Positive C" << endl;
		cout << "R=" << R << " N=" << N << " Time=" << (end - start) << " MFLOPS=" << MFLOPS << "\n";

		get_walltime(&start); // start timer for C2
		for (int j = 0; j < R; j++)
		{
			for (int i = 0; i < N; i++) {
				if (C2[i] < 0)
				{
					A[i] = B[i] - C2[i] * D[i];
				}
				else
				{
					A[i] = B[i] + C2[i] * D[i];

				}
			}
			if (A[2] < 0) dummy(A, B, C2, D);

		}
		get_walltime(&end); //end timer

		MFLOPS = (double)R*(double)N*2.0 / ((end - start)*1000000.0); //calculate MFLOPS
		cout << "Negative C" << endl;
		cout << "R=" << R << " N=" << N << " Time=" << (end - start) << " MFLOPS=" << MFLOPS << "\n";

		get_walltime(&start); // start timer for C3
		for (int j = 0; j < R; j++)
		{
			for (int i = 0; i < N; i++) {
				if (C3[i] < 0)
				{
					A[i] = B[i] - C3[i] * D[i];
				}
				else
				{
					A[i] = B[i] + C3[i] * D[i];

				}
			}
			if (A[2] < 0) dummy(A, B, C3, D);

		}
		get_walltime(&end); //end timer

		MFLOPS = (double)R*(double)N*2.0 / ((end - start)*1000000.0); //calculate MFLOPS
		cout << "Random C between -1 and 1" << endl;
		cout << "R=" << R << " N=" << N << " Time=" << (end - start) << " MFLOPS=" << MFLOPS << "\n";


		delete[] A;
		delete[] B;
		delete[] C1;
		delete[] C2;
		delete[] C3;
		delete[] D;

		N = N*1.44; //increase N by 44% every loop
		R = R*0.75; //reduce R by 25% every loop

	}
	return 0;
}


