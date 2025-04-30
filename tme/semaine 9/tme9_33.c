#include <stdio.h>
#include "multi_ensembles.h"

int main() {
  element_t *ensemble = Creation_ensemble(3);
  printf("\n");
  // element_t *ensemble2 = Creation_ensemble(10);

  Affiche_ensemble(ensemble);
  printf("\n\n");
  // Affiche_ensemble(ensemble2);
  // printf("\n\n");

  // int res = taille(ensemble);
  // printf("%d\n", res);

  // ensemble = Supprime_frequence_inf_seuil(ensemble, 2);
  ensemble = Reverse_rec(ensemble);
  Affiche_ensemble(ensemble);

  return 0;
}