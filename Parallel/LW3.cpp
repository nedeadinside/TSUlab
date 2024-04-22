#include <iostream>
#include <mpi.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

int const n = 16;

int main(int argc,char **argv) { 
	MPI_Init(&argc,&argv);
	int rank, size, tag = 1;

	MPI_Comm comm;
	MPI_Status status;

	comm = MPI_COMM_WORLD;
	
	MPI_Comm_size(comm,&size);
	MPI_Comm_rank(comm,&rank);

	int kol_group = n/(int)(log2(n));
	int kol_elem = (int)(log2(n));

	int S = rank + 1;
	int local;
	
	if (rank % kol_elem == 0) {
		MPI_Send(&S, 1, MPI_INT, rank + 1, tag, comm);
	}
	else if ((rank + 1) % kol_elem == 0) {
		MPI_Recv(&local, 1, MPI_INT, rank - 1, tag, comm, &status);
		S += local;
	}
	else {
		MPI_Recv(&local, 1, MPI_INT, rank - 1, tag, comm, &status);
		S += local;
		MPI_Send(&S, 1, MPI_INT, rank + 1, tag, comm);	
	}

	int shift = kol_elem;
	for (int level = 1; level <= kol_elem; level++) {
		if (((rank + 1) % shift == 0) && ((rank + 1) % (2 * shift) != 0) && (rank != (size - 1))) {
			MPI_Send(&S, 1, MPI_INT, rank + shift, tag, comm);
		}
		else if ((rank + 1) % (2 * shift) == 0) {
			MPI_Recv(&local, 1, MPI_INT, rank - shift, tag, comm, &status);
			S += local;
			cout << "proc #" << rank << ", S = " << S << "\n";	
		}
		shift *= 2;
	}

	MPI_Finalize();
	return 0;
}