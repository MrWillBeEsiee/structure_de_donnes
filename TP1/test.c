#include "Array.h"     		  		  	   	 
#include <stdlib.h>     		  		  	   	 
#include <stdio.h>
#include <string.h>     		  		  	   	 
     		  		  	   	 
/*Array* createArray(int size, int value){     		  		  	   	 
     		  		  	   	 
    Array* theArray = (Array*)malloc(sizeof(Array));     		  		  	   	 
     		  		  	   	 
    theArray -> tab = (int*)malloc(sizeof(int) * size);     		  		  	   	 
     		  		  	   	 
    for (int i = 0; i < size; i++){     		  		  	   	 
        printf("%d\n", theArray -> tab[i]);     		  		  	   	 
    }     		  		  	   	 
     		  		  	   	 
    theArray -> size = size;     		  		  	   	 
     		  		  	   	 
    for (int i = 0; i < size; i++){     		  		  	   	 
        theArray -> tab[i] = value;     		  		  	   	 
    }     		  		  	   	 
     		  		  	   	 
    return theArray;     		  		  	   	 
}     		  		  	   	 
     		  		  	   	 
void freeArray(Array** array){     		  		  	   	 
     		  		  	   	 
    (*array) -> size = 0;   		  		  	   	   

    for (int i = 0; i < strlen((*array) -> tab); i++){
        (*array) -> tab[i] = 0;
        printf("%d\n", (*array) -> tab[i]);
    } 	   	 

    (*array) -> tab = NULL;
    free((*array) -> tab);  
    free(*array); 
    *array = NULL;     		  		  	   	 
}     		  		  	   	 

int main(){

    freeArray((createArray(5, 1)));
    return 0;
}*/

int main(){

    //char chaine1[] = "Dylan";
    //char chaine2[] = "Hendrix";

    //printf("%d", strcmp(chaine1, chaine2));
    // Egale : 0
    // 1 < 2 : -1
    // 1 > 2 : 1
    for (int i = 0; i < 0; i++){
        printf("%d", 1);
    }
}