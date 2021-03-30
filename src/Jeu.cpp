/* Inclusions des entêtes utilisées */
#include "Jeu.h"
#include <iostream>

    // Constructeur par défaut de la classe Jeu.
    Jeu::Jeu(){
        pla = Plateau();
        j1 = Joueur();
        j2 = Joueur();
        score = Score();
    }


    // Constructeur de la classe Jeu.
    Jeu::Jeu(Plateau p, Joueur joueur1, Joueur joueur2){
        pla = p;
        j1 = joueur1;
        j2 = joueur2;
        score = Score();
    }

    // Destructeur de la classe Jeu.
    Jeu::~Jeu(){
        pla = Plateau();
        j1 = Joueur();
        j2 = Joueur();
        score = Score();
    }


    // Accesseur : Récupère le plateau de jeu.
    const Plateau & Jeu::getPlateau() const{
        return pla;
    }

    // Accesseur : Récupère le joueur1 de la partie en cours.
    const Joueur & Jeu::getJoueur1() const{
        return j1;
    }

    // Accesseur : Récupère le joueur2 de la partie en cours.
    const Joueur & Jeu::getJoueur2() const{
        return j2;
    }

    // Accesseur : Récupère le score de la partie.
    const Score & Jeu::getScore() const{
        return score;
    }


    // Mutateur : Modifie le plateau de jeu.
    void Jeu::setPlateau(Plateau & nvPlateau){
        pla = nvPlateau;
    }

    // Mutateur : Modifie le Joueur1.
    void Jeu::setJoueur1(Joueur & nvJoueur1){
        j1 = nvJoueur1;
    }


    // Mutateur : Modifie le Joueur2.
    void Jeu::setJoueur2(Joueur & nvJoueur2){
        j2 = nvJoueur2;
    }


    // Mutateur : Modifie le nombre de case possédé par le joueur.
    void Jeu::setScore(Score & nvScore){
        score = nvScore;
    }

    // Donne la couleur du joueur1 et du joueur2
    void Jeu::donneCouleur(){
        std::string couleur_j1 = "Bleu";
        std::string couleur_j2 = "Rouge";
        j1.setCouleur(couleur_j1);
        j2.setCouleur(couleur_j2);
    }

    // Donne un pseudo à un joueur.
    void Jeu::pseudoJoueur(Joueur j, std::string pseudo){
        j.setPseudo(pseudo);
    }

    // Initialise le jeu avec deux joueurs et leurs couleurs + initialisation du plateau.
    void Jeu::initJeu(){
        donneCouleur();
        pla.dessinePlateau();
    }

    // Permet de fermer le jeu.
    void Jeu::quitJeu(){
        exit(0);
    }
    
    // Permet de rejouer une partie.
    void Jeu::rejouerPartie(){
        j1 = Joueur();
        j2 = Joueur();
        pla = Plateau();
        score = Score();
        initJeu();
    }
