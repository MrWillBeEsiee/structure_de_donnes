#ifndef _ARRAY_H_     		  		  	   	 
#define _ARRAY_H_     		  		  	   	 
     		  		  	   	 
typedef struct{     		  		  	   	 
     		  		  	   	 
    int size;     		  		  	   	 
    int* tab;     		  		  	   	 
     		  		  	   	 
}Array;     		  		  	   	 
     		  		  	   	 
Array* createArray(int size, int value);     		  		  	   	 
void freeArray(Array** array);     		  		  	   	 
     		  		  	   	 
#endif     		  		  	   	 
     		  		  	   	 