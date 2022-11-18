#include <stdio.h>
//https://www.binaryconvert.com/result_double.html?decimal=052048
void Visualisation_double(double* nbr){
    char * tab = (char*)nbr;
    for(int i = 7; i >= 0; i--){ 
        printf("%x ", tab[i]);
    }
}

int main(){
    double db = 50;
    Visualisation_double(&db);
    return 1;
}