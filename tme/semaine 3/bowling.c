#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NBTOURS 10
#define NBLANCERS 2
#define NBQUILLES 10

/* Il sera probablement n�cessaire de modifier les parametres et valeur de retour des fonctions 
  lancer, lancer_aleatoire, score et jeu */

/* Les declarations actuelles permettent de compiler et d'executer le programme */

int lancer(int seuil) {
  int lance = -1;
  while (lance < 0 || lance > seuil){
    scanf("%d", &lance);
  }
  return lance;
}

int lancer_aleatoire(int seuil) {
  return rand() % (seuil + 1);
}

void score(int points, int *score_, int *spar_prec, int *strike_prec, int *strike_prec_deux) {
  if (*strike_prec == 1){
    *strike_prec_deux = 1;
    *strike_prec = 0;
    *score_ += points;
  }
  if (*strike_prec_deux == 1){
    *strike_prec_deux = 0;
    *score_ += points;
  }
  if(*spar_prec == 1){
    *spar_prec = 0;
    *score_ += points;
  }

  *score_ += points;
}

void tour(int *score_, int *spar_prec, int *strike_prec, int *strike_prec_deux){
  // premiere lance
  int lance = lancer(NBQUILLES);
  score(lance, score_, spar_prec, strike_prec, strike_prec_deux);

  // deuxieme lance
  int debout = NBQUILLES - lance;
  if (debout > 0){
    lance = lancer(debout);
    score(lance, score_, spar_prec, strike_prec, strike_prec_deux);

    debout = debout - lance;
    if(debout == 0){
      *spar_prec = 1;
    }
  }
  else{
    *strike_prec = 1;
  }
}

int jeu(int *score_, int *spar_prec, int *strike_prec, int *strike_prec_deux){
  for(int i = 0; i < NBTOURS; i++){
    tour(score_, spar_prec, strike_prec, strike_prec_deux);
    // printf("score: %d, spar_prec: %d, strike_prec: %d, strike_prec_deux: %d\n", *score_, *spar_prec, *strike_prec, *strike_prec_deux);
  }

  if(*strike_prec == 1){
    *score_ += lancer(NBQUILLES);
    *score_ += lancer(NBQUILLES);
  }
  else if(*spar_prec == 1 || *strike_prec_deux == 1){
    *score_ += lancer(NBQUILLES);
  }

  return *score_;
}

int main() {
  srand(time(NULL));

  int score_ = 0, spar_prec = 0, strike_prec = 0, strike_prec_deux = 0;
  
  printf("%d\n", jeu(&score_, &spar_prec, &strike_prec, &strike_prec_deux));

  // int res = lancer(10);
  // printf("%d\n", res);
  

  // tour(&score_, &spar_prec, &strike_prec, &strike_prec_deux);

  // printf("%d\n", lancer(NBQUILLES));

  return 0;
}