#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/* la reponse a la question precedente */

# define REL_TOL 1e-9
# define ABS_TOL 0.0
/* inclure <math .h> et compiler avec gcc -lm */

int proche ( double a , double b ) {
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

double moyenne ( double t [] , int n ) {
/* calcule la moyenne des n premiers elements du tableau t */
    int i;
    double moyenne = 0.0;
    for (i = 0; i < n; i++){
        moyenne += t[i];
    }
    moyenne /= n;
    return moyenne;
}

double moyenne_positifs ( double t []) {
/* calcule la moyenne des elements du tableau t jusqu 'a rencontrer un
element negatif et -1.0 si le premier element est deja negatif */

    if (t[0] < 0){
        return -1.0;
    }

    int i = 0;
    double moyenne = 0.0;

    while (t[i] != '\0'){
        if (t[i] < 0){
            break;
        }

        moyenne += t[i];
        i++;
    }

    moyenne /= i;
    return moyenne;
}

double test_moyenne () {
    double v [] = {1.0 , 2.0 , 3.0 , 4.0 , 5.0 , 6.0 , -1.0};
    double d , attendu ;
    attendu = 1;
    /* test moyenne */
    if (!proche (( d = moyenne (v , 1) ) , attendu ) ) {
        printf (" Pb moyenne . Attendu : %f Obtenu :%f \n " , attendu , d ) ;
    }
    attendu = 2.0;
    if (!proche (( d = moyenne (v , 3) ) , attendu ) ) {
        printf (" Pb moyenne . Attendu : %f Obtenu :%f \n " , attendu , d ) ;
    }
    attendu = 3.5;
    if (!proche (( d = moyenne (v , 6) ) , attendu ) ) {
        printf (" Pb moyenne . Attendu : %f Obtenu :%f \n " , attendu , d ) ;
    }
    /* test moyenne positifs */
    attendu = 3.5;
    if (!proche (( d = moyenne_positifs ( v ) ) , attendu ) ) {
        printf (" Pb moyenne_positifs . Attendu : %f Obtenu :%f \n " , attendu , d ) ;
    }
    attendu = 5.0;
    if (!proche (( d = moyenne_positifs ( v + 3) ) , attendu ) ) {
        printf (" Pb moyenne_positifs . Attendu : %f Obtenu :%f \n " , attendu , d ) ;
    }
    attendu = -1.0;
    if (!proche ( d = moyenne_positifs (v + 6) , -1.0) ) {
        printf (" Pb moyenne_positifs . Attendu : %f Obtenu :%f \n " , attendu , d ) ;
    }

    return 0.0;
}

int main () {
    test_moyenne () ;
    return 0;
}