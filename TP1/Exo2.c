#include <stdlib.h>
#include <stdio.h>
#include <math.h>

# define REL_TOL 1e-9 // 0.000000001
# define ABS_TOL 0.0

int proche ( double a , double b ){
    // abs(a-b) <= max( rel_tol * max(abs(a), abs(b)), abs_tol
    // 0 -> pas proche
    // 1 -> proche
    if (fabs(a-b) <= fmax(REL_TOL * fmax(fabs(a), fabs(b)), ABS_TOL)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    double a, b;

    do{
        printf ("Entrez un nombre entier (0 pour terminer) : \n") ;
        scanf ("%lf", &a) ;
        printf ("Entrez un autre nombre entier (0 pour terminer) : \n");
        scanf ("%lf", &b) ;

        if (proche(a, b) == 0){
            printf("%.10lf et %.10lf ne sont pas proche\n", a, b);
        }
        else{
            printf("%.10lf et %.10lf sont proche\n", a, b);
        }

    }while(a != 0 && b != 0);
    
}