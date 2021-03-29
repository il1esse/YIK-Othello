/* Inclusion de l'entète du module */
#include "Score.h"

/* Inclusion d'entêtes standards */
#include <cassert>
#include <iostream>

/* Définitions des fonctions membres publiques et privées */


    // Constructeur par défaut de la classe Score.
    Score::Score()
    {
        score = 0;
        nbCaseJ1Sco = 0;
        nbCaseJ2Sco = 0;
        tabClassiqueSco = true;
        victoireJ1 = false;

    }

    // Constructeur de la classe Score.
    Score::Score(const Plateau & p, const Joueur & j1, const Joueur & j2) {
        score = 0;
        nbCaseJ1Sco = j1.getNombreCase();
        nbCaseJ2Sco = j2.getNombreCase();
        tabClassiqueSco = p.getType();
        pSco = p;
        victoireJ1 = false;
    }

    // Destructeur de la classe Score/
   Score::~Score () {
        score = 0;
        nbCaseJ1Sco = 0;
        nbCaseJ2Sco = 0 ;
        tabClassiqueSco = true;
        victoireJ1 = false;
   }

    // Accesseur : Retoune le score.
   const int & Score::getValScore() const {
      return score;
   }

    // Mutateur : Modifie la valeur du score.
   void Score::setValScore(int nouvScore) {
        score = nouvScore;
   }

    //Accesseur : Retourne la valeur de la variable victoire
   const bool & Score::getVictoire() const{
       return victoireJ1;
   }

   //Mutateur : Modifie la valeur de de victoire

   void Score::setVictoire(bool nvvictoire)
   {
       victoireJ1 = nvvictoire;
   }
   
    // Retourne le multiplicateur de score du joueur victorieux selon les conditions de bonus.
    int Score::condMultiplicateur(const Plateau & p)
    {
        int nbCaseMax = (p.getDimensionX()-1)*(p.getDimensionY()-1);
        int m=1;
        if(victoireJ1 == true && nbCaseJ2Sco == 0)
        {
            m=m*2;
        }
        else if(victoireJ1 == false && nbCaseJ1Sco == 0){
            m=m*2;
        }
        if((nbCaseJ1Sco + nbCaseJ2Sco) == nbCaseMax)
        {
            m=m*2;
        }
        if(tabClassiqueSco == true)
        {
            m=m*2;
        }
        else m=m*3;

        return m;
    }

    // Retourne le score final du joueur victorieux.
    const int & Score::CalculateurScore(const Plateau & p)
    {   
        int m = condMultiplicateur(p);
        if (victoireJ1 == true)
        {
            return nbCaseJ1Sco * m;
        }
        else return nbCaseJ2Sco * m;
    }
        



    // Affiche textuellement et de manière détaillé le score du joueur victorieux.
    void Score::AfficherScoreTxt(const Joueur & j1, const Joueur & j2, const Plateau &p)
    {
        score = CalculateurScore(p);
        if(victoireJ1 == true){
            std::cout << "Bien joué !!! " << j1.getPseudo() << " as gagné ! " <<std::endl;
            std::cout << "Nombre de case de " << j1.getPseudo() << "est " << j1.getNombreCase() << std::endl;
            std::cout << "Ton adversaire possède " << j2.getNombreCase() << std::endl;
            if(j2.getNombreCase() == 0){ std::cout << "Bonus de domination sur ton adversaire score multiplié par 2" << std::endl;}
            if(tabClassiqueSco == true){ std::cout << "Bonus de plateau classique, score multiplié par 2."<< std::endl;}
            else{std::cout << "Bonus de plateau extravagant, score multiplié par 3."<< std::endl;}
            if(j1.getNombreCase()+j2.getNombreCase() == (p.getDimensionX()-1)*(p.getDimensionY()-1)){
                { std::cout << "Bonus de plateau plateau rempli, score multiplié par 2."<< std::endl;}
            }
            std::cout << "Bonus de victoire, score multiplié par 3." <<std::endl;
            std::cout << "Ton score total est de : " << score <<std::endl;
        }
        if(victoireJ1 == false){
            std::cout << "Bien joué !!! " << j2.getPseudo() << " as gagné ! " <<std::endl;
            std::cout << "Nombre de case de " << j2.getPseudo() << "est " << j2.getNombreCase() << std::endl;
            std::cout << "Ton adversaire possède " << j2.getNombreCase() << std::endl;
            if(j1.getNombreCase() == 0){ std::cout << "Bonus de domination sur ton adversaire score multiplié par 2" << std::endl;}
            if(tabClassiqueSco == true){ std::cout << "Bonus de plateau classique, score multiplié par 2."<< std::endl;}
            else{std::cout << "Bonus de plateau extravagant, score multiplié par 3."<< std::endl;}
            if(j2.getNombreCase()+j1.getNombreCase() == (p.getDimensionX()-1)*(p.getDimensionY()-1)){
                { std::cout << "Bonus de plateau plateau rempli, score multiplié par 2."<< std::endl;}
            }
            std::cout << "Bonus de victoire, score multiplié par 3." <<std::endl;
            std::cout << "Ton score total est de : " << score <<std::endl;
        }
        

    }
  


