#include <stdio.h>
#include <stdlib.h>
#include "multi_ensembles.h"

  
/* Retourne un pointeur sur le premier element de valeur val, retourne NULL si aucun �l�ment n'a la valeur val */
element_t * Recherche_val(element_t *ensemble, int val) {
  element_t *elem = ensemble;
  while(elem != NULL){
    if(elem->valeur == val){
      return elem;
    }

    elem = elem->suivant;
  }
  return NULL;
}

/* Ajoute l'element val en tete de l'ensemble s'il n'apparait pas dans l'ensemble, augmente sa frequence de 1 sinon */
element_t * Ajout_tete_ensemble(element_t *ensemble, int val, int freq) {
 element_t *elem_trouve = Recherche_val(ensemble, val);
 if(elem_trouve){
  elem_trouve->frequence += freq;
  
  return ensemble;
 }
 else{
  element_t *new_elem;
  new_elem = malloc(sizeof(element_t));
  new_elem->frequence = freq;
  new_elem->valeur = val;
  new_elem->suivant = ensemble;
  
  return new_elem;
 }
}

element_t *Supprime_total_element_ensemble(element_t *ensemble, int val){
  if(ensemble){
    if(ensemble->valeur == val){
      element_t *suiv = ensemble->suivant;
      free(ensemble);
      ensemble = suiv;
    }
    else{
      ensemble->suivant = Supprime_total_element_ensemble(ensemble->suivant, val);
    }
  }
  return ensemble;
}

element_t *Supprime_element_ensemble(element_t *ensemble, int val){
  if(ensemble){
    if(ensemble->valeur == val){
      if(ensemble->frequence == 1){
        element_t *suiv = ensemble->suivant;
        free(ensemble);
        ensemble = suiv;
      }
      else{
        ensemble->frequence--;
        ensemble->suivant = Supprime_element_ensemble(ensemble->suivant, val);
      }
    }
    else{
      ensemble->suivant = Supprime_element_ensemble(ensemble->suivant, val);
    }
  }
  return ensemble;
}

element_t *Ajout_ensemble_trie(element_t *ensemble, int val, int freq){
  element_t *courant = ensemble;
  element_t *precedent = NULL;
  element_t *new;

  while(courant != NULL && courant->valeur < val){
    precedent = courant;
    courant = courant->suivant;
  }

  if(courant != NULL && courant->valeur == val){
    courant->frequence += freq;
    return ensemble;
  }

  new = malloc(sizeof(element_t));
  new->frequence = freq;
  new->valeur = val;
  new->suivant = courant;

  if(precedent == NULL){
    return new;
  }

  precedent->suivant = new;

  return ensemble;
}

element_t *Supprime_total_element_ensemble_trie(element_t *ensemble, int val){
  element_t *courant = ensemble;
  element_t *precedent = NULL;

  while(courant != NULL && courant->valeur < val){
    precedent = courant;
    courant = courant->suivant;
  }

  if(courant != NULL && courant->valeur == val){
    if(precedent != NULL){
      precedent->suivant = courant->suivant;
    }
    else{
      ensemble = courant->suivant;
    }
    
    free(courant);
  }

  return ensemble;
}

element_t *Supprime_element_ensemble_trie(element_t *ensemble, int val){
  element_t *courant = ensemble;
  element_t *precedent = NULL;

  while(courant != NULL && courant->valeur < val){
    precedent = courant;
    courant = courant->suivant;
  }

  if(courant != NULL && courant->valeur == val){
    if(courant->frequence == 1){
      if(precedent != NULL){
        precedent->suivant = courant->suivant;
      }
      else{
        ensemble = courant->suivant;
      }
  
      free(courant);
    }
    else{
      courant->frequence--;
    }
  }

  return ensemble;
}

/* Affche tous les elements d'un ensemble avec leur frequence */
void Affiche_ensemble(element_t *ensemble) {
  element_t *ptr = ensemble;
  
  while (ptr != NULL) {
    printf("val : %d, frequence : %d\n",ptr->valeur,ptr->frequence);
    ptr=ptr->suivant;
  }
}

/* Saisie des n elements d'un ensemble */
element_t * Creation_ensemble(int n) {
  element_t *ensemble=NULL;
  
  int i = 0;
  int val;
  
  for (i=0; i < n; i++) {
    printf("Saisie d'un entier: ");
    scanf("%d",&val);
    ensemble=Ajout_tete_ensemble(ensemble,val,1);
  }
  return ensemble;
}

int Inclus(element_t *e1, element_t *e2){
  while(e1 != NULL){
    if(e2 == NULL){
      return 0;
    }

    if(e1->valeur < e2->valeur){
      return 0;
    }
    else if(e1->valeur == e2->valeur){
      if(e1->frequence > e2->frequence){
        return 0;
      }
      e1 = e1->suivant;
    }
    e2 = e2->suivant;
  }

  return 1;
}

int Intersection_Vide(element_t *e1, element_t *e2){
  while(e1 != NULL && e2 != NULL){
    if(e1->valeur == e2->valeur){
      return 0;
    }
    
    if(e1->valeur < e2->valeur){
      e1 = e1->suivant;
    }
    else{
      e2 = e2->suivant;
    }
  }

  return 1;
}

int taille(element_t *ensemble){
  if(ensemble){
    int somme = ensemble->frequence;
    return somme + taille(ensemble->suivant);
  }

  return 0;
}

element_t *Supprime_frequence_inf_seuil(element_t *ensemble, int val){
  if(ensemble){
    ensemble->suivant = Supprime_frequence_inf_seuil(ensemble->suivant, val);
    
    if(ensemble->frequence < val){
      element_t *suiv = ensemble->suivant;
      free(ensemble);
      ensemble = suiv;
    }
  }
  return ensemble;
}

int Inclus_rec(element_t *e1, element_t *e2){

}

element_t *Union(element_t *e1, element_t *e2){

}

element_t *Ajout_suivant(element_t *element, int val, int freq){

}

element_t *Union_triee(element_t *e1, element_t *e2){

}

element_t *Union_triee_rec(element_t *e1, element_t *e2){

}

element_t *Intersection_triee(element_t *e1, element_t *e2){

}

element_t *Difference_triee(element_t *e1, element_t *e2){

}

element_t *Xor_triee(element_t *e1, element_t *e2){

}

void Detruire(element_t *ensemble){

}

element_t *Reverse(element_t *ensemble){
  element_t *new_tete = NULL;
  element_t *suiv = NULL;

  while(ensemble != NULL){
    suiv = ensemble->suivant;
    ensemble->suivant = new_tete;
    new_tete = ensemble;
    ensemble = suiv;
  }
  
  return new_tete;
}

element_t *Reverse_rec(element_t *ensemble){
  if(ensemble == NULL || ensemble->suivant == NULL){
    return ensemble;
  }

  element_t *new_tete = Reverse_rec(ensemble->suivant);
  ensemble->suivant->suivant = ensemble;
  ensemble->suivant = NULL;

  return new_tete;
}
