/**
 @brief JeuModeGraphique contient les données & les entêtes des fonctions JeuModeGraphique.
 @author YIK
 @version 1.0
 @date 2021/03/17
*/

/* Directives pour éviter les inclusions multiples */
#ifndef JEUMODEGRAPHIQUE_H
#define JEUMODEGRAPHIQUE_H

/* Inclusions des entêtes utilisées */

#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


/* Inclusions des entêtes utilisées */
#include "Jeu.h"

/* Définitions de la classes */
class JeuModeGraphique {
    /* Données privés */
    private:
    Jeu jeu;
    SDL_Window* pWindow = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *texte = NULL; //*fond = NULL;
    SDL_Rect position;
    SDL_Event events;

    /* Donnée et fonctions publique */
    public: 

    /**
    @brief Constructeur par défaut de la classe JeuModeGraphique.
    */
    JeuModeGraphique();

    /**
    @brief Constructeur de la classe JeuModeGraphique.
    @param j Jeu.
    */
    JeuModeGraphique(Jeu j);

    /**
    @brief Destructeur de la classe JeuModeGraphique.
    */
    ~JeuModeGraphique();

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
    void menuJeu();

    /**
    @brief Défini les options de choix de départ.
    */
    void joueurChoix(int x);

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
    void ordreJeu(Joueur & joueur);

    /**
    @brief Permet de déterminer le tour des joueurs.
    */
    void joueurTour(Joueur & j);

    /**
    @brief Permet au joueur de jouer son tour.
    */
    void actionJoueur(Joueur & j);

    /**
    @brief Lance le mode Joueur vs Joueur.
    */
    void modeVsJoueur();

    /**
    @brief Lance le mode vs IA.
    */
    void modeVsIA();

    /**
    @brief Dessine le plateau 
    */
    void dessinePLATEAUGRAPHIQUE();

    /**
   @brief Initialise la fenetre.
   @return Aucun
   */
    void AfficherInit();

    /**
   @brief Ferme la fenetre.
   @return Aucun
   */
    void AfficherDetruit();

    /**
   @brief Met à jour fenetre (Evenement/Draw...).
   @return Aucun
   */
    void AfficherBoucle();

    /**
   @brief Affiche le plateau de jeu dans une fenêtre
   @return Aucun
   */
    void Afficher();
};
#endif /* Termine le #ifndef JeuModeGraphique_H */