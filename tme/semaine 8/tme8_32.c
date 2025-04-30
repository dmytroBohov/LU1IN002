// Exercice 41 – (CodeRunner) Parcours de listes  
// -------------------------------------------------------------------------------  
// **Objectif** : Ajouter les fonctions suivantes à la bibliothèque `liste_entiers` :  
// 1. Mettre à jour `liste_entiers.h` (signatures)  
// 2. Implémenter dans `liste_entiers.c`  
// 3. Tester dans `test_liste.c`  

// -------------------------------------------------------------------------------  
// Question 1  
// -------------------------------------------------------------------------------  
// Écrivez la fonction :  
// `int nb_occurences(int val, cellule_t *liste)`  
// Renvoie le nombre d’occurrences de `val` dans la liste.  

// -------------------------------------------------------------------------------  
// Question 2  
// -------------------------------------------------------------------------------  
// Écrivez la fonction :  
// `int tous_plus_grand(int val, cellule_t *liste)`  
// Renvoie `1` si tous les éléments de la liste sont ≥ `val`, `0` sinon.  

// -------------------------------------------------------------------------------  
// Question 3  
// -------------------------------------------------------------------------------  
// Écrivez la fonction :  
// `cellule_t* Maximum(cellule_t *liste)`  
// Renvoie un pointeur vers la **première** cellule contenant la valeur maximale de la liste.  

// -------------------------------------------------------------------------------  
// Question 4  
// -------------------------------------------------------------------------------  
// Écrivez la fonction :  
// `int Renvoyer_val_element_pos(int pos, cellule_t* liste)`  
// Renvoie la valeur de l’élément en position `pos` (indexation à partir de 0).  
// **Hypothèse** : `pos` est valide (0 ≤ pos < taille liste).  

// -------------------------------------------------------------------------------  
// Question 5 (non notée)  
// -------------------------------------------------------------------------------  
// Écrivez la fonction itérative :  
// `cellule_t *Concatener_it(cellule_t *liste1, cellule_t *liste2)`  
// Renvoie la concaténation de `liste1` et `liste2` :  
// - Si une liste est vide, renvoie l’autre.  
// - Si les deux sont vides, renvoie `NULL`.  
// - Modifie `liste1` et renvoie sa tête après ajout de `liste2`.  

// -------------------------------------------------------------------------------  
// Question 6 (non notée)  
// -------------------------------------------------------------------------------  
// Écrivez la fonction :  
// `int nb_maximum(cellule_t *liste)`  
// Renvoie le nombre d’occurrences de la valeur maximale dans la liste.  
// **Contrainte** : Parcourir la liste **une seule fois**.

#include "liste_entiers.h"
#include <stdio.h>

int main() {
  cellule_t *ma_liste=creerListe(5);
  AfficherListeInt(ma_liste);
  printf("\n\n");

  int res = nb_occurences(2, ma_liste);
  printf("Nombre d'occurances : %d\n", res);
  printf("\n\n");

  res = tous_plus_grands(2, ma_liste);
  printf("Tous plus grand : %d\n", res);
  printf("\n\n");

  cellule_t *max_cell = Maximum(ma_liste);
  printf("Max est : %d\n", max_cell->donnee);
  printf("\n\n");

  res = Renvoyer_val_element_pos(2, ma_liste);
  printf("Valeur de position : %d\n", res);
  
  return 0;
}
