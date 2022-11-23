#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


int main(){

    void afficheTab(Vector *p_s_Vector){
        printf("[ ");
        for(int i = 0; i < p_s_Vector -> size; i++){
            printf("%f ", p_s_Vector -> db[i]);
        }
        printf("]\n");
    }

    Vector *p_s_Vector = vector_alloc(10);

    //Test set
    vector_set(p_s_Vector,2,15.4);
    vector_set(p_s_Vector,7,2.3);
    afficheTab(p_s_Vector);

    //Test insert
    vector_insert(p_s_Vector,3,9.1);
    printf("insert 9.1 en position 3\n");
    afficheTab(p_s_Vector);


    //pour tester la fonction erase
    printf("Ecrasement de la valeur en indice 2 \n");
    afficheTab(p_s_Vector);
    vector_erase(p_s_Vector,2);
    afficheTab(p_s_Vector);

    //tester la fonction push_back
    printf("Ajout de 6.0 en fin de tableau\n");
    afficheTab(p_s_Vector);
    vector_push_back(p_s_Vector,6.0);
    afficheTab(p_s_Vector);

    //tester la fonction pop_back
    printf("pop de la dernière valeur du tableau\n");
    afficheTab(p_s_Vector);
    vector_pop_back(p_s_Vector);
    afficheTab(p_s_Vector);


    //tester la fonction get
    printf("Récupération de la valeur en index 2 du tableau et écriture dans le pointeur\n");
    double *ptr = malloc(sizeof(double));
    vector_get(p_s_Vector,2,ptr);
    printf("pointeur = %lf\n",*ptr);

    //tester la fonction vector_size
    /*print("Retourne la taille du tableau (10)\n");
    printf("taille : %d\n",vector_size(p_s_Vector));*/

    //tester la fonction clear
    printf("Supprime toutes les valeurs du tableau\n");
    printf("%d\n", p_s_Vector -> size);

    //tester la fonction empty
    printf("Retourne 1 si le tableau est vide doit retourner 1\n");
    printf("%d\n", vector_empty(p_s_Vector));

    vector_free(p_s_Vector);

    return EXIT_SUCCESS;
}