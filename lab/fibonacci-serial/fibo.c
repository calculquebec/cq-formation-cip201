#include <stdlib.h>
#include <stdio.h>

unsigned long fibonacci(unsigned int nth)
{
	if (nth == 0)
	{
		return 0;
	}
	else if (nth == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(nth - 1) + fibonacci(nth - 2);
	}
}

int main(int argc, char* argv[])
{
	if (argc > 2)
	{
		printf("usage: fibo [nth-number]\n");
		return(1);
	}
	else
	{
		unsigned int nth;
		if (argc == 2)
		{
			nth = atoi(argv[1]);
		}
		else
		{
			nth = 50;
		}
		printf("Computing the %uth Fibonacci number.\n", nth);
		printf("The %uth Fibonacci number is %lu.\n", nth, fibonacci(nth));
		return 0;
	}
}
