#include <stdlib.h>
#include <stdio.h>

#define MAX 6

int rechercher(int tab[], int taille, int val){
    for(int i = 0; i < taille; i++){
        if(tab[i] == val)
            return 1;
    }

    return 0;
}

int recherche_rec(int tab[], int taille, int val){
    if(taille == 0){
        return -1;
    }
    else{
        if(tab[taille - 1] == val){
            return taille - 1;
        }
        else{
            return recherche_rec(tab, taille - 1, val);
        }
    }
}

int recherche_rec_aux(int tab[], int taille, int indice, int val){
    if(taille == 0){
        return -1;
    }
    else{
        if(tab[indice] == val){
            return indice;
        }
        else{
            return recherche_rec_aux(tab, taille - 1, indice + 1, val);
        }
    }
}

int rechercher_v(int tab[], int taille, int val){
    int gauche = 0, droite = taille - 1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;

        if (tab[milieu] == val)
            return 1; // Valeur trouvée
        if (tab[milieu] < val)
            gauche = milieu + 1; // Chercher à droite
        else
            droite = milieu - 1; // Chercher à gauche
    }
    return 0; // Valeur non trouvée
}

int rechercher_rec_v(int tab[], int gauche, int droite, int val) {
    if (gauche > droite)  
        return 0;  // Valeur non trouvée

    int milieu = gauche + (droite - gauche) / 2;

    if (tab[milieu] == val)
        return 1;  // Valeur trouvée
    if (tab[milieu] < val)
        return rechercher_rec_v(tab, milieu + 1, droite, val); // Chercher à droite
    else
        return rechercher_rec_v(tab, gauche, milieu - 1, val); // Chercher à gauche
}

int main(){
    int test[MAX] = {2,2,3,4,1,6};
    int res = recherche_rec_aux(test, MAX, 0, 1);
    printf("%d\n", res);

    // res = rechercher(test, MAX, 10);
    // printf("%d\n", res);

    return 0;
}
