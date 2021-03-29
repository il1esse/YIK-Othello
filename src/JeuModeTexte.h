/**
 @brief JeuModeTexte contient les données & les entêtes des fonctions JeuModeTexte.
 @author YIK
 @version 1.0
 @date 2021/03/17
*/

/* Directives pour éviter les inclusions multiples */
#ifndef JEUMODETEXTE_H
#define JEUMODETEXTE_H

/* Inclusions des entêtes utilisées */
#include "Jeu.h"

/* Définitions de la classes */
class JeuModeTexte {
    /* Données privés */
    private:
    Jeu jeu;

    /* Donnée et fonctions publique */
    public: 

    /**
    @brief Constructeur par défaut de la classe JeuModeTexte.
    */
    JeuModeTexte();

    /**
    @brief Constructeur de la classe JeuModeTexte.
    @param j Jeu.
    */
    JeuModeTexte(Jeu j);

    /**
    @brief Destructeur de la classe JeuModeTexte.
    */
    ~JeuModeTexte();

    /**
    @brief Accesseur : Récupère le jeu.
    */
    const Jeu & getJeu() const;

    /**
    @brief Mutateur: Change le jeu.
    @param nvJeu Le Nouveau jeu.
    */
    void setJeu(Jeu nvJeu);

    /**
    @brief Défini les options du jeu.
    */
    void JeuModeTexte::menuJeu();

    /**
    @brief Défini les options de choix de départ.
    */
    void JeuModeTexte::menuChoix();

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
    void ordreJeu(Joueur joueur);

    /**
    @brief Permet de déterminer le tour des joueurs.
    */
    void joueurTour(Joueur j);

    /**
    @brief Permet au joueur de jouer son tour.
    */
    void actionJoueur(Joueur j);

    /**
    @brief Lance le mode Joueur vs Joueur.
    */
    void modeVsJoueur();

    /**
    @brief Lance le mode vs IA.
    */
    void modeVsIA();

};
#endif /* Termine le #ifndef JEUMODETEXTE_H */