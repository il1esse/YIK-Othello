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
    Score score;

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
    char & getPlateau() const;

    /**
    @brief Accesseur : Récupère le joueur1 de la partie en cours.
    */
    char & getJoueur1() const;

    /**
    @brief Accesseur : Récupère le joueur2 de la partie en cours.
    */
    char & getJoueur2() const;

    /**
    @brief Accesseur : Récupère le score de la partie.
    */
    unsigned int & getScore() const;


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
    void setScore(Score & nvScore);

    /**
    @brief Défini les options du jeu.
    */
    void menuJeu(int choix);

    /**
    @brief Met à jour la partie de jeu avec les dernières informations.
    */
    void majJeu();

    /**
    @brief Met fin à la partie.
    */
    void finDePartie();

    /**
    @brief Définie aléatoirement l'ordre dans lequelle les joueurs vont jouer.
    */
    void ordreJeu();

    /**
    @brief Définie l'ordre dans lequelle les joueurs vont jouer.
    @param j Le joueur à jouer en premier.
    */
    void ordreJeu(Joueur j);

    /**
    @brief Permet de déterminer le tour des joueurs.
    */
    void joueurTour(Joueur j);

    /**
    @brief Permet au joueur de jouer son tour.
    */
    void actionJoueur(Joueur j);

    /**
    @brief Permet de fermer le jeu.
    */
    void quitJeu();

    /**
    @brief Permet de rejouer une partie.
    */
    void rejouerPartie();

    /**
    @brief Lance le mode Joueur vs Joueur.
    */
    void modeVsJoueur();

    /**
    @brief Lance le mode vs IA.
    */
    void modeVsIA();

};
#endif /* Termine le #ifndef JEU_H */