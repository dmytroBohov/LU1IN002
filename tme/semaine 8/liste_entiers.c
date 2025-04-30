#include <stdio.h>
#include <stdlib.h>
#include "liste_entiers.h"

cellule_t * creerListe(int n) {
/* cree une liste de n entiers saisi par l'utilisateur
  renvoie l'adresse du premier element de la liste */
  int i;
  int val;
  cellule_t *tete=NULL;
  cellule_t *ptr;
  
  printf("Saisie des %d elements de la liste\n",n);
  for (i=0; i < n; i++) {
    printf("Element %d :",i+1);
    scanf("%d",&val);
    ptr=malloc(sizeof(cellule_t));
    ptr->donnee = val;
    ptr->suivant = tete;
    tete = ptr;
  }
  return tete;
}

void AfficherListeInt(cellule_t *liste){
  cellule_t *cell = liste;
  while(cell != NULL){
    printf("%d\n", cell->donnee);
    cell = cell->suivant;
  }
}

int nb_occurences(int val, cellule_t *liste){
  int compt = 0;
  cellule_t *cell = liste;
  while(cell != NULL){
    if(cell->donnee == val)
      compt++;
    
    cell = cell->suivant;
  }

  return compt;
}

int tous_plus_grands(int val, cellule_t *liste){
  cellule_t *cell = liste;
  while(cell != NULL){
    if(cell->donnee < val)
      return 0;
    
    cell = cell->suivant;
  }

  return 1;
}

cellule_t *Maximum(cellule_t *liste){
  cellule_t *max = liste, *cell = liste;
  while(cell != NULL){
    if(cell->donnee > max->donnee){
      max = cell;
    }

    cell = cell->suivant;
  }

  return max;
}

int Renvoyer_val_element_pos(int pos, cellule_t *liste){
  int index = 0;
  cellule_t *cell = liste;
  while(cell != NULL){
    if(index == pos)
      return cell->donnee;

    cell = cell->suivant;
    index++;
  }

  return -1;
}

cellule_t *Concatener_it(cellule_t *liste_1, cellule_t *liste_2){
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
