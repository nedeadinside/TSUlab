#include <stdio.h>
#include <mpi.h>
#include <math.h>

double f(double x, double y) {
    return sqrt(x*x + 2*y*y + 2.04)/sqrt(1 + y*y);
}

double integrate(double a, double b, double y, int n) {
    double h = (b - a) / (3 * n);
    double sum = 0.0;
    
    for (int i = 1; i <= ((3 * n) - 1); i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x, y);
        }
        else {
            sum += 3 * f(x, y);
        }
    }
    
    return ((b - a)/(8 * n))*(f(a, y) + f(b, y) + sum);
}

double doubleIntegrate(double a, double b, double c, double d, int n) {
    double result = 0.0;
    double h = (d - c) / (3 * n);
    
    for (int i = 1; i <= ((3 * n) - 1); i++) {
        double y = c + i * h;
        if (i % 3 == 0) {
            result += 2 * integrate(a, b, y, n);
        }
        else {
            result += 3 * integrate(a, b, y, n);
        }
    }
    
    return ((d - c)/(8 * n))*(integrate(a, b, c, n) + integrate(a, b, d, n) + result);
}


int main(int argc, char** argv) {
    int rank, size;
    double a = -1, b = 4;
    double c = 0, d = 3;

    int n = 10000;
    
    double result, local_result;
    double start_time, end_time;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    int local_n = n / size;
    
    MPI_Barrier(MPI_COMM_WORLD);
    start_time = MPI_Wtime();
        
    local_result = doubleIntegrate(a + (rank * (b - a) / size), a + ((rank + 1) * (b - a) / size),
     c + (rank * (d - c) / size), c + ((rank + 1) * (d - c) / size), local_n);

    end_time = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Reduce(&local_result, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    
    if (rank == 0) {
	    printf("Size: %d \n", size);
        printf("Result: %.10f \n", result);
        printf("Time: %f seconds\n", end_time - start_time);
    }
    
    MPI_Finalize();
    
    return 0;
}
