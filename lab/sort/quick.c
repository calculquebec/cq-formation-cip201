#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N_MIN 1ul
#define N_MAX 256000000ul


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


void quick_sort(int * vect, unsigned long n)
{
    if (n <= 1) return;

    int pivot = vect[n - 1], tmp;
    unsigned long p = 0, i;

    for (i = 0; i < n; ++i) {
        if (vect[i] <= pivot) {
            tmp = vect[p];
            vect[p] = vect[i];
            vect[i] = tmp;
            p++;
        }
    }

    quick_sort(&vect[0], p - 1);
    quick_sort(&vect[p], n - p);
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

    quick_sort(vect, n);
    printf("%d <= %d\n", vect[0], vect[n - 1]);

    free(vect);

    return 0;
}
