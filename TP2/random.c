#include "random.h"
#include <stdlib.h>

double random_double(double a, double b){

    double valeur = ((double)rand() * (b - a) / (double)RAND_MAX) + a;
    return valeur;
}

float random_float(float a, float b){

    float valeur = ((float)rand() * (b - a) / (float)RAND_MAX) + a;
    return valeur;
}

size_t random_size_t(size_t a, size_t b){

    size_t valeur = ((size_t)rand() * (b - a) / (size_t)RAND_MAX) + a;
    return valeur;
}

int random_int(int a, int b){
    int valeur = (rand() * (b - a) / RAND_MAX) + a;
    return valeur;
}

char random_char(char a, char b){

}

void random_init_string(char * c, size_t n){

}

