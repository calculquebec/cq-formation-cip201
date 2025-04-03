#include <math.h>
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

int randlcg(int* state)
{
	int new_state = ((*state) * 1103515245 + 12345);
	*state = new_state;
	return new_state & RAND_MAX;
}


double monte_carlo_pi(unsigned long long n)
{
	unsigned long long p = 0;
	#pragma omp parallel reduction(+:p)
	{
		int nthreads = omp_get_num_threads();
		int thread = omp_get_thread_num();
		int rand_state = thread;
		double x, y;
		for (unsigned long long i = thread; i < n; i+= nthreads)
		{
			x = (double) randlcg(&rand_state) / RAND_MAX;
			y = (double) randlcg(&rand_state) / RAND_MAX;
			if (sqrt(x*x + y*y) <= 1.0)
			{
				p++;
			}
		}
	}
	return 4*((double)p)/n;
}

int main(int argc, char* argv[])
{
	if (argc > 2)
	{
		printf("usage: pi [n-points]\n");
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
		printf("Estimating pi with %llu random points.\n", n);
		double pi = monte_carlo_pi(n);
		printf("Pi estimate is %f.\n", pi);
		return 0;
	}
}
