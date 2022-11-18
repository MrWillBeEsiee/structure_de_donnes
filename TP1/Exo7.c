#include <stdio.h>

int chaine_longueur_rec(char* s){

    int i = 0;

        if(s[0] != '\0'){
            i++;
            i += chaine_longueur_rec(s +1);
        } 
        return i;
}


int chaine_debute_par(char* s1, char* s2){
    if(s1[0] == '\0') return 1;
    if(s1[0] != s2[0]){
        return 0;
    }
    return chaine_debute_par(s1+1, s2+1);
}


int main(){
    char* test = "jddf ";
    char* test2 = "jdd";
    printf("%d",chaine_debute_par(test, test2));
    printf("\n%d\n", chaine_longueur_rec("jjgh"));

}