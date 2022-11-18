#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"

int main(int argc, char*argv[]){
    srand(time(NULL));

    double a = 25.0;
    double a2 = -1.0;
    double b = 27.0;
    double b2 = 2.0;

    double test_random_double = random_double(a, b);
    if ((test_random_double < a || test_random_double >= b))
    {
        printf("\nrandom_double failure 1\n");
        return EXIT_FAILURE;
    }
    test_random_double = random_double(a2, b2);
    if ((test_random_double < a2 || test_random_double >= b2))
    {
        printf("\nrandom_double failure 2\n");
        return EXIT_FAILURE;
    }
    
    float test_random_float = random_float((float)a, (float)b);
    if ((test_random_float < (float)a || test_random_float >= (float)b))
    {
        printf("\nrandom_float failure 1\n");
        return EXIT_FAILURE;
    }
    test_random_float = random_float((float)a2, (float)b2);
    if ((test_random_float < (float)a2 || test_random_float >= (float)b2))
    {
        printf("\nrandom_float failure 2\n");
        return EXIT_FAILURE;
    }

    size_t test_random_size_t = random_size_t((size_t)a, (size_t)b);
    if ((test_random_size_t < (size_t)a || test_random_size_t >= (size_t)b))
    {
        printf("\nrandom_size_t failure 1\n");
        return EXIT_FAILURE;
    }

    int test_random_int = random_int((int)a, (int)b);
    if ((test_random_int < (int)a || test_random_int >= (int)b))
    {
        printf("\nrandom_int failure 1\n");
        return EXIT_FAILURE;
    }
    test_random_int = random_int((int)a2, (int)b2);
    if ((test_random_int < (int)a2 || test_random_int >= (int)b2))
    {
        printf("\nrandom_int failure 2\n");
        return EXIT_FAILURE;
    }

    printf("\nAll tests passed !\n");
    return EXIT_SUCCESS;
}
