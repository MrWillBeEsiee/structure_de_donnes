#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../headers/random.h"
#include "../headers/vector.h"

//Déclarer des prototypes pour les fonctions qui effectuent différents tests
void insert_erase_random(size_t init_size, size_t n);
void insert_erase_head(size_t init_size, size_t n);
void insert_erase_tail(size_t init_size, size_t n); 
void read_write_random(size_t init_size, size_t n); 
void read_write_sequential(size_t init_size, size_t n); 
void bubble_sort(size_t init_size, size_t n);

int main(int argc, char*argv[]){
    // générateur de graine aléatoire
	srand(time(NULL));

    int init_size = 0;
    int n = 0;

    //Parse les arguments init_size et n
    sscanf(argv[2], "%d", &init_size);
    sscanf(argv[3], "%d", &n);

    printf("%d %d\n", init_size, n);

    //appelle la fonction en fonction de arg[1]
    if(strcmp(argv[1], "insert_erase_random") == 0){
        insert_erase_random(init_size, n);
    }else if(strcmp(argv[1], "insert_erase_head") == 0){
        insert_erase_head(init_size, n);
    }else if(strcmp(argv[1], "insert_erase_tail") == 0) {
        insert_erase_tail(init_size, n);
    }else if(strcmp(argv[1], "read_write_random") == 0){
        read_write_random(init_size, n);
    }else if(strcmp(argv[1], "read_write_sequential") == 0){
        read_write_sequential(init_size, n);
    }else if(strcmp(argv[1], "bubble_sort") == 0) {
        bubble_sort(init_size, n);
    }else{
        printf("Mauvais paramètre type\n");
        return 1;
    }

	return 0;
}
//alloue un vector de taille init_size et répète n-fois l’ajout et suppression d’un élément
//à des positions aléatoire
void insert_erase_random(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(size_t i = 0; i  < n; i++){
        vector_insert(testVector, random_size_t(0, init_size), random_double(0, 100));
        vector_erase(testVector, random_size_t(0, init_size));
    }
    vector_free(vector);
}

//alloue un vector de taille init_size et répète n-fois l’ajout et la suppression d’un
//élément en tête
void insert_erase_head(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(size_t i = 0; i  < n; i++){
        vector_insert(testVector, 0, random_double(0, 100));
        vector_erase(testVector, 0);
    }
    vector_free(vector);
}

//alloue un vector de taille init_size et répète n-fois l’ajout et la suppression d’un
//élément en queue
void insert_erase_tail(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(size_t i = 0; i  < n; i++){
        vector_push_back(testVector, random_double(0, 100));
        vector_pop_back(testVector);
    }
    vector_free(vector);
}

//alloue un vector de taille init_size et répète n-fois la lecture et réécriture de la valeur
//lu incrémenté de 1 à des positions aléatoire
void read_write_random(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(size_t i = 0; i  < n; i++){
        int random = random_int(0, init_size);
        double result;
        vector_get(testVector, random, &result);
        vector_set(testVector, random, result + 1);
    }
    vector_free(vector);
}

//alloue un vector de taille init_size et répète n-fois la lecture et réécriture de la
//valeur lu incrémenté de 1 avec un parcours de la tête vers la queue
void read_write_sequential(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(size_t i = 0; i < n; i++){
        double result;
        vector_get(testVector, i, &result);
        vector_set(testVector, i, result + 1);
    }
    vector_free(vector);
}

//alloue un vector de taille init_size et répète n-fois l’écriture de tous les éléments du vecteur
//avec des valeur aléatoire puis tri du vecteur avec le tri à bulles
void bubble_sort(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(size_t i = 0; i  < n; i++){
        for(size_t j = 0; j < vector_size(vector); j++){
            vector_insert(vector, j, random_double(0, 100));
        }

        for(size_t i = vector_size(vector)-1; i > 0; i--){
            int tabsort = 1;
            for(size_t j = 0; j < i; j++){
                double temp1;
                vector_get(vector, j+1, &temp1);
                double temp2;
                vector_get(vector, j, &temp2);
                if(temp1 < temp2){
                    vector_set(vector, j+1, temp2);
                    vector_set(vector, j, temp1);
                    tabsort = 0;
                }
            }
            if(tabsort) break;
        }
    }
    vector_free(vector);
}
