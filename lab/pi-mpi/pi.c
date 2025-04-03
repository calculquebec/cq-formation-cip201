#include <math.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int randlcg(int* state)
{
	int new_state = ((*state) * 1103515245 + 12345);
	*state = new_state;
	return new_state & RAND_MAX;
}

double monte_carlo_pi(unsigned long long n, MPI_Comm comm)
{
	unsigned long long local_p = 0;
	int nranks, rank;
	MPI_Comm_size(comm, &nranks);
	MPI_Comm_rank(comm, &rank);
	int rand_state = rank;
	double x, y;
	for (unsigned long long i = rank; i < n; i += nranks)
	{
		x = (double) randlcg(&rand_state) / RAND_MAX;
		y = (double) randlcg(&rand_state) / RAND_MAX;
		if (sqrt(x*x + y*y) <= 1.0)
		{
			local_p++;
		}
	}
	unsigned long long p;
	MPI_Allreduce(&local_p, &p, 1, MPI_UNSIGNED_LONG_LONG, MPI_SUM, comm);
	return 4*((double)p)/n;
}

int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (argc > 2)
	{
		if (rank == 0)
		{
			printf("usage: pi [n-points]\n");
		}
		MPI_Finalize();
		return 1;
	}
	else
	{
		unsigned long long n;
		if (argc == 2)
		{
			char* endptr;
			n = strtoll(argv[1], &endptr, 10);
		}
		else
		{
			n = 10000000000;
		}
		if (rank == 0)
		{
			printf("Estimating pi with %llu random points.\n", n);
		}
		double pi = monte_carlo_pi(n, MPI_COMM_WORLD);
		if (rank == 0)
		{
			printf("Pi estimate is %f.\n", pi);
		}
		MPI_Finalize();
		return 0;
	}
}
