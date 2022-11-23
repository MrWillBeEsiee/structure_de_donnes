#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"vector.h"


Vector* vector_alloc(size_t n){

    Vector* theVect = (Vector*)malloc(sizeof(Vector));  // Alloue dynamiquement le Vector* theVect
    theVect -> size = n;
    theVect -> db = calloc(n + 10, n * sizeof(double));  // Initialise le tableau dynamique à 0.0
}

void vector_free(Vector* p_vector){

    free(p_vector -> db);
    p_vector -> db = NULL;  // Aucune idée de si c'est utile
    p_vector -> size = 0;  // Aucune idée de si c'est utile
    free(p_vector);
}

void vector_set(Vector* p_vector, size_t i, double v){

    if (p_vector == NULL || i > p_vector -> size || i < 0) return;  // Evite tout problème

    (p_vector -> db)[i] = v;

}

void vector_get(Vector* p_vector, size_t i, double * pv){

    if (p_vector == NULL || i > p_vector -> size || i < 0 || pv == NULL) return;  // Evite tout problème

    *pv = (p_vector -> db)[i];
}

void vector_insert(Vector* p_vector, size_t i, double v){

    if (p_vector == NULL || i > p_vector -> size || i < 0) return;  // Evite tout problème

    p_vector -> db = (double*)realloc(p_vector -> db, (p_vector -> size + 1) * sizeof(double));
    (p_vector -> db)[p_vector -> size] = v;  // size = 4 avant, insert à db[4]
    (p_vector -> size) ++;  // Augmenter la taille
}

void vector_erase(Vector* p_vector, size_t i){

    if (p_vector == NULL || i > p_vector -> size || i < 0) return;  // Evite tout problème

    double* tempDb = (double*)calloc ((p_vector -> size) - 1, (p_vector->size-1) * sizeof(double));
    memcpy(tempDb, p_vector -> db, i*sizeof(double));
    memcpy(tempDb + (i*sizeof(double)), (p_vector -> db) + (i+1)*sizeof(double), p_vector -> size - i);
    p_vector -> size --;
    p_vector -> db = (double*)realloc(p_vector -> db, (p_vector -> size) * sizeof(double));  // La taille est déjà réduite ici

    for (int i = 0; i < (p_vector -> size); i++){
        (p_vector -> db)[i] = tempDb[i];
    }

    free(tempDb);
    tempDb = NULL;
}

void vector_push_back(Vector* p_vector, double v){

    if (p_vector == NULL) return;  // Evite tout problème

    p_vector -> db = (double*)realloc(p_vector -> db, (p_vector -> size +1) * sizeof(double));
    p_vector -> db[p_vector->size+1] = v;
}

void vector_pop_back(Vector* p_vector){

    if (p_vector == NULL) return;  // Evite tout problème

    vector_erase(p_vector, p_vector->size);
    p_vector->size--;
    p_vector -> db = (double*)realloc(p_vector -> db, (p_vector -> size) * sizeof(double));
}

void vector_clear(Vector* p_vector){

    if (p_vector == NULL) return;  // Evite tout problème

    while(p_vector->size != 0)
        vector_erase(p_vector, p_vector->size);
    vector_free(p_vector);
}

int vector_empty(Vector* p_vector){

    if (p_vector == NULL) return 0;  // Evite tout problème

    return p_vector->size == 0 ? 0 : 1;
}

size_t vector_size(Vector* p_vector){

    if (p_vector == NULL) return 0;  // Evite tout problème

    return p_vector->size;
}

