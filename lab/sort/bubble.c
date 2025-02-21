#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N_MIN 1ul
#define N_MAX 128000ul


int * alloc_rand(unsigned long n)
{
    unsigned long i;
    int * vect = malloc(n * sizeof(int));

    srand(0x12345678);

    for (i = 0; i < n; ++i) {
        vect[i] = rand();
    }

    return vect;
}


void bubble_sort(int * vect, unsigned long n)
{
    int tmp;
    unsigned long i, nb_swapped = n - 1;

    while (nb_swapped != 0) {
        nb_swapped = 0;

        for (i = 1; i < n; ++i) {
            if (vect[i - 1] > vect[i]) {
                tmp = vect[i - 1];
                vect[i - 1] = vect[i];
                vect[i] = tmp;
                nb_swapped++;
            }
        }

        n--;
    }
}


int main(int argc, char ** argv)
{
    if (argc <= 1) {
        printf("Usage: time -p ./bubble <nb>\n");
        return 0;
    }

    unsigned long n = strtoul(argv[1], NULL, 10);

    if (n < N_MIN) {
        printf("Error: nb = %lu < %lu\n", n, N_MIN);
        return 1;
    }

    if (n > N_MAX) {
        printf("Error: nb = %lu > %lu\n", n, N_MAX);
        return 2;
    }

    int * vect = alloc_rand(n);

    bubble_sort(vect, n);
    printf("%d <= %d\n", vect[0], vect[n - 1]);

    free(vect);

    return 0;
}
