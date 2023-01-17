/*
 * Ce fichier inclut les fichiers test_vector.c et test_random.c,
 * qui contiennent chacun une fonction main().
 * 
 * Pour éviter les conflits de nom de fonction, on utilise les
 * directives de préprocesseur #define et #undef pour redéfinir
 * la fonction main dans chaque fichier inclus.
 * 
 * La fonction main de ce fichier appelle les fonctions main
 * redéfinies dans les fichiers test_vector.c et test_random.c.
 */

#define main main_test_vector
#include "../TP2/test_vector.c"
#undef main
#define main main_test_random
#include "../TP2/test_random.c"
#undef main

int main(int argc, char *argv[]){
	// Appel des fonctions main de test_vector.c et test_random.c
	main_test_vector(argc, argv);
	main_test_random(argc, argv);
	return 0;
}

