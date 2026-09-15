#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int world_rank;
    int world_size;
    int number;

    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0)
    {
        printf("MASTER: sending values...\n");

        for (int i = 1; i < world_size; i++)
        {
            number = i * 10;

            MPI_Send(
                &number,
                1,
                MPI_INT,
                i,
                0,
                MPI_COMM_WORLD
            );
        }
    }
    else
    {
        MPI_Recv(
            &number,
            1,
            MPI_INT,
            0,
            0,
            MPI_COMM_WORLD,
            MPI_STATUS_IGNORE
        );

        printf("CHILD %d received: %d\n", world_rank, number);
    }

    MPI_Finalize();

    return 0;
}
