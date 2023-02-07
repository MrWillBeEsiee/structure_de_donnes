#include<stdlib.h>
#include<string.h>
#include"../headers/vector.h"

//alloue et retourne votre structure. Le tableau dynamique contient n double près initialisés à 0.0
Vector* vector_alloc(size_t n){
    Vector* p_s_Vector = (Vector*)malloc(sizeof(Vector*));
    p_s_Vector -> size = n;
#if VERSION==2
    if(n < 16){
        p_s_Vector -> db = (double*)calloc(16, sizeof(double));
    }else{
        p_s_Vector -> db = (double*)calloc((int)pow(2, ceil(log(n) / log(2))), sizeof(double));
    }
#else
    p_s_Vector -> db = (double*)calloc(n, sizeof(double));
#endif
    return p_s_Vector;

}

//libère la structure
void vector_free(Vector* p_s_Vector){
    free(p_s_Vector -> db);
    free(p_s_Vector);
    p_s_Vector = NULL;
}

//affecte la valeur v à l’index i du tableau dynamique
void vector_set(Vector* p_s_Vector, size_t i, double v){

    if (p_s_Vector == NULL || i >= p_s_Vector -> size) return;

    p_s_Vector -> db[i] = v;
}

//´ecrit dans le pointeur pv la valeur de l’index i
void vector_get(Vector* p_s_vector, size_t i, double * pv){

    if (p_s_vector == NULL || i >= p_s_vector -> size || pv == NULL) return;

    *pv = p_s_vector -> db[i];
}

//insert une nouvelle donnée à l’index i de votre tableau dynamique
void vector_insert(Vector* p_s_Vector, size_t i, double v){

    if (p_s_Vector == NULL || i >= p_s_Vector -> size) return;
#if VERSION==2
    if(p_s_Vector -> size < p_s_Vector -> capacity){
        p_s_Vector -> db = (double*)realloc(p_s_Vector -> db, (p_s_Vector -> size + 1) * sizeof(double));
    }else{
        p_s_Vector -> db = (double*)realloc(p_s_Vector -> db, (p_s_Vector -> size * 2) * sizeof(double));
        p_s_Vector -> capacity = p_s_Vector -> size * 2;
    }
#else
    p_s_Vector -> db = (double*)realloc(p_s_Vector -> db, (p_s_Vector -> size + 1) * sizeof(double));
#endif

    if(i == p_s_Vector -> size-1){
        vector_set(p_s_Vector, i, v);
        return;
    }
    memcpy(p_s_Vector -> db+i, p_s_Vector+i+1, (p_s_Vector -> size -i) * sizeof (double));
    p_s_Vector -> db[i] = v;
    p_s_Vector -> size ++;
}

//supprime la donnée à l’index i de votre tableau dynamique
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
#if VERSION==2
    if(p_s_Vector -> size <= p_s_Vector -> capacity /4){
        p_s_Vector -> capacity = p_s_Vector -> capacity /2;
    }
#endif

    p_s_Vector -> db = realloc(p_s_Vector -> db, (p_s_Vector -> size) * sizeof(double));

}

//insert une nouvelle donn´ee `a la fin de votre tableau dynamique
void vector_push_back(Vector* p_vector, double v){

    vector_insert(p_vector,p_vector->size-1, v);

}

//supprime la dernière donnée du tableau dynamique
void vector_pop_back(Vector* p_vector){

    vector_erase(p_vector,p_vector->size-1);

}

//supprime toutes les donn´ees de votre tableau dynamique
void vector_clear(Vector* p_vector){

    if (p_vector == NULL) return;

    while(p_vector->size != 0)
        vector_erase(p_vector, p_vector->size);
}

//retourne un entier non nul si votre tableau dynamique est vide et zéros sinon
int vector_empty(Vector* p_vector){

    if (p_vector == NULL) return 0;

    return p_vector->size == 0 ? 0 : 1;
}

//retourne le nombre d’élément stocker dans le tableau dynamique
size_t vector_size(Vector* p_vector){

    if (p_vector == NULL) return EXIT_FAILURE;

    return p_vector->size;
}

