# serial_optimization
optimize serial code given below using serial optimization techniques 
#define N = 16384;
double *A = new double[N*N];
double *B = new double[N*N];


// begin my operation
for (int y = 0; y < N; y++)
   for (int x = 0; x < N; x++)
       B[(x * N) + y] = A[(y * N) + x];
// end my operation
