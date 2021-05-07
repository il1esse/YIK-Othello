/**
 @brief Jeu.h contient les entêtes et les fonctions des données Jeu.
 @author YIK
 @version 1.0
 @date 2021/03/17
*/

/* Directives pour éviter les inclusions multiples */
#ifndef JEU_H
#define JEU_H

/* Inclusions des entêtes utilisées */
#include <stdlib.h>
#include "Joueur.h"
#include "Plateau.h"
#include "Score.h"

/* Définitions de la classes */
class Jeu{

/* Données privés */
 private :  
    Plateau pla;
    Joueur j1;
    Joueur j2;
    Score * score = new Score (pla,j1,j2);

/* Donnée et fonctions publique */
 public :
    
    /**
    @brief Constructeur par défaut de la classe Jeu.
    */
    Jeu();

    /**
    @brief Constructeur de la classe Jeu.
    @param p Plateau de jeu.
    @param joueur1 Joueur1.
    @param joueur2 Joueur2.
    */
    Jeu(Plateau p, Joueur joueur1, Joueur joueur2);

    /**
    @brief Destructeur de la classe Joueur.
    */
    ~Jeu();

    /**
    @brief Accesseur : Récupère le plateau de jeu.
    */
    const Plateau & getPlateau() const;

    /**
    @brief Accesseur : Récupère le joueur1 de la partie en cours.
    */
    const Joueur  & getJoueur1() const;

    /**
    @brief Accesseur : Récupère le joueur1 de la partie en cours.
    */
    Joueur & getJoueur1();

    /**
    @brief Accesseur : Récupère le joueur2 de la partie en cours.
    */
    const Joueur  & getJoueur2() const;

    /**
    @brief Accesseur : Récupère le joueur2 de la partie en cours.
    */
    Joueur  & getJoueur2();

    /**
    @brief Accesseur : Récupère le score de la partie.
    */
    const Score * getScore() const;

    /**
    @brief Accesseur : Récupère le score de la partie.
    */
    Score * getScore();


    /**
    @brief Mutateur : Modifie le plateau de jeu.
    @param nvPlateau Le nouveau plateau de jeu.
    */
    void setPlateau(Plateau & nvPlateau);

    /**
    @brief Mutateur : Modifie le Joueur1.
    @param nvJoueur1 Le nouveau Joueur1.
    */
    void setJoueur1(Joueur & nvJoueur1);

    /**
    @brief Mutateur : Modifie le Joueur2.
    @param nvJoueur2 Le nouveau Joueur2.
    */
    void setJoueur2(Joueur & nvJoueur2);

    /**
    @brief Mutateur : Modifie le nombre de case possédé par le joueur.
    @param nvScore Le nouveau nombre de case possédé par joueur.
    */
    void setScore(Score * nvScore);

    /**
    @brief Défini les options du jeu.
    */
    void menuJeu(int choix);

    /**
    @brief Défini la couleur des joueurs 1 et 2.
    */
    void donneCouleur();

    /**
    @brief Donne un pseudo à un joueur.
    @param j Le joueur qui portera le pseudo.
    @param pseudo Le pseudo du joueur.
    */
    void pseudoJoueur(Joueur j, std::string pseudo);

    /**
    @brief Permet au jeu de poser un jeton d'un joueur sur le plateau.
    @param j Joueur qui pose un jeton.
    @param x coordonnée X du jeton.
    @param y coordonnée Y du jeton.
    @param nomJeton nom du jeton posé.
    */
    void poseJeton(Joueur & j,unsigned int x, unsigned int y, std::string nomJeton);

    /**
    @brief Initialise le jeu avec deux joueurs et leurs couleurs + initialisation du plateau.
    */
    void initJeu();

    /**
    @brief Permet de fermer le jeu.
    */
    void quitJeu();
    
    /**
    @brief Permet de rejouer une partie.
    */
    void rejouerPartie();

};
#endif /* Termine le #ifndef JEU_H */