#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int *generate_int_array(int size)
{
    int *intvec = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        intvec[i] = (rand() % 101) + 1;
    }

    return intvec;
}

int main(int argc, char **argv)
{
    int world_rank;
    int world_size;

    int *intvec;
    int *received_values;

    int array_size = 100;
    int chunk_size;

    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    /*
     * Precisamos de pelo menos um MASTER
     * e um CHILD.
     */
    if (world_size < 2)
    {
        printf("Run the program with at least 2 processes.\n");

        MPI_Finalize();
        return 0;
    }

    chunk_size = array_size / (world_size - 1);

    if (world_rank == 0)
    {
        printf("MASTER: Creating and sending values...\n");

        srand(100);

        intvec = generate_int_array(array_size);

        for (int i = 1; i < world_size; i++)
        {
            int begin;
            int size;

            begin = chunk_size * (i - 1);

            if (i < world_size - 1)
            {
                size = chunk_size;
            }
            else
            {
                size = chunk_size + array_size % (world_size - 1);
            }

            MPI_Send(
                &intvec[begin],
                size,
                MPI_INT,
                i,
                0,
                MPI_COMM_WORLD
            );
        }

        free(intvec);
    }
    else
    {
        int size;

        if (world_rank < world_size - 1)
        {
            size = chunk_size;
        }
        else
        {
            size = chunk_size + array_size % (world_size - 1);
        }

        received_values = malloc(sizeof(int) * size);

        MPI_Recv(
            received_values,
            size,
            MPI_INT,
            0,
            0,
            MPI_COMM_WORLD,
            MPI_STATUS_IGNORE
        );

        printf("CHILD %d received %d values:\n", world_rank, size);

        for (int i = 0; i < size; i++)
        {
            printf("%d ", received_values[i]);
        }

        printf("\n");

        free(received_values);
    }

    MPI_Finalize();

    return 0;
}
