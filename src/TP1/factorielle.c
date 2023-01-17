#include <limits.h>

/* int factorielle_iterative (int n)
 * calcule la factorielle de n
 * Principe : accumulation des produits des n premiers nombres
 * arguments : n entier positif
 * retour : factorielle de n si n >=0
                      1 si n est negatif
 * JCG ecrit le 22/03/2001 modif le 14/04/2013
 */
int factorielle_iterative ( int n ) {
    int i, p = 1;
    for(i = 1; i <= n; ++i )
        p *= i;
    return p;
}

/* ******************************************************************* */

/* int factorielle_recursive (int n)
 * calcule la factorielle de n
 * Principe : F(n)=1 si n=0 , F(n)=n*F(n -1) si n >0
 * arguments : n entier positif
 * retour : factorielle de n si n >=0
                  1 si n est negatif
 * JCG ecrit le 22/03/2001 modif le 14/04/2013
 */
int factorielle_recursive ( int n ) {
    if(n <= 0)
        return 1;
    else
        return n * factorielle_recursive(n - 1) ;
}

int find_overflow_number(){
    int p = 1;
    int i = 1;
    while (p < (INT_MAX/i)){
        p *= i;
        i += 1;
    }
    return i;
}

/* ********************************************************************* */

#include <stdio.h>
int main ( void ) {
    int n ;
    do {
        printf ("Entrez un nombre entier (0 pour terminer) : ") ;
        scanf ("%d", &n) ;
        if (n < 0){
            printf("Pas de negatif !");
        }
        else if (n >= find_overflow_number()){
            printf("Il y a depassement, tu dois mettre n < %d\n", find_overflow_number());
        }
        else{
            printf ("factorielle_iterative (%2d) = %15d \n", n, factorielle_iterative(n));
            printf ("factorielle_recursive (%2d) = %15d \n", n, factorielle_recursive(n));
        }
    }while ( n != 0 );
    return 0;
}
