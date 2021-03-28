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
#include "Jeu.h"
#include <iostream>

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
    Score();

    /**
    @brief Constructeur de la classe:
    */
    Score(int nbCaseJ1,int nbCaseJ2, bool tabClassique,Plateau p);

    /**
    @brief Destructeur de la classe:
    */
    ~Score();

   /**
    @brief Fonction qui retourne un entier, fonction qui permettre de calculer le nombre
    avec lequel on multipliera le score du joueur pour determiner son vrai score
    en fonction des différents exploits réalisé par le joueur lors de la partie (ex:plateau plein avec
    uniquement ses jetons , etc...)
    */
    int condMultiplicateur();

    /**
    @brief Fonction principale du score, fonction qui retournera le score du joueur qui a gagné la partie (score multiplié par les différent bonus)
    */
    Score & CalculateurScore();

    /**
    @brief Fonction qui permet d'afficher le score du joueur vainqueur à l'écran 
    */
    void Score::AfficherScore();

    /**
    @brief Accesseur: Récupère le contenu de score
    */
    Score & Score::getScore () const;

    /**
    @brief Mutateur: Modifie le contenu de score
    */
   void Score::SetScore (Score & nouvScore);

};
#endif /* Termine le #ifndef SCORE_H */

