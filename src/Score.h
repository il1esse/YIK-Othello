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
#include "Joueur.h"
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
    @param p Plateau de jeu
    @param j1 Joueur1
    @param j2 Joueur2
    */
    Score(const Plateau & p, const Joueur & j1, const Joueur & j2);

    
    /**
    @brief Destructeur de la classe:
    */
    ~Score();

   /**
    @brief Retourne le multiplicateur de score du joueur victorieux selon les conditions de bonus.
    @param p Plateau de jeu.
    */
    int condMultiplicateur(const Plateau & p);

    /**
    @brief Retourne le score final du joueur victorieux.
    @param p Plateau de jeu.
    */
    const int & CalculateurScore(const Plateau & p);

    /**
    @brief Affiche textuellement et de manière détaillé le score du joueur victorieux.
    @param j1 Joueur 1.
    @param j2 Joueur 2.
    @param p Plateau de jeu. 
    */
    void AfficherScoreTxt(const Joueur & j1, const Joueur & j2, const Plateau & p);

    /**
    @brief Accesseur: Récupère la valeur entière du score.
    */
    const int & getValScore() const;

    /**
    @brief Accesseur: Récupère la valeur booléenne de victoire du joueur1.
    */
    const bool & getVictoire() const;

    /**
    @brief Mutateur: Modifie la valeur booléenne de victoire du joueur1.
    @param nvVictoireJ1 La nouvelle valeur booléenne de victoire du joueur1.
    */
   void setVictoire(bool nvVictoireJ1);

    /**
    @brief Mutateur: Modifie la valeur entière du score.
    @param nouvScore La nouvelle valeur entière du score.
    */
   void setValScore(int nouvScore);

};
#endif /* Termine le #ifndef SCORE_H */

