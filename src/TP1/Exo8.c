#include <stdio.h>
#include <string.h>


int chaine_index ( char* s1 , char* s2 ){

    if (strlen(s1) < strlen(s2)){
        return -1;
    }

    int valid = 0;

    for (int i = 0; s1[i] != '\0'; i++){

        if (s1[i] == s2[0]){

            for (int j = 0; j < strlen(s2); j++){

                if (s1[i + j] != s2[j]){
                    break;
                }

                if (j == strlen(s2) - 1 && s1[i + j] == s2[j]){
                    valid = 1;
                }
            }		  		  	   	 
            if (valid == 1){
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    char* s1 = "ines est faaa une fille";
    char* s2 = "Suuuuu";
    char* s3 = "fille";

    int pos = chaine_index(s1, s2);
    int pos2 = chaine_index(s1, s3);

    printf("%s | %s = %d\n", s1, s2, pos);
    printf("%s | %s = %d\n", s1, s3, pos2);
    //printf("%c%c%c%c\n", s1[18], s1[19], s1[20], s1[21]);

    return 0;
}
