# serial_optimization
Task 1) Write a benchmark implementing problem 2.1 (The perils of branching.) from the HPC book. Compare the performance of the 3 scenarios described for the various memory situations.

 

Task 2) Benchmark the following operation, then optimize it. Your code should include a test to verify functionality.  Write about your findings. My optimized version of this routine runs in 2.3 seconds.

#define N = 16384;
double *A = new double[N*N];
double *B = new double[N*N];


// begin my operation
for (int y = 0; y < N; y++)
   for (int x = 0; x < N; x++)
       B[(x * N) + y] = A[(y * N) + x];
// end my operation
