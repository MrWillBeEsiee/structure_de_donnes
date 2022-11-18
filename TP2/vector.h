#ifndef __VECTOR_H__
#define __VECTOR_H__

struct struct_vector{
	int size;
	double* db;
};

typedef struct struct_vector s_vector;  // stuct_vector peut être égelement nommé par s_vector
typedef s_vector* p_s_vector;  // p_s_vector représente le pointeur sur la structure s_vector


p_s_vector vector_alloc(size_t n);
void vector_free(p_s_vector p_vector);
void vector_set(p_s_vector p_vector, size_t i, double v);
void vector_get(p_s_vector p_vector, size_t i, double * pv);
void vector_insert(p_s_vector p_vector, size_t i, double v);
void vector_erase(p_s_vector p_vector, size_t i);
void vector_push_back(p_s_vector p_vector, double v);
void vector_pop_back(p_s_vector p_vector);
void vector_clear(p_s_vector p_vector);
int vector_empty(p_s_vector p_vector);
size_t vector_size(p_s_vector p_vector);

#endif //__VECTOR_H__
