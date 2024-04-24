#include <stdio.h>
#include <mpi.h>
#include <math.h>

double f(double x) {
    return exp(-tan(0.8 * x)) / (1.35 + cos(x));
}

double integrate(double a, double b, int n) {
    double h = (b - a) / (3 * n);
    double sum = 0.0;
    
    for (int i = 1; i <= ((3 * n) - 1); i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x);
        }
        else {
            sum += 3 * f(x);
        }
    }
    
    return ((b - a)/(8 * n))*(f(a) + f(b) + sum);
}

int main(int argc, char** argv) {
    int rank, size;
    double a = 2.5, b = 5;
    int n = 1000;
    
    double result, local_result;
    double start_time, end_time;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    int local_n = n / size;
    
    MPI_Barrier(MPI_COMM_WORLD);
    start_time = MPI_Wtime();
        
    local_result = integrate(a + (rank * (b - a) / size), a + ((rank + 1) * (b - a) / size), local_n);

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
