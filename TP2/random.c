#include "random.h"
#include <stdlib.h>

double random_double(double a, double b){

    double valeur = (((double)rand() / (double)RAND_MAX) * (b - a)) + a;
    return valeur;
}

float random_float(float a, float b){

    float valeur = (((float)rand() / (double)RAND_MAX) * (b - a)) + a;
    return valeur;
}

size_t random_size_t(size_t a, size_t b){

    size_t valeur = (((size_t)rand() / (double)RAND_MAX) * (b - a)) + a;
    return valeur;
}

int random_int(int a, int b){
    int valeur = ((rand() / (double)RAND_MAX) * (b - a)) + a;
    return valeur;
}

char random_char(char a, char b){
    char valeur = ((rand() / (double)RAND_MAX) * (b - a)) + a;
    return valeur;
}

void random_init_string(char * c, size_t n){

    for (int i = 0; i < (int)n; i++){
        c[i] = random_char('A', 'Z');
    }
}

