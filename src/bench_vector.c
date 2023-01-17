#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "random.h"
#include "vector.h"

void insert_erase_random(size_t init_size, size_t n);
void insert_erase_head(size_t init_size, size_t n);
void insert_erase_tail(size_t init_size, size_t n); 
void read_write_random(size_t init_size, size_t n); 
void read_write_sequential(size_t init_size, size_t n); 
void bubble_sort(size_t init_size, size_t n);

int main(int argc, char*argv[]){
	srand(time(NULL));

    int init_size = 0;
    int n = 0;


    sscanf(argv[2], "%d", &init_size);
    sscanf(argv[3], "%d", &n);

    printf("%d %d\n", init_size, n);

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

void insert_erase_random(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(int i = 0; i  < n; i++){
        int a = random_int(0, vector_size(vector));
        double b = random_double(0, 50);
        vector_insert(vector, a, b);
        vector_erase(vector, a);
    }
    vector_free(vector);
}

void insert_erase_head(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(int i = 0; i  < n; i++){
        double b = random_double(0, 50);
        vector_insert(vector, 0, b);
        vector_erase(vector, 0);
    }
    vector_free(vector);
}

void insert_erase_tail(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(int i = 0; i  < n; i++){
        double b = random_double(0, 50);
        vector_push_back(vector,b);
        vector_pop_back(vector);
    }
    vector_free(vector);
}

void read_write_random(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(int i = 0; i  < n; i++){
        int a = random_int(0, vector_size(vector));
        int c = random_int(0, vector_size(vector));
        double value = vector->db[a];
        vector_set(vector, c, value+1);
    }
    vector_free(vector);
}

void read_write_sequential(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(int i = 0; i  < n; i++){
        int a = random_int(0, vector_size(vector));
        double value = vector->db[i];
        vector_set(vector, a, value+1);
    }
    vector_free(vector);
}

void bubble_sort(size_t init_size, size_t n){
    Vector* vector = vector_alloc(init_size);
    for(int i = 0; i  < n; i++){
        for(int j = 0; j < vector_size(vector); j++){
            vector_insert(vector, j, random_double(0, 50));
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
