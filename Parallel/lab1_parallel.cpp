#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    MPI_Comm comm;
    MPI_Status status;

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    comm = MPI_COMM_WORLD;

    const int n = 5;
    float X[n];

    if (rank == size - 1) {
        for (int i = 0; i < n; i++) {
            X[i] = (float)rand() / RAND_MAX;;
        }
        cout << "Rank: "<< rank <<" Array X: ";
        for (int i = 0; i < n; i++) {
            cout << X[i] << " ";
        }
    }

    for (int i = size - 1; i > 0; i--) {
        if (rank == i) {
            MPI_Send(X, n, MPI_FLOAT, (i - 1), MPI_ANY_TAG, comm);
        }
        if (rank == i - 1) {
            MPI_Recv(X, n, MPI_FLOAT, i, MPI_ANY_TAG, comm, &status);
        }
    }

    if (rank == 0) {
        cout << "Array X on process 0: ";
        for (int i = 0; i < n; i++) {
            cout << X[i] << " ";
        }
        cout << endl;
    }

    MPI_Finalize();
    return 0;
}