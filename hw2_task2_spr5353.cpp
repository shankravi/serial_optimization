#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
void get_walltime(double* wcTime) { //function used to get the run time
	struct timeval tp;
	gettimeofday(&tp, NULL);
	*wcTime = (double)(tp.tv_sec + tp.tv_usec / 1000000.0);
}
int main() {


	double start, end;
	#define N 16384
	#define block_size 128 //set to square root of 16384  
	double *A, *B;
	A = new double[N*N]; //initialize array A
	B = new double[N*N]; //initialize array B

	int x_n, y_n, x, y;
	x_n = 0;
	y_n = 0;

	get_walltime(&start); //start timer
	//using loop blocking from pg 82 of the textbook, I used loop blocking method
	for (y = 0; y < N; y += block_size) {
		for (x = 0; x < N; x += block_size) {
			for (int i = y; i<y + block_size; i++) {
				for (int j = x; j<block_size + x; j++) {
					B[(j*N) + i] = A[(i*N) + j];
				}
			}
		}
	}

	get_walltime(&end);//end timer
	cout << "run time=" << (end - start) << "\n";

	return 0;
}
