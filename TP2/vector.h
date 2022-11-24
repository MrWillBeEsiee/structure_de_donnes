#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct struct_vector{
    size_t size;
    double* db;
}Vector;

Vector* vector_alloc(size_t n);
void vector_free(Vector *p_vector);
void vector_set(Vector *p_vector, size_t i, double v);
void vector_get(Vector *p_vector, size_t i, double * pv);
void vector_insert(Vector *p_vector, size_t i, double v);
void vector_erase(Vector *p_vector, size_t i);
void vector_push_back(Vector *p_vector, double v);
void vector_pop_back(Vector *p_vector);
void vector_clear(Vector *p_vector);
int vector_empty(Vector *p_vector);
size_t vector_size(Vector *p_vector);

#endif //__VECTOR_H__
