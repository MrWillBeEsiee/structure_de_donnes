#include <stdio.h>

void eleve_au_carre ( int* p ) {
    *p *= *p;
}

int main () {
    int n = 5;
    eleve_au_carre (& n ) ;
    printf ("%d\n" , n ) ; /* = > 25 */
    return 0;
}