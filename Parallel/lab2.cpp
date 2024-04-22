#include <iostream>
#include <mpi.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    
    MPI_Comm comm;
    MPI_Status status;

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    comm = MPI_COMM_WORLD;

    const int m = 6;
    float Y[m], R[m], x;
    
    x = cos((rank + 1.0) * rand() / RAND_MAX);
    cout << "Rank: "<< rank <<" x: " << x << endl;
    
    for (int k = 0; k < m; k++) {
	Y[k] = cos(k * x + 1);
    }
    
    cout << "Rank: " << rank << ", Y = [";
    for (int k = 0; k < m; k++) {
	cout << " " << Y[k] << " ";
    }
    cout << "]" << endl;
    
    MPI_Scan(Y, R, m, MPI_FLOAT, MPI_SUM, comm);
    
    float max_R = R[0];
    
    for (int i = 1; i < m; i++) {
	if (R[i] > max_R) {
	    max_R = R[i];
	}
    }
	
    printf("Process %d: Max value of R is %f\n", rank, max_R);
						
    MPI_Finalize();
    return 0;
}