#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int world_rank;
    int world_size;

    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    printf("Process %d of %d\n", world_rank, world_size);

    MPI_Finalize();

    return 0;
}
