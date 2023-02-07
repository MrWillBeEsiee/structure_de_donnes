#include "../headers/random.h"
#include <stdlib.h>

//retourne un nombre aléatoire de type double compris entre a inclus et b exclu
double random_double(double a, double b){

    if (a > b) {
        printf("min>max\n");
        return 0;

    double valeur = (((double)rand() / (double)RAND_MAX) * (b - a)) + a;
    return valeur;
}

//Retourne un nombre aléatoire de type float compris entre a inclus et b exclu
float random_float(float a, float b){
    if (a > b) {
        printf("min>max\n");
        return 0;
    }

    float valeur = (((float)rand() / (double)RAND_MAX) * (b - a)) + a;
    return valeur;
}
//retourne un nombre aléatoire de type int compris entre a inclus et b exclu
size_t random_size_t(size_t a, size_t b){
    if (a > b) {
        printf("min>max\n");
        return 0;
    }

    size_t valeur = (((size_t)rand() / (double)RAND_MAX) * (b - a)) + a;
    return valeur;
}

//retourne un nombre aléatoire de type int compris entre a inclus et b exclu
int random_int(int a, int b){
    if (a > b) {
        printf("min>max\n");
        return 0;
    }

    int valeur = ((rand() / (double)RAND_MAX) * (b - a)) + a;
    return valeur;
}

//retourne un nombre aléatoire de type unsigned char compris entre a inclus et b exclu
char random_char(char a, char b){
    char valeur = ((rand() / (double)RAND_MAX) * (b - a)) + a;
    return valeur;
}

//remplit la chaîne de caractère c de lettre majuscule aléatoire,n est la taille du tableau pointé par le pointeur c
void random_init_string(char * c, size_t n){
    for (int i = 0; i < (int)n; i++){
        c[i] = random_char('A', 'Z');
    }
}

