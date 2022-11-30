#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"vector.h"


Vector* vector_alloc(size_t n){

    Vector* p_s_Vector = (Vector*)malloc(sizeof(Vector*));
    p_s_Vector -> size = n;
    p_s_Vector -> db = (double*)calloc(n, n * sizeof(double));
    return p_s_Vector;
}

void vector_free(Vector* p_s_Vector){

    free(p_s_Vector -> db);
    free(p_s_Vector);
    p_s_Vector = NULL;
}

void vector_set(Vector* p_s_Vector, size_t i, double v){

    if (p_s_Vector == NULL || i >= p_s_Vector -> size) return;

    p_s_Vector -> db[i] = v;
}

void vector_get(Vector* p_s_vector, size_t i, double * pv){

    if (p_s_vector == NULL || i >= p_s_vector -> size || pv == NULL) return;
    *pv = p_s_vector -> db[i];
}

void vector_insert(Vector* p_s_Vector, size_t i, double v){

    if (p_s_Vector == NULL || i >= p_s_Vector -> size) return;

    p_s_Vector -> db = (double*)realloc(p_s_Vector -> db, (p_s_Vector -> size + 1) * sizeof(double));
    if(i == p_s_Vector -> size-1){
        vector_set(p_s_Vector, i, v);
        return;
    }
    memcpy(p_s_Vector -> db+i, p_s_Vector+i+1, (p_s_Vector -> size -i) * sizeof (double));
    p_s_Vector -> db[i] = v;
    p_s_Vector -> size ++;
}

void vector_erase(Vector* p_s_Vector, size_t i){

    if (p_s_Vector == NULL || i >= p_s_Vector -> size) return;
    if(p_s_Vector -> size == 1){
        free(p_s_Vector -> db);
        return;
    }
    if(i == p_s_Vector -> size-1){
        p_s_Vector -> size --;
        realloc(p_s_Vector -> db,(p_s_Vector -> size) * sizeof(double));
        return;
    }
    p_s_Vector -> size --;
    memmove(p_s_Vector -> db+i, p_s_Vector -> db+i+1, (p_s_Vector -> size -i) * sizeof (double));

    p_s_Vector -> db = realloc(p_s_Vector -> db, (p_s_Vector -> size) * sizeof(double));

}

void vector_push_back(Vector* p_vector, double v){

    vector_insert(p_vector,p_vector->size-1, v);

}

void vector_pop_back(Vector* p_vector){

    vector_erase(p_vector,p_vector->size-1);

}

void vector_clear(Vector* p_vector){

    if (p_vector == NULL) return;

    while(p_vector->size != 0)
        vector_erase(p_vector, p_vector->size);
}

int vector_empty(Vector* p_vector){

    if (p_vector == NULL) return 0;

    return p_vector->size == 0 ? 0 : 1;
}

size_t vector_size(Vector* p_vector){

    if (p_vector == NULL) return EXIT_FAILURE;

    return p_vector->size;
}

