/* Inclusion de l'entète du module */
#include "Score.h"
#include "Jeu.h"
#include "Plateau.h"

/* Inclusion d'entêtes standards */
#include <cassert>
#include <iostream>
#include <fstream>

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
        int caseocc = 0;
        int caseadv = 0;
        score = 0;
        for(int i=1; i<dimx-2; i++)
        {
            for(int j=1; i<dimy-2; j++)
            {
                if(tabCase[j*dimx+i] == 0)
                {
                    caseocc = caseocc +1;
                }
                else(tabCase[j*dimx+i] == 1)
                {
                    caseadv = caseadv +1;
                }
            }
        }
        if(caseadv = 0)
        {
            score = score * 2;
        }
        if(caseocc = (dimx-2 * dimy-2))
        {
            score = score *2;
        }
        if(joueur1 == true) && (classique == true)
        {
            score = score * 2;
        }
        if(joueur 1 == true) && (classique == false)
        {
            score = score * 3;
        }
    }

// AfficherScore();
    void Score::AfficherScore();
    {
        if()//condition de victoire: Le joueur possède + de case que son adversaire.
        {
            cout << "Bien joué !!! tu as gagnés" <<endl;
            sleep(8);
            cout << "Voici ton score" << score;
        }
    }
  


