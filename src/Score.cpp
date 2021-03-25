/* Inclusion de l'entète du module */
#include "Score.h"
#include "Jeu.h"
/* Inclusion d'entêtes standards */
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;



/* Définitions des fonctions membres publiques et privées */
// Constructeur par défaut de la classe:
    Jeton::Jeton() {
        score = 0;
   }

// Destructeur de la classe: 
   Jeton::~Jeton () {
       score = NULL;
   }

// Accesseur :
   Score & Score::getScore () const {
      return score;
   }

// Mutateur :
   void Score::SetScore () {
        Score = score;
   }

// CalculateurScore();
    Score & CalculateurScore(); {


        
        bonusmult=//x2 si le perdant a aucune case
        bonusd'occupation=//x2 si tte les cases sont occuper
        //bonus plateau special
        bonusvictoire =0
        bonusdefaite=0
    }

// AfficherScore();
    void Score::AfficherScore();
    {
        cout << score;
    }

// EffacerScore();
    void EffacerScore();
    {
    }


  


