/**
 @brief Score contient les données & les entêtes des fonctions Score.
 @author YIK
 @version 1.0
 @date 2021/03/17
*/

/* Directives pour éviter les inclusions multiples */
#ifndef SCORE_H
#define SCORE_H
/* Inclusions des entêtes utilisées */

#include "Plateau.h"

/* Définitions de la classes */
class Score {
/* Données privés */

 private :
    int score;
    int nbCaseJ1Sco;
    int nbCaseJ2Sco;
    bool tabClassiqueSco;
    bool victoireJ1;
    Plateau pSco;


/* Donnée et fonctions publique */
 public :   

    /**
    @brief Constructeur par défaut de la classe:
    */
    Score(int nbCaseJ1,int nbCaseJ2, bool tabClassique);

    /**
    @brief Destructeur de la classe:
    */
    ~Score();

   /**
    @brief 
    */
    condMultiplicateur()

    /**
    @brief 
    */
    CalculateurScore();

    /**
    @brief 
    */
    AfficherScore();

    /**
    @brief
    */
    EffacerScore();

    /**
    @brief
    */
    GetScore();

    /**
    @brief
    */
   SetScore(Score & nouvScore);

};
#endif /* Termine le #ifndef SCORE_H */

