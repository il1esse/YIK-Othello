/* Inclusion de l'entète du module */
#include "Score.h"

/* Inclusion d'entêtes standards */
#include <cassert>
#include <iostream>

/* Définitions des fonctions membres publiques et privées */


// Constructeur par défaut de la classe:
    Score::Score()
    {
        score = 0;
    }

// Constructeur de la classe Score: 
    Score::Score(int nbCaseJ1,int nbCaseJ2, bool tabClassique,Plateau p) {
        score = 0;
        nbCaseJ1Sco = nbCaseJ1;
        nbCaseJ2Sco = nbCaseJ2 ;
        tabClassiqueSco = tabClassique;
        pSco = p;
    }

// Destructeur de la classe: 
   Score::~Score () {
        score = 0;
        nbCaseJ1Sco = 0;
        nbCaseJ2Sco = 0 ;
        tabClassiqueSco = true;
   }

// Accesseur :
   Score & Score::getScore () const {
      return score;
   }

// Mutateur :
   void Score::SetScore (Score & nouvScore) {
        score = nouvScore;
   }
   
// condMultiplicateur()
    int condMultiplicateur()
    {
        int m=1;
        if(nbCaseJ1Sco == 0 || nbCaseJ2Sco == 0)
        {
            m=m*2;
        }
        int nbCaseMax = j*dimx + i; //refaire calcul du nombre de case a part
        if(nbCaseJ1Sco == nbCaseMax || nbCaseJ2Sco == nbCaseMax)
        {
            m=m*2;
        }
        if(tabClassiqueSco==true)
        {
            m=m*2
        }
        else m=m*3;

        return m;
    }

// CalculateurScore();
    Score & CalculateurScore(); 
    {   
        int m = condMultiplicateur();
        if (victoireJ1 == true)
        {
            return nbCaseJ1Sco * m;
        }
        else return nbCaseJ2Sco * m;
    }
        



// AfficherScore();
    void Score::AfficherScore();
    {
        if()//condition de victoire: Le joueur possède + de case que son adversaire.
        {
            std::cout << "Bien joué !!! tu as gagnés" <<std::endl;
            sleep(8);
            std::cout << "Voici ton score" << score <<std::endl;
        }
    }
  


