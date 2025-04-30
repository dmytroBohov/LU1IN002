#include <stdlib.h>
#include <stdio.h>

typedef struct _cellule_t cellule_t;

struct _cellule_t{
    int donnee;
    cellule_t *suivant;
};

cellule_t *concatener(cellule_t *liste_1, cellule_t *liste_2){
    if(liste_1 == NULL && liste_2 == NULL)
        return NULL;
    else if(liste_1 == NULL)
        return liste_2;
    else if(liste_2 == NULL)
        return liste_1;
    
    cellule_t *cell = liste_1, *cell2 = liste_2;
    int liste_1_parcours = 1;
    while(liste_1_parcours){
        if(cell->suivant == NULL){
            cell->suivant = cell2;
            liste_1_parcours = 0;
        }
        cell = cell->suivant;
    }

    return liste_1;
}

cellule_t *Ajouter(int val, cellule_t *pListe){
	cellule_t *el;
	el = malloc(sizeof(cellule_t));
	el->donnee = val;
	el->suivant = pListe;
	return el;
}

void Afficher(cellule_t *pListe){
	cellule_t *cell = pListe;
	while(cell != NULL){
		printf("%d\n", cell->donnee);
		cell = cell->suivant;
	}
}

int nb_maximum(cellule_t *liste){
    int max = 0;
    int compter = 0;
    cellule_t *cell = liste;
    while(cell != NULL){
        if(cell->donnee > max){
            compter = 0;
            max = cell->donnee;
            compter++;
        }
        else if(cell->donnee == max){
            compter++;
        }

        cell = cell->suivant;
    }

    return compter;
}

int main(){
    cellule_t *liste1 = NULL, *liste2 = NULL, *liste3 = NULL;
    liste1 = Ajouter(5, liste1);
    liste1 = Ajouter(3, liste1);
    liste1 = Ajouter(5, liste1);
    liste1 = Ajouter(1, liste1);

    liste2 = Ajouter(0, liste2);
    liste2 = Ajouter(0, liste2);
    liste2 = Ajouter(5, liste2);

    // Afficher(liste1);
    // printf("\n\n");
    // Afficher(liste2);
    // printf("\n\n");

    liste3 = concatener(liste1, liste2);
    Afficher(liste3);
    printf("\n");

    int res = nb_maximum(liste3);
    printf("%d\n", res);

    return 0;
}
