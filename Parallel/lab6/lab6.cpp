﻿#include <stdio.h>
#include <omp.h>
#include <math.h>

#define NUM_THREADS 8

double f(double x) {
    return exp(-tan(0.8 * x)) / (1.35 + cos(x));
}

double integrate(double a, double b, int n) {
    double h = (b - a) / (3 * n);
    double sum = 0.0;

#pragma omp parallel for reduction(+:sum) num_threads(NUM_THREADS)
    for (int i = 1; i <= ((3 * n) - 1); i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x);
        }
        else {
            sum += 3 * f(x);
        }
    }

    return ((b - a) / (8 * n)) * (f(a) + f(b) + sum);
}

int main(int argc, char** argv) {
    double a = 2.5, b = 5;
    int n = 100000;
    int size = 0;

    double result;
    double start_time, end_time;

    #pragma omp parallel num_threads(NUM_THREADS) private(result, start_time, end_time)
    {
        start_time = omp_get_wtime();

        result = integrate(a, b, n);

        end_time = omp_get_wtime();

        size = NUM_THREADS;

        #pragma omp critical
        {
            printf("Size: %d \n", size);
            printf("Result: %.10f \n", result);
            printf("Time: %f seconds\n", end_time - start_time);
        }
    }

    return 0;
}